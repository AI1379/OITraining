#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
class SegmentTree {
  struct node {
    ll val;
    ll tag;
  };
  node segt[4 * MAXN];
  ll size;
  void pushdown(ll l, ll r, ll mid, ll cnt) {
    if (segt[cnt].tag) {
      segt[cnt * 2].val += (mid - l + 1) * segt[cnt].tag;
      segt[cnt * 2 + 1].val += (r - mid) * segt[cnt].tag;
      segt[cnt * 2].tag += segt[cnt].tag;
      segt[cnt * 2 + 1].tag += segt[cnt].tag;
      segt[cnt].tag = 0;
    }
  }
  void buildImpl(const array<ll, MAXN> &orig, ll beg, ll end, ll cnt) {
    if (beg == end) {
      segt[cnt].val = orig[beg];
      return;
    }
    ll mid = (beg + end) / 2;
    buildImpl(orig, beg, mid, cnt * 2);
    buildImpl(orig, mid + 1, end, cnt * 2 + 1);
    segt[cnt].val = segt[cnt * 2].val + segt[cnt * 2 + 1].val;
  }
  void modifyImpl(ll l, ll r, ll k, ll beg, ll end, ll cnt) {
    if (l <= beg && end <= r) {
      segt[cnt].val += (end - beg + 1) * k;
      segt[cnt].tag += k;
      return;
    }
    ll mid = (beg + end) / 2;
    if (beg != end)
      pushdown(beg, end, mid, cnt);
    if (l <= mid)
      modifyImpl(l, r, k, beg, mid, cnt * 2);
    if (mid + 1 <= r)
      modifyImpl(l, r, k, mid + 1, end, cnt * 2 + 1);
    segt[cnt].val = segt[cnt * 2].val + segt[cnt * 2 + 1].val;
    return;
  }
  ll queryImpl(ll l, ll r, ll beg, ll end, ll cnt) {
    if (l <= beg && end <= r) {
      return segt[cnt].val;
    }
    ll res = 0, mid = (beg + end) / 2;
    pushdown(beg, end, mid, cnt);
    if (l <= mid)
      res += queryImpl(l, r, beg, mid, cnt * 2);
    if (mid + 1 <= r)
      res += queryImpl(l, r, mid + 1, end, cnt * 2 + 1);
    return res;
  }

public:
  void build(ll x, const array<ll, MAXN> &orig) {
    size = x;
    buildImpl(orig, 1, size, 1);
  }
  void modify(ll l, ll r, ll k) { modifyImpl(l, r, k, 1, size, 1); }
  ll query(ll l, ll r) { return queryImpl(l, r, 1, size, 1); }
};
ll n, m;
array<ll, MAXN> a;
SegmentTree segt;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  segt.build(n, a);
  ll t, x, y, k;
  while (m--) {
    cin >> t;
    if (t == 1) {
      cin >> x >> y >> k;
      segt.modify(x, y, k);
    } else {
      cin >> x >> y;
      cout << segt.query(x, y) << endl;
    }
  }
  return 0;
}