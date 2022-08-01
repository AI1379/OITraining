#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 500010;
template <typename T> struct IntTraits {
  static bool isInt() { return false; }
};
template <> struct IntTraits<ll> {
  static bool isInt() { return true; }
};
template <typename T, std::int64_t size> class BinaryIndexTree {
public:
  using SizeType = std::int64_t;
  using Container = std::array<T, size>;
  using ValueType = T;
  ValueType query(SizeType idx) {
    ValueType res;
    if (IntTraits<ValueType>::isInt())
      res = 0;
    for (; idx; idx -= lowbit(idx))
      res = res + container_[idx];
    return res;
  }
  void update(SizeType idx, const ValueType &upd) {
    for (; idx <= end_; idx += lowbit(idx))
      container_[idx] = container_[idx] + upd;
  }
  void setEnding(SizeType end) { this->end_ = end; }

private:
  SizeType lowbit(SizeType x) { return x & (-x); }
  Container container_;
  SizeType size_;
  SizeType end_;
};

ll n, m;
ll a[MAXN], b[MAXN];
BinaryIndexTree<ll, MAXN> bit;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
  }
  ll ans = 0;
  bit.setEnding(m);
  for (int i = n; i >= 1; i--) {
    ans += bit.query(a[i] - 1);
    bit.update(a[i], 1);
  }
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}