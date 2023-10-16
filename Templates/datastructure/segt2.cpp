#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
struct Node {
  ll l, r, sm, tagadd, tagmul, len;
};
ll n, q, m;
ll orig[MAXN];
Node segt[MAXN * 4];
void pushdown(ll p) {
  segt[p * 2].tagadd =
      (segt[p * 2].tagadd * segt[p].tagmul + segt[p].tagadd) % m;
  segt[p * 2].tagmul = segt[p * 2].tagmul * segt[p].tagmul % m;
  segt[p * 2].sm = (segt[p * 2].sm * segt[p].tagmul % m +
                    segt[p].tagadd * segt[p * 2].len % m) %
                   m;
  segt[p * 2 + 1].tagadd =
      (segt[p * 2 + 1].tagadd * segt[p].tagmul + segt[p].tagadd) % m;
  segt[p * 2 + 1].tagmul = segt[p * 2 + 1].tagmul * segt[p].tagmul % m;
  segt[p * 2 + 1].sm = (segt[p * 2 + 1].sm * segt[p].tagmul % m +
                        segt[p].tagadd * segt[p * 2 + 1].len % m) %
                       m;
  segt[p].tagadd = 0;
  segt[p].tagmul = 1;
}
void pushup(ll p) { segt[p].sm = (segt[p * 2].sm + segt[p * 2 + 1].sm) % m; }
void build(ll cur, ll l, ll r) {
  segt[cur].l = l;
  segt[cur].r = r;
  segt[cur].tagmul = 1;
  segt[cur].len = r - l + 1;
  if (l == r) {
    segt[cur].sm = orig[l];
    return;
  }
  ll mid = (l + r) / 2;
  build(cur * 2, l, mid);
  build(cur * 2 + 1, mid + 1, r);
  pushup(cur);
}
void add(ll cur, ll l, ll r, ll diff) {
  if (l <= segt[cur].l && segt[cur].r <= r) {
    segt[cur].tagadd = (segt[cur].tagadd + diff) % m;
    segt[cur].sm = (segt[cur].sm + diff * (segt[cur].r - segt[cur].l + 1)) % m;
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  pushdown(cur);
  if (l <= mid)
    add(cur * 2, l, r, diff);
  if (mid + 1 <= r)
    add(cur * 2 + 1, l, r, diff);
  pushup(cur);
}
void mul(ll cur, ll l, ll r, ll diff) {
  if (l <= segt[cur].l && segt[cur].r <= r) {
    segt[cur].tagmul = segt[cur].tagmul * diff % m;
    segt[cur].tagadd = segt[cur].tagadd * diff % m;
    segt[cur].sm = segt[cur].sm * diff % m;
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  pushdown(cur);
  if (l <= mid)
    mul(cur * 2, l, r, diff);
  if (mid + 1 <= r)
    mul(cur * 2 + 1, l, r, diff);
  pushup(cur);
}
ll query(ll cur, ll l, ll r) {
  if (l <= segt[cur].l && segt[cur].r <= r) {
    return segt[cur].sm;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  pushdown(cur);
  ll res = 0;
  if (l <= mid)
    res = (res + query(cur * 2, l, r)) % m;
  if (mid + 1 <= r)
    res = (res + query(cur * 2 + 1, l, r)) % m;
  return res;
}
int main() {
  ll opt, u, v, w;
  cin >> n >> q >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> orig[i];
  }
  build(1, 1, n);
  while (q--) {
    cin >> opt;
    if (opt == 1) {
      cin >> u >> v >> w;
      mul(1, u, v, w);
    } else if (opt == 2) {
      cin >> u >> v >> w;
      add(1, u, v, w);
    } else {
      cin >> u >> v;
      cout << query(1, u, v) << endl;
    }
  }
  return 0;
}