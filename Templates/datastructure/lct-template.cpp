#include <bits/stdc++.h>
#include <cstddef>
#include <memory_resource>
using namespace std;
#define ll long long
const ll MAXN = 100010;
struct XorFunctor {
  long long operator()(long long lhs, long long rhs) { return lhs ^ rhs; }
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
  void modify(Node *u, ValueType v) {
    splay(u);
    u->val = v;
    pushup(u);
  }
  NodeAlloc alloc_;
  map<int, Node *> vertices_;

public:
  LCT() : alloc_(){};
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
  }
  void makeroot(IdType u) { makeroot(vertices_[u]); }
  void link(IdType u, IdType v) { link(vertices_[u], vertices_[v]); }
  void cut(IdType u, IdType v) { cut(vertices_[u], vertices_[v]); }
  void modify(IdType u, IdType v) { modify(vertices_[u], v); }
  void split(IdType u, IdType v) { split(vertices_[u], vertices_[v]); }
  ValueType query(IdType u, IdType v) {
    split(u, v);
    return vertices_[v]->sum;
  }
};
ll n, m;
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
  array<char, MAXN * 64> buf;
  size_t cur;
};
LCT<ll, XorFunctor, Alloc<ll>> lct;
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