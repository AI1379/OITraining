#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
struct Node {
  ll l, r, val, tag, sq;
};
ll n, m;
Node segt[MAXN * 4];
ll a[MAXN];
void pushup(ll p) {
  segt[p].val = segt[p * 2].val + segt[p * 2 + 1].val;
  segt[p].sq = segt[p * 2].sq + segt[p * 2 + 1].sq;
}
void pushdown(ll p) {
  if (segt[p].tag) {
    segt[p * 2].tag += p;
    segt[p * 2 + 1].tag += p;
    segt[p * 2].sq +=
        (2 * segt[p * 2].val * segt[p].tag +
         (segt[p * 2].r - segt[p * 2].l + 1) * segt[p].tag * segt[p].tag);
    segt[p * 2].val += segt[p].tag * (segt[p * 2].r - segt[p * 2].l + 1);
    segt[p * 2 + 1].sq += (2 * segt[p * 2 + 1].val * segt[p].tag +
                           (segt[p * 2 + 1].r - segt[p * 2 + 1].l + 1) *
                               segt[p].tag * segt[p].tag);
    segt[p * 2 + 1].val +=
        segt[p].tag * (segt[p * 2 + 1].r - segt[p * 2 + 1].l + 1);
    segt[p].tag = 0;
  }
}
void build(ll cur, ll l, ll r) {
  segt[cur].l = l;
  segt[cur].r = r;
  if (l == r) {
    segt[cur].val = a[l];
    segt[cur].sq = a[l] * a[l];
    return;
  }
  ll mid = (l + r) / 2;
  build(cur * 2, l, mid);
  build(cur * 2 + 1, mid + 1, r);
  pushup(cur);
}
void modify(ll cur, ll l, ll r, ll diff) {
  if (l <= segt[cur].l && segt[cur].r <= r) {
    segt[cur].tag += diff;
    segt[cur].sq += (2 * diff * segt[cur].val +
                     (segt[cur].r - segt[cur].l + 1) * diff * diff);
    segt[cur].val += diff * (segt[cur].r - segt[cur].l + 1);
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  pushdown(cur);
  if (l <= mid)
    modify(cur * 2, l, r, diff);
  if (mid + 1 <= r)
    modify(cur * 2 + 1, l, r, diff);
  pushup(cur);
}
ll query(ll cur, ll l, ll r) {
  if (l <= segt[cur].l && segt[cur].r <= r) {
    return segt[cur].sq;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  ll res = 0;
  pushdown(cur);
  if (l <= mid)
    res += query(cur * 2, l, r);
  if (mid + 1 <= r)
    res += query(cur * 2 + 1, l, r);
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n);
  char opt;
  ll u, v, w;
  while (m--) {
    cin >> opt >> u >> v;
    if (opt == 'A') {
      cin >> w;
      modify(1, u, v, w);
    } else {
      cout << query(1, u, v) << endl;
    }
  }
  return 0;
}