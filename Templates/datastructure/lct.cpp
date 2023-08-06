#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
class LCT {
public:
  struct Node {
    ll val, sum, tag, id;
    Node *sptr[2], *pptr;
  };

private:
  static Node *getnull() {
    static Node kNull;
    kNull = Node{0, 0, 0, 0, {nullptr, nullptr}, nullptr};
    return &kNull;
  }
  bool get(Node *ptr) { return ptr == ptr->pptr->sptr[1]; }
  bool isRoot(Node *ptr) {
    return ptr->pptr->sptr[0] != ptr && ptr->pptr->sptr[1] != ptr;
  }
  void pushup(Node *ptr) {
    ptr->sum = (ptr->sptr[0]->sum) ^ (ptr->sptr[1]->sum) ^ (ptr->val);
  }
  void pushdown(Node *ptr) {
    if (ptr->tag) {
      swap(ptr->sptr[0]->sptr[0], ptr->sptr[0]->sptr[1]);
      ptr->sptr[0]->tag ^= 1;
      swap(ptr->sptr[1]->sptr[0], ptr->sptr[1]->sptr[1]);
      ptr->sptr[1]->tag ^= 1;
      ptr->tag = 0;
    }
  }
  void update(Node *u) {
    if (!isRoot(u))
      update(u->pptr);
    pushdown(u);
  }
  void rotate(Node *x) {
    auto y = x->pptr, z = y->pptr;
    auto k = get(x);

    if (!isRoot(y)) {
      z->sptr[get(y)] = x;
      pushup(z);
    }

    y->sptr[k] = x->sptr[!k];
    x->sptr[!k]->pptr = y;
    x->sptr[!k] = y;
    y->pptr = x;
    x->pptr = z;
    pushup(y);
    pushup(x);
  }
  void splay(Node *ptr) {
    update(ptr);

    for (Node *p = ptr->pptr; !isRoot(ptr); p = ptr->pptr) {
      if (!isRoot(p))
        rotate(get(p) == get(ptr) ? p : ptr);
      rotate(ptr);
    }

    pushup(ptr);
  }
  Node *allocnode(ll val, ll id) {
    return new Node{val, val, 0, id, {getnull(), getnull()}, getnull()};
  }

public:
  void print(ostream &os) {
    cout << "id val pptr lptr rptr sum tag " << endl;

    for (auto [id, ptr] : vertices) {
      os << id << ' ' << ptr->val << ' ' << (ptr->pptr->id) << ' '
         << (ptr->sptr[0]->id) << ' ' << (ptr->sptr[1]->id) << ' ' << (ptr->sum)
         << ' ' << (ptr->tag) << endl;
    }
  }
  Node *access(Node *ptr) {
    Node *p = getnull();

    for (; ptr != getnull(); p = ptr, ptr = ptr->pptr) {
      splay(ptr);
      ptr->sptr[1] = p;
      pushup(ptr);
    }

    return p;
  }
  void makeroot(Node *ptr) {
    access(ptr);
    splay(ptr);
    swap(ptr->sptr[0], ptr->sptr[1]);
    ptr->tag ^= 1;
  }
  Node *findroot(Node *ptr) {
    access(ptr);
    splay(ptr);

    while (ptr->sptr[0] != getnull()) {
      pushdown(ptr);
      ptr = ptr->sptr[0];
    }

    splay(ptr);
    return ptr;
  }
  void link(Node *u, Node *v) {
    makeroot(u);

    if (findroot(v) == u)
      return;

    u->pptr = v;
  }
  void split(Node *u, Node *v) {
    makeroot(u);
    access(v);
    splay(v);
  }
  void cut(Node *u, Node *v) {
    makeroot(u);

    if (findroot(v) != u || v->pptr != u || v->sptr[0] != getnull())
      return;

    v->pptr = u->sptr[1] = getnull();
    pushup(u);
  }
  void modify(Node *u, ll v) {
    splay(u);
    u->val = v;
    pushup(u);
  }
  void addnode(ll id, ll val) { vertices[id] = allocnode(val, id); }
  void makeroot(ll u) { makeroot(vertices[u]); }
  void link(ll u, ll v) { link(vertices[u], vertices[v]); }
  void cut(ll u, ll v) { cut(vertices[u], vertices[v]); }
  void modify(ll u, ll v) { modify(vertices[u], v); }
  void split(ll u, ll v) { split(vertices[u], vertices[v]); }
  ll query(ll u, ll v) {
    split(u, v);
    return vertices[v]->sum;
  }
  map<ll, Node *> vertices;
};
ll n, m;
LCT lct;
#define pushcase(x, y)                                                         \
  case x: {                                                                    \
    y;                                                                         \
    break;                                                                     \
  }
int main() {
  ll u, v, w;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    cin >> u;
    lct.addnode(i, u);
  }

  while (m--) {
    cin >> u >> v >> w;

    switch (u) {
      pushcase(0, cout << lct.query(v, w) << endl);
      pushcase(1, lct.link(v, w));
      pushcase(2, lct.cut(v, w));
      pushcase(3, lct.modify(v, w););
    }
  }

  return 0;
}