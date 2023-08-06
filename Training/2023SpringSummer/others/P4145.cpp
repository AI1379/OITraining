#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
struct Node {
  ll l, r, s, m;
};
ll n, q;
ll val[MAXN];
Node segt[MAXN * 4];
void build(ll cur, ll l, ll r) {
  segt[cur].l = l;
  segt[cur].r = r;
  if (l == r) {
    segt[cur].s = segt[cur].m = val[l];
    return;
  }
  ll mid = (l + r) / 2;
  build(cur * 2, l, mid);
  build(cur * 2 + 1, mid + 1, r);
  segt[cur].s = segt[cur * 2].s + segt[cur * 2 + 1].s;
  segt[cur].m = max(segt[cur * 2].m, segt[cur * 2 + 1].m);
}
ll querysum(ll cur, ll l, ll r) {
  if (l <= segt[cur].l && segt[cur].r <= r)
    return segt[cur].s;
  ll res = 0;
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (l <= mid)
    res += querysum(cur * 2, l, r);
  if (mid + 1 <= r)
    res += querysum(cur * 2 + 1, l, r);
  return res;
}
ll querymax(ll cur, ll l, ll r) {
  if (l <= segt[cur].l && segt[cur].r <= r)
    return segt[cur].m;
  ll res = 0;
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (l <= mid)
    res = max(res, querymax(cur * 2, l, r));
  if (mid + 1 <= r)
    res = max(res, querymax(cur * 2 + 1, l, r));
  return res;
}
void modify(ll cur, ll l, ll r) {
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (segt[cur].l == segt[cur].r) {
    segt[cur].m = segt[cur].s = int(sqrt(segt[cur].s));
    return;
  }
  if (l <= mid)
    modify(cur * 2, l, r);
  if (mid + 1 <= r)
    modify(cur * 2 + 1, l, r);
  segt[cur].s = segt[cur * 2].s + segt[cur * 2 + 1].s;
  segt[cur].m = max(segt[cur * 2].m, segt[cur * 2 + 1].m);
}

int main() {
  ll u, v, opt;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  build(1, 1, n);
  cin >> q;
  while (q--) {
    cin >> opt >> u >> v;
    if (u > v)
      swap(u, v);
    if (opt) {
      cout << querysum(1, u, v) << endl;
    } else {
      if (querymax(1, u, v) != 1)
        modify(1, u, v);
    }
  }
  return 0;
}
/**
10
1 2 3 4 5 6 7 8 9 10
5
0 1 10
1 1 10
1 1 5
0 5 8
1 4 8

19
7
6
**/