#include <iostream>
#include <set>
#include <vector>

using namespace std;
#define ll long long
template <typename T> class ODT {
public:
  struct Node {
    std::size_t l, r;
    mutable T value;
    bool operator<(const Node &rhs) const { return l < rhs.l; }
    Node(std::size_t _l, std::size_t _r, const T &_value)
        : l(_l), r(_r), value(_value) {}
  };
  using ValueType = T;
  ODT(std::size_t n) : kMaxN(n) {}
  ODT(const std::vector<ValueType> &init_list) : kMaxN(init_list.size()) {
    std::size_t l;
    l = 1;
    for (std::size_t idx = 0; idx < init_list.size(); ++idx) {
      if (init_list[idx] != init_list[l - 1]) {
        container_.insert(Node(l, idx, ValueType(init_list[l - 1])));
        l = idx + 1;
      }
    }
    container_.insert(Node(l, init_list.size(), ValueType(init_list[l - 1])));
  }

private:
  std::set<Node> container_;
  auto merge(typename decltype(container_)::iterator iter_l,
             typename decltype(container_)::iterator iter_r,
             const ValueType &val) {
    std::size_t l = iter_l->l, r = iter_r->r;
    container_.erase(iter_l, ++iter_r);
    return container_.insert(Node(l, r, val)).first;
  }

public:
  auto split(std::size_t p) {
    if (p > kMaxN)
      return container_.end();
    auto it = --container_.upper_bound(Node(p, 0, ValueType(0)));
    if (it->l == p)
      return it;
    std::size_t l = it->l, r = it->r;
    ValueType &&v = std::move(it->value);
    container_.erase(it);
    container_.insert(Node(l, p - 1, v));
    return container_.insert(Node(p, r, v)).first;
  }
  void assign(std::size_t l, std::size_t r, const ValueType &val) {
    auto iter_r = split(r + 1), iter_l = split(l);
    auto iter = merge(iter_l, --iter_r, val);
    // container_.erase(iter_l, iter_r);
    // auto iter = container_.insert(Node(l, r, val)).first;
    if (iter != container_.begin()) {
      iter_l = --iter;
      ++iter;
    }
    if (++iter != container_.end())
      iter_r = iter;
    --iter;
    if (iter_l != iter && iter_l->value != iter->value)
      ++iter_l;
    if (iter_r != iter && iter_r->value != iter->value)
      --iter_r;
    merge(iter_l, iter_r, val);
  }
  template <typename Operator>
  void modify(std::size_t l, std::size_t r, Operator op) {
    auto iter_r = split(r + 1), iter_l = split(l);
    for (; iter_l != iter_r; ++iter_l) {
      iter_l->value = op(iter_l->value);
      cerr << iter_l->l << ' ' << iter_l->r << ' ' << iter_l->value << endl;
    }
  }

  template <typename ResultType, typename Operator>
  ResultType query(std::size_t l, std::size_t r, ResultType res, Operator op) {
    auto iter_r = split(r + 1), iter_l = split(l);
    for (; iter_l != iter_r; ++iter_l) {
      res = op(res, *iter_l);
      cerr << iter_l->l << ' ' << iter_l->r << ' ' << iter_l->value << ' '
           << res << endl;
    }
    return res;
  }

  const std::size_t kMaxN;
};
ll n, m;
vector<ll> a;
int main() {
  ll opt, l, r, res;
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ODT<ll> odt(a);
  while (m--) {
    cin >> opt >> l >> r;
    ++l;
    ++r;
    switch (opt) {
    case 0: {
      odt.assign(l, r, 0);
      break;
    }
    case 1: {
      odt.assign(l, r, 1);
      break;
    }
    case 2: {
      odt.modify(l, r, [](ll x) { return x ^ 1; });
      break;
    }
    case 3: {
      res = odt.query(l, r, 0, [](size_t p, const decltype(odt)::Node &node) {
        if (node.value == 1)
          return p + node.r - node.l + 1;
        return p;
      });
      cout << res << endl;
      break;
    }
    case 4: {
      res = odt.query(l, r, 0, [](size_t p, const decltype(odt)::Node &node) {
        if (node.value == 1)
          return max(p, node.r - node.l + 1);
        return p;
      });
      cout << res << endl;
      break;
    }
    }
  }
  return 0;
}