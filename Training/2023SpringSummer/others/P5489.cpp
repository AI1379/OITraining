#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, q;
struct Sum {
  ll operator()(ll x, ll y) { return x + y; }
};
template <typename T, typename F, typename Allo_ = std::allocator<T>>
class LCT {
public:
  typedef Allo_ Alloc;
  typedef F Func;
  typedef T ValueType;
  typedef int IdType;

private:
  struct Node {
    ValueType val, sum;
    int tag;
    IdType id;
    Node *sptr[2], *pptr;
  };

  typedef typename std::allocator_traits<Alloc>::template rebind_alloc<Node>
      NodeAlloc;

  static Node *getnull() {
    static Node kNull;
    kNull = Node{ValueType(), ValueType(), 0, 0, {nullptr, nullptr}, nullptr};
    return &kNull;
  }
  bool get(Node *ptr) { return ptr == ptr->pptr->sptr[1]; }
  bool isRoot(Node *ptr) {
    return ptr->pptr->sptr[0] != ptr && ptr->pptr->sptr[1] != ptr;
  }
  void pushup(Node *ptr) {
    ptr->sum = Func{}(ptr->val, Func{}(ptr->sptr[0]->sum, ptr->sptr[1]->sum));
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
  Node *allocnode(ValueType val, IdType id) {
    auto buf = alloc_.allocate(1);
    return new (buf) Node{val, val, 0, id, {getnull(), getnull()}, getnull()};
  }
  Node *access(Node *ptr) {
    Node *p = getnull();
    for (; ptr != getnull(); p = ptr, ptr = ptr->pptr) {
      splay(ptr);
      ptr->sptr[1] = p;
      pushup(ptr);
      ptr->pptr = disjfind(ptr->pptr);
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
    u = disjfind(u);
    v = disjfind(v);
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
  void modify(Node *u, ValueType v) {
    splay(u);
    u->val = v;
    pushup(u);
  }
  Node *disjfind(Node *u) {
    return disj_[u] == u ? u : disj_[u] = disjfind(disj_[u]);
  }
  ValueType query(Node *u, Node *v) {
    u = disjfind(u);
    v = disjfind(v);
    makeroot(u);
    if (findroot(v) != u)
      return -1;
    access(v);
    splay(v);
    return v->sum;
  }
  NodeAlloc alloc_;
  unordered_map<int, Node *> vertices_;
  unordered_map<Node *, Node *> disj_;

public:
  LCT() : alloc_() { disj_[getnull()] = getnull(); };
  virtual ~LCT() {
    for (auto p : vertices_) {
      alloc_.deallocate(p.second, 1);
    }
  }
  void print(ostream &os) {
    cout << "id val pptr lptr rptr sum tag " << endl;
    for (auto [id, ptr] : vertices_) {
      os << id << ' ' << ptr->val << ' ' << (ptr->pptr->id) << ' '
         << (ptr->sptr[0]->id) << ' ' << (ptr->sptr[1]->id) << ' ' << (ptr->sum)
         << ' ' << (ptr->tag) << endl;
    }
  }
  void addnode(IdType id, const ValueType &val) {
    vertices_[id] = allocnode(val, id);
    disj_[vertices_[id]] = vertices_[id];
  }
  void makeroot(IdType u) { makeroot(vertices_[u]); }
  IdType findroot(IdType u) { return findroot(vertices_[u])->id; }
  void link(IdType u, IdType v) { link(vertices_[u], vertices_[v]); }
  void cut(IdType u, IdType v) { cut(vertices_[u], vertices_[v]); }
  void modify(IdType u, IdType v) { modify(vertices_[u], v); }
  void split(IdType u, IdType v) { split(vertices_[u], vertices_[v]); }
  ValueType query(IdType u, IdType v) {
    return query(vertices_[u], vertices_[v]);
  }
  friend void link(ll, ll);
};
template <typename T> struct Alloc {
  typedef T value_type;
  template <typename U> Alloc(const Alloc<U> &) noexcept {}
  Alloc() = default;
  T *allocate(size_t n) {
    auto res = reinterpret_cast<T *>(&buf[cur]);
    cur += n * sizeof(T);
    return res;
  }
  void deallocate(T *p, size_t n) {}

private:
  array<char, MAXN * 128> buf;
  size_t cur;
};
LCT<ll, Sum, Alloc<ll>> ebcc, vbcc;
typedef decltype(ebcc) LCTType;
void link(ll u, ll v) {
  typedef decltype(ebcc)::Node LCTNode;
  static ll tot = n;
  // ebcc
  LCTNode *fu, *fv;
  fu = ebcc.disjfind(ebcc.vertices_[u]);
  fv = ebcc.disjfind(ebcc.vertices_[v]);
  ebcc.makeroot(fu);
  if (ebcc.findroot(fv) == fu) {
    ebcc.split(fu, fv);
    std::function<void(LCTNode *, LCTNode *)> dfs1 = [&](LCTNode *u,
                                                         LCTNode *fa) {
      if (u == LCTType::getnull())
        return;
      ebcc.disj_[u] = fa;
      dfs1(u->sptr[0], fa);
      dfs1(u->sptr[1], fa);
      u->sptr[0] = u->sptr[1] = LCTType::getnull();
      ebcc.pushup(u);
    };
    dfs1(fv->sptr[0], fv);
    vbcc.split(u, v);
    std::function<void(LCTNode *, LCTNode *)> dfs2 = [&](LCTNode *u,
                                                         LCTNode *fa) {
      if (u == LCTType::getnull())
        return;
      u->pptr = fa;
      dfs2(u->sptr[0], fa);
      dfs2(u->sptr[1], fa);
      u->sptr[0] = u->sptr[1] = LCTType::getnull();
      vbcc.pushup(u);
    };
    ++tot;
    vbcc.addnode(tot, 0);
    dfs2(vbcc.vertices_[v], vbcc.vertices_[tot]);
  } else {
    ebcc.link(fu, fv);
    vbcc.link(u, v);
  }
}

int main() {
  ll opt, u, v;
  ll last = 0, ans = 0;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    ebcc.addnode(i, 1);
    vbcc.addnode(i, 1);
  }
  while (q--) {
    cin >> opt >> u >> v;
    u ^= last;
    v ^= last;
    switch (opt) {
    case 1: {
      link(u, v);
      break;
    }
    case 2: {
      ans = ebcc.query(u, v);
      if (ans != -1) {
        --ans;
        last = ans;
      }
      cout << ans << endl;
      break;
    }
    case 3: {
      ans = vbcc.query(u, v);
      last = (ans == -1 ? last : ans);
      cout << ans << endl;
      break;
    }
    }
  }
  return 0;
}
/**
5 10
1 1 2
1 2 3
2 1 3
3 0 1
1 3 1
1 1 6
2 3 7
1 6 7
1 7 1
3 3 6

5 10
1 1 2
1 2 3
2 1 3
3 2 3
1 1 3
1 3 4
2 1 5
1 4 5
1 5 3
3 1 4

2
2
-1
3

**/