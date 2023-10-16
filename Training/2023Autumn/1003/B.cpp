#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 1000010;
struct Node {
  ll lson, rson;
  ll val, size, pri, dat;
};
ll n, m, q;
Node treap[MAXN];
ll root;
ll ans = 0;
void pushup(ll p) {
  treap[p].size = treap[treap[p].lson].size + treap[treap[p].rson].size + 1;
}
// (-inf, val] , (val, inf)
pll split(ll p, ll val) {
  pll tmp;
  if (p == 0)
    return {0, 0};
  if (treap[p].val <= val) {
    tmp = split(treap[p].rson, val);
    treap[p].rson = tmp.first;
    pushup(p);
    return {p, tmp.second};
  } else {
    tmp = split(treap[p].lson, val);
    treap[p].lson = tmp.second;
    pushup(p);
    return {tmp.first, p};
  }
}
ll merge(ll u, ll v) {
  if (u == 0 || v == 0)
    return u ^ v;
  if (treap[u].pri > treap[v].pri) {
    treap[u].rson = merge(treap[u].rson, v);
    pushup(u);
    return u;
  } else {
    treap[v].lson = merge(u, treap[v].lson);
    pushup(v);
    return v;
  }
}
ll ins(ll val, ll dat) {
  pll tmp = split(root, val);
  treap[val].dat = dat;
  ll l = tmp.first, r = tmp.second, res = 0;
  while (treap[l].rson)
    l = treap[l].rson;
  while (treap[r].lson)
    r = treap[r].lson;
  if (tmp.first == 0 && tmp.second == 0) {
    res = 0;
  } else if (tmp.first == 0) {
    res = (dat != treap[r].dat);
  } else if (tmp.second == 0) {
    res = (dat != treap[l].dat);
  } else if (treap[l].dat == treap[r].dat) {
    res = treap[l].dat == dat ? 0 : 2;
  } else {
    res = 0;
  }
  root = merge(merge(tmp.first, val), tmp.second);
  return res;
}
ll del(ll val) {
  pll tmpl = split(root, val - 1);
  pll tmp = split(tmpl.second, val);
  ll res = 0, l = tmpl.first, r = tmp.second;
  while (treap[l].rson)
    l = treap[l].rson;
  while (treap[r].lson)
    r = treap[r].lson;
  if (tmpl.first == 0 && tmp.second == 0) {
    res = 0;
  } else if (tmpl.first == 0) {
    res = (treap[val].dat != treap[r].dat);
  } else if (tmp.second == 0) {
    res = (treap[val].dat != treap[l].dat);
  } else if (treap[l].dat == treap[r].dat) {
    res = treap[l].dat == treap[val].dat ? 0 : 2;
  } else {
    res = 0;
  }
  root = merge(tmpl.first, tmp.second);
  return res;
}
int main() {
  ll u, v, w;
  mt19937 rng(time(nullptr));
  uniform_int_distribution<ll> dist;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> u;
    treap[i].val = i;
    treap[i].pri = dist(rng);
    treap[i].size = 1;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    ans += ins(u, v % 2);
    // cout << ans << endl;
  }
  for (int i = 1; i <= q; ++i) {
    cin >> w;
    if (w == 2) {
      cin >> u >> v;
      ans += ins(u, v % 2);
    } else {
      cin >> u;
      ans -= del(u);
    }
    cout << ans << endl;
  }
  return 0;
}
/**

10 8 10
15 4 12 10 14 5 18 7 9 11
5 12
6 18
1 4
10 5
7 7
2 15
9 14
4 10

2 8 11
1 7
1 6
2 7 18
2 6 9
1 8
2 8 7
1 9
1 4
1 5


5
5
5
7
7
7
7
5
5
5

**/