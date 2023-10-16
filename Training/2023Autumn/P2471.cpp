#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 50010;
struct Node {
  ll l, r, mx, mn, val;
};
ll n, m;
Node segt[MAXN * 2 * 4];
map<ll, ll> table;
pll lst[MAXN];
void pushup(ll p) {
  segt[p].mx = max(segt[p * 2].mx, segt[p * 2 + 1].mx);
  segt[p].mn = min(segt[p * 2].mn, segt[p * 2 + 1].mn);
}
void build(ll p, ll l, ll r) {
  segt[p].l = l;
  segt[p].r = r;
  if (l == r)
    return;
  ll mid = (l + r) / 2;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
}
void modify(ll p, ll pos, ll x) {
  if (segt[p].l == pos && segt[p].r == pos) {
    segt[p].val = segt[p].mx = segt[p].mn = x;
    return;
  }
  ll mid = (segt[p].l + segt[p].r) / 2;
  if (pos <= mid)
    modify(p * 2, pos, x);
  else
    modify(p * 2 + 1, pos, x);
  pushup(p);
}
ll querymx(ll p, ll l, ll r) {
  if (l <= segt[p].l && segt[p].r <= r) {
    return segt[p].mx;
  }
  ll mid = (segt[p].l + segt[p].r) / 2;
  ll res = 0;
  if (l <= mid)
    res = max(res, querymx(p * 2, l, r));
  if (mid + 1 <= r)
    res = max(res, querymx(p * 2 + 1, l, r));
  return res;
}
ll querymn(ll p, ll l, ll r) {
  if (l <= segt[p].l && segt[p].r <= r) {
    return segt[p].mn;
  }
  ll mid = (segt[p].l + segt[p].r) / 2;
  ll res = 0;
  if (l <= mid)
    res = min(res, querymn(p * 2, l, r));
  if (mid + 1 <= r)
    res = min(res, querymn(p * 2 + 1, l, r));
  return res;
}
int main() {
  ll u, v;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> lst[i].first >> lst[i].second;
  }
  build(1, 1, 2 * n);
  for (int i = 1; i <= n; ++i) {
    table[lst[i].first] = i * 2 - 1;
    modify(1, i * 2 - 1, lst[i].second);
    if (lst[i].first == lst[i + 1].first - 1) {
      modify(1, i * 2, 0);
    } else {
      modify(1, i * 2, -1);
    }
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    if (querymx(1, table[u], table[u]) < querymx(1, table[v], table[v])) {
      cout << "false" << endl;
    } else if (table[u] == table[v] - 1) {
      cout << "true" << endl;
    } else if (querymx(1, table[u] + 1, table[v] - 1) >=
               querymx(1, table[v], table[v])) {
      cout << "false" << endl;
    } else if (querymn(1, table[u] + 1, table[v] - 1) == -1) {
      cout << "maybe" << endl;
    } else {
      cout << "true" << endl;
    }
  }
  return 0;
}

/**

6
2002 4920
2003 5901
2004 2832
2005 3890
2007 5609
2008 3024
5
2002 2005
2003 2005
2002 2007
2003 2007
2005 2008

false
true
false
maybe
false

**/