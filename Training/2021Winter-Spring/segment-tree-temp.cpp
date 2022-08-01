#include <array>
#include <iostream>
using namespace std;
#define ll long long
template <typename T, std::size_t size> class SegmentTree {
public:
  using SizeType = std::size_t;
  static constexpr SizeType ContainerSize = size * 4;
  using Container = std::array<T, ContainerSize>;
  using ValueType = T;
  template <typename U> void build(const U &seq) {
    this->build(seq, 1, size, 1);
  };
  ValueType query(SizeType l, SizeType r) { return this->query(1, size, l, r, 1); };
  void update(SizeType l, SizeType r, ValueType d) {
    this->update(1, size, l, r, d, 1);
  };

private:
  Container container_;
  Container tag_;
  template <typename U>
  void build(const U &seq, SizeType l, SizeType r, SizeType rt) {
    if (l == r) {
      container_[rt] = seq[l];
      return;
    }
    SizeType mid = (l + r) / 2;
    build(seq, l, mid, rt * 2);
    build(seq, mid + 1, r, rt * 2 + 1);
    container_[rt] = container_[rt * 2] + container_[rt * 2 + 1];
  }

  // 下传标记
  void pushdown(SizeType s, SizeType e, SizeType m, SizeType rt) {
    if (tag_[rt]) {
      container_[rt * 2] += tag_[rt] * (m - s + 1);
      container_[rt * 2 + 1] += tag_[rt] * (e - m);
      tag_[rt * 2] += tag_[rt];
      tag_[rt * 2 + 1] += tag_[rt];
      tag_[rt] = 0;
    }
  };
  ValueType query(SizeType l, SizeType r, SizeType s, SizeType e, SizeType rt) {
    if (s <= l && r <= e)
      return container_[rt];
    T res = 0;
    SizeType mid = (l + r) / 2;
    pushdown(l, r, mid, rt);
    if (s <= mid)
      res += query(l, mid, s, e, rt * 2);
    if (mid + 1 <= e)
      res += query(mid + 1, r, s, e, rt * 2 + 1);
    return res;
  }
  void update(SizeType l, SizeType r, SizeType s, SizeType e, const T &d,
              SizeType rt) {
    if (s <= l && r <= e) {
      container_[rt] += (r - l + 1) * d;
      tag_[rt] += d;
      return;
    }
    SizeType mid = (l + r) / 2;
    if (l != r)
      pushdown(l, r, mid, rt);
    if (s <= mid)
      update(l, mid, s, e, d, rt * 2);
    if (mid + 1 <= e)
      update(mid + 1, r, s, e, d, rt * 2 + 1);
    container_[rt] = container_[rt * 2] + container_[rt * 2 + 1];
    return;
  }
};
const ll MAXN = 100010;
ll n, m;
ll seq[MAXN];
SegmentTree<ll, MAXN> segt;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> seq[i];
  segt.build(seq);
  ll opt, x, y, k;
  while (m--) {
    cin >> opt;
    if (opt == 1) {
      cin >> x >> y >> k;
      segt.update(x, y, k);
    } else {
      cin >> x >> y;
      cout << segt.query(x, y) << endl;
    }
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}