#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 400010;
struct Node {
  ll l, r, maxv, sum;
};
ll n, m, q;
ll a[MAXN];
Node segt[MAXN * 4];
void pushup(ll p) {
  segt[p].maxv = max(segt[p * 2].maxv, segt[p * 2 + 1].maxv);
  segt[p].sum = segt[p * 2].sum + segt[p * 2 + 1].sum;
}
void build(ll p, ll l, ll r) {
  ll mid;
  mid = (l + r) / 2;
  segt[p].l = l;
  segt[p].r = r;
  if (l == r) {
    segt[p].maxv = segt[p].sum = a[l];
    return;
  }
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  pushup(p);
}
void modify(ll p, ll pos, ll x) {
  ll mid = (segt[p].l + segt[p].r) / 2;
  if (segt[p].l == segt[p].r) {
    segt[p].maxv = segt[p].sum = x;
    return;
  }
  if (pos <= mid)
    modify(p * 2, pos, x);
  if (mid < pos)
    modify(p * 2 + 1, pos, x);
  pushup(p);
}
ll query() { return max(segt[1].maxv, (segt[1].sum + m - 1) / m); }
int main() {
  ll u, v;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n);
  cout << query() << endl;
  while (q--) {
    cin >> u >> v;
    modify(1, u, v);
    cout << query() << endl;
  }
  return 0;
}