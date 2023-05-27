#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
#define ll long long
#define ld long double
const ll MAXN = 100010;
const ld EXP = 1e-16;
struct Node {
  ld val, vals, tag;
  ll l, r;
};
ll n, m;
Node segt[MAXN * 4];
ld orig[MAXN];
void pushup(ll p) {
  segt[p].val = segt[p * 2].val + segt[p * 2 + 1].val;
  segt[p].vals = segt[p * 2].vals + segt[p * 2 + 1].vals;
}
void pushdown(ll p) {
  if (fabs(segt[p].tag) > EXP) {
    segt[p * 2].vals +=
        (2 * segt[p].tag * segt[p * 2].val +
         segt[p].tag * segt[p].tag * (segt[p * 2].r - segt[p * 2].l + 1));
    segt[p * 2 + 1].vals += (2 * segt[p].tag * segt[p * 2 + 1].val +
                             segt[p].tag * segt[p].tag *
                                 (segt[p * 2 + 1].r - segt[p * 2 + 1].l + 1));
    segt[p * 2].val += (segt[p].tag * (segt[p * 2].r - segt[p * 2].l + 1));
    segt[p * 2 + 1].val +=
        (segt[p].tag * (segt[p * 2 + 1].r - segt[p * 2 + 1].l + 1));
    segt[p * 2].tag += segt[p].tag;
    segt[p * 2 + 1].tag += segt[p].tag;
    segt[p].tag = 0;
  }
}
void build(ll p, ll l, ll r) {
  segt[p].l = l;
  segt[p].r = r;
  segt[p].tag = 0;
  if (l == r) {
    segt[p].val = orig[l];
    segt[p].vals = orig[l] * orig[l];
    return;
  }
  ll mid = (l + r) >> 1;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  pushup(p);
}
ld querySum(ll p, ll l, ll r) {
  if (l <= segt[p].l && segt[p].r <= r) {
    return segt[p].val;
  }
  ll mid = (segt[p].r + segt[p].l) >> 1;
  ld res = 0;
  pushdown(p);
  if (l <= mid) res += querySum(p * 2, l, r);
  if (mid + 1 <= r) res += querySum(p * 2 + 1, l, r);
  return res;
}
ld querySq(ll p, ll l, ll r) {
  if (l <= segt[p].l && segt[p].r <= r) {
    return segt[p].vals;
  }
  ll mid = (segt[p].r + segt[p].l) >> 1;
  ld res = 0;
  pushdown(p);
  if (l <= mid) res += querySq(p * 2, l, r);
  if (mid + 1 <= r) res += querySq(p * 2 + 1, l, r);
  return res;
}
void print(ll p) {
  cout << p << ' ' << segt[p].l << ' ' << segt[p].r << ' ' << segt[p].val << ' '
       << segt[p].vals << endl;
  if (segt[p].l == segt[p].r) return;
  print(p * 2);
  print(p * 2 + 1);
}
void modify(ll p, ll l, ll r, ld diff) {
  ll mid = (segt[p].l + segt[p].r) >> 1;
  if (l <= segt[p].l && segt[p].r <= r) {
    segt[p].tag += diff;
    segt[p].vals +=
        (2 * diff * segt[p].val + diff * diff * (segt[p].r - segt[p].l + 1));
    segt[p].val += diff * (segt[p].r - segt[p].l + 1);
    return;
  }
  pushdown(p);
  if (l <= mid) modify(p * 2, l, r, diff);
  if (mid + 1 <= r) modify(p * 2 + 1, l, r, diff);
  pushup(p);
}
int main() {
  ll opt, x, y;
  ld k, b;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> orig[i];
  }
  build(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    cin >> opt >> x >> y;
    if (opt == 1) {
      cin >> k;
      modify(1, x, y, k);
    } else if (opt == 2) {
      k = (querySum(1, x, y) / ((ld)(y - x + 1)));
      cout << fixed << setprecision(4) << k << endl;
    } else if (opt == 3) {
      b = querySum(1, x, y) / ((ld)(y - x + 1));
      k = (querySq(1, x, y) - 2 * b * querySum(1, x, y)) / ((ld)(y - x + 1)) +
          b * b;
      cout << fixed << setprecision(4) << k << endl;
    }
  }
  return 0;
}