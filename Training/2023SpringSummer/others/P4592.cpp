#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MAXNLOGN = MAXN * 30;
ll n, q;
ll val[MAXN];
ll roots[MAXN];
ll cnt[MAXNLOGN];
ll trie[MAXNLOGN][2], cur = 0;
vector<ll> tree[MAXN];
ll weight[MAXN], top[MAXN], fa[MAXN], prefer[MAXN], dfn[MAXN], bottom[MAXN],
    node[MAXN], dep[MAXN], idx = 0;
void getson(ll u) {
  weight[u] = 1;
  dep[u] = dep[fa[u]] + 1;
  for (auto v : tree[u]) {
    if (v == fa[u])
      continue;
    fa[v] = u;
    getson(v);
    weight[u] += weight[v];
    if (weight[v] > weight[prefer[u]])
      prefer[u] = v;
  }
}
void decomposition(ll u, ll t) {
  top[u] = t;
  bottom[u] = dfn[u] = ++idx;
  node[dfn[u]] = u;
  if (prefer[u])
    decomposition(prefer[u], t);
  bottom[u] = max(bottom[u], bottom[prefer[u]]);
  for (auto v : tree[u]) {
    if (v == fa[u] || v == prefer[u])
      continue;
    decomposition(v, v);
    bottom[u] = max(bottom[u], bottom[v]);
  }
}
void insert(ll p, ll lst, ll v) {
  for (int i = 28; i >= 0; --i) {
    cnt[p] = cnt[lst] + 1;
    if ((v & (1 << i)) == 0) {
      if (!trie[p][0])
        trie[p][0] = ++cur;
      trie[p][1] = trie[lst][1];
      p = trie[p][0];
      lst = trie[lst][0];
    } else {
      if (!trie[p][1])
        trie[p][1] = ++cur;
      trie[p][0] = trie[lst][0];
      p = trie[p][1];
      lst = trie[lst][1];
    }
  }
  cnt[p] = cnt[lst] + 1;
}
ll query(ll l, ll r, ll val) {
  ll res = 0;
  for (int i = 28; i >= 0; --i) {
    auto tmp = ((val & (1 << i)) == 0 ? 1 : 0);
    if (cnt[trie[l][tmp]] != cnt[trie[r][tmp]]) {
      res += (1 << i);
      l = trie[l][tmp];
      r = trie[r][tmp];
    } else {
      l = trie[l][!tmp];
      r = trie[r][!tmp];
    }
  }
  return res;
}
ll querychain(ll u, ll v, ll val) {
  ll res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    res = max(res, query(roots[dfn[top[u]] - 1], roots[dfn[u]], val));
    u = fa[top[u]];
  }
  if (dfn[u] > dfn[v])
    swap(u, v);
  res = max(query(roots[dfn[u] - 1], roots[dfn[v]], val), res);
  return res;
}
int main() {
  ll opt, u, v, w;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  getson(1);
  decomposition(1, 1);
  for (int i = 1; i <= n; ++i) {
    roots[i] = ++cur;
    insert(roots[i], roots[i - 1], val[node[i]]);
  }
  while (q--) {
    cin >> opt;
    if (opt == 1) {
      cin >> u >> w;
      cout << query(roots[dfn[u] - 1], roots[bottom[u]], w) << endl;
    } else {
      cin >> u >> v >> w;
      cout << querychain(u, v, w) << endl;
    }
  }
  return 0;
}
/**
7 5
1 3 5 7 9 2 4
1 2
1 3
2 4
2 5
3 6
3 7
1 3 5
2 4 6 3
1 5 5
2 5 7 2
1 1 9
**/
/**
14 8
11 12 12 14 11 8 2 1 7 2 5 1 6 9
1 2
1 4
2 3
3 5
4 6
6 7
6 8
7 10
7 12
7 13
8 9
8 11
9 14
[2, 14, 7, 8] 15
[2, 3, 10, 7] 15
[2, 2, 4, 14] 5
[1, 12, 12] 13
[1, 7, 1] 7
[2, 6, 1, 9] 7
[1, 4, 1] 15
[1, 4, 14] 15
**/