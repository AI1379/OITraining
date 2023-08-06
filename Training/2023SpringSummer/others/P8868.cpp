#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pll pair<ll, ll>
const ull MAXN = 250010;
struct Node {
  int l, r;
  ull val;
};
ll t, n, q;
ull a[MAXN], b[MAXN];
pll query[MAXN];
Node segta[MAXN * 4], segtb[MAXN * 4];
void build(Node *segt, ull *val, ll cur, ll l, ll r) {
  segt[cur].l = l;
  segt[cur].r = r;
  if (l == r) {
    segt[cur].val = val[l];
    return;
  }
  auto mid = (l + r) / 2;
  build(segt, val, cur * 2, l, mid);
  build(segt, val, cur * 2 + 1, mid + 1, r);
}
int main() {
  cin >> t >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    cin >> b[i];
  build(segta, a, 1, 1, n);
  build(segtb, b, 1, 1, n);
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> query[i].first >> query[i].second;
  }
  return 0;
}