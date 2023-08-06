#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <random>
#include <utility>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define t3l tuple<ll, ll, ll>
const ll MAXN = 500010;
const ll MAXNLOGN = MAXN * 30;
class ETT {
public:
  ETT(ll n) : n_(n), vertices_(n) {
    for (int i = 0; i < n_; ++i) {
      vertices_[i] = allocNode(i, i, 1);
    }
  }
  ~ETT() {
    for (auto i : vertices_) {
      if (i != getNullPtr())
        delete i;
    }
    for (auto p : edges_) {
      if (p.second != getNullPtr())
        delete p.second;
    }
  }

private:
  static ll random() {
    static std::mt19937 rng_(time(NULL));
    return rng_();
  }
  ll n_;

  struct Node {
    ll size, pri;
    Node *lptr, *rptr, *pptr; // left child, right child, parent
    ll from, to;              // Euler tour
    ll value, sum;
  };
  static Node *allocNode(ll u, ll v, ll val) {
    return new Node{1, random(), getNullPtr(), getNullPtr(), getNullPtr(),
                    u, v,        val,          val};
  }
  static void freeNode(Node *&u) {
    if (u && u != getNullPtr()) {
      delete u;
      u = getNullPtr();
    }
  }

  // global single null node
  static Node *getNullPtr() {
    static Node kNullNode;
    kNullNode = Node{0, 0, nullptr, nullptr, nullptr, 0, 0, 0, 0};
    return &kNullNode;
  }
  static void pushup(Node *p) {
    p->size = p->lptr->size + p->rptr->size + 1;
    p->sum = p->lptr->sum + p->rptr->sum + p->value;
  }
  vector<Node *> vertices_;
  map<pair<ll, ll>, Node *> edges_;

  pair<Node *, Node *> split2(Node *u) {
    auto node = u;
    auto rptr = u->rptr, lptr = getNullPtr();

    if (rptr != getNullPtr())
      rptr->pptr = getNullPtr();
    node->rptr = getNullPtr();

    bool from_lchild = false, is_lchild = false;
    while (node != getNullPtr()) {
      auto p = node->pptr;
      if (p != getNullPtr()) {
        is_lchild = (p->lptr == node);
        if (is_lchild)
          p->lptr = getNullPtr();
        else
          p->rptr = getNullPtr();
        node->pptr = getNullPtr();
      }
      if (!from_lchild)
        lptr = merge(node, lptr);
      else
        rptr = merge(rptr, node);
      from_lchild = is_lchild;
      pushup(node);
      node = p;
    }
    return {lptr, rptr};
  }
  tuple<Node *, Node *, Node *> split3(Node *u) {
    auto node = u;
    auto rptr = u->rptr, lptr = u->lptr, self = u;

    if (lptr != getNullPtr())
      lptr->pptr = getNullPtr();
    node->lptr = getNullPtr();

    if (rptr != getNullPtr())
      rptr->pptr = getNullPtr();
    node->rptr = getNullPtr();

    bool from_lchild = false, is_lchild = false;
    auto p = u->pptr;
    if (p) {
      is_lchild = (p->lptr == p);
      if (is_lchild)
        p->lptr = getNullPtr();
      else
        p->rptr = getNullPtr();
    }
    from_lchild = is_lchild;
    pushup(node);
    node = p;

    while (node != getNullPtr()) {
      p = node->pptr;
      if (p != getNullPtr()) {
        is_lchild = (p->lptr == node);
        if (is_lchild)
          p->lptr = getNullPtr();
        else
          p->rptr = getNullPtr();
        node->pptr = getNullPtr();
      }
      if (!from_lchild)
        lptr = merge(node, lptr);
      else
        rptr = merge(rptr, node);
      from_lchild = is_lchild;
      pushup(node);
      node = p;
    }

    return {lptr, self, rptr};
  }

  Node *merge(Node *u, Node *v) {
    // u < v
    if (u == getNullPtr() && v == getNullPtr())
      return getNullPtr();
    else if (u == getNullPtr())
      return v;
    else if (v == getNullPtr())
      return u;
    if (u->pri >= v->pri) {
      u->rptr = merge(u->rptr, v);
      pushup(u);
      return u;
    } else {
      v->lptr = merge(u, v->lptr);
      pushup(v);
      return v;
    }
  }
  ll pos(Node *p) {
    auto res = p->lptr->size + 1;
    while (p) {
      if (p->pptr != getNullPtr() && (p == p->pptr->rptr))
        res += p->pptr->lptr->size + 1;
      p = p->pptr;
    }
    return res;
  }
  Node *findroot(Node *u) {
    while (u->pptr && u->pptr != getNullPtr())
      u = u->pptr;
    return u;
  }

public:
  void makeroot(ll u) {
    auto uptr = vertices_[u - 1];
    auto tmp = split2(uptr);
    auto l1 = tmp.first, l2 = tmp.second;
    this->merge(l2, l1);
  }
  void insert(ll u, ll v) {
    auto uptr = vertices_[u], vptr = vertices_[v];
    auto uv = allocNode(u, v, 0), vu = allocNode(v, u, 0);
    edges_[{u, v}] = uv;
    edges_[{v, u}] = vu;
    auto L1 = split2(uptr);
    auto L2 = split2(vptr);
    auto L = L1.second;
    L = merge(L, L1.first);
    L = merge(L, uv);
    L = merge(L, L2.second);
    L = merge(L, L2.first);
    L = merge(L, vu);
  }
  void remove(ll u, ll v) {
    auto uv = edges_[{u, v}], vu = edges_[{v, u}];
    edges_[{u, v}] = edges_[{v, u}] = getNullPtr();
    auto posuv = pos(uv), posvu = pos(vu);
    if (posuv > posvu)
      swap(uv, vu);
    auto L1 = split3(uv);
    auto L2 = split3(vu);
    merge(get<0>(L1), get<2>(L2));
    freeNode(uv);
    freeNode(vu);
  }
  bool connected(ll u, ll v) {
    return findroot(vertices_[u]) == findroot(vertices_[v]);
  }
  ll query(ll u) {
    auto uptr = vertices_[u];
    auto rt = findroot(uptr);
    return rt == getNullPtr() ? 0 : rt->sum;
  }
};
ll n, q;
int main() {
  cin >> n >> q;
  ETT ett(n);
  return 0;
}