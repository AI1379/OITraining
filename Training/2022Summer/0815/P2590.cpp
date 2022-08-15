#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define ll long long
const ll MAXN = 30010;
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
struct Node {
  ll l, r, sum, max;
};
static ll n, q;
static ll val[MAXN];
vector<ll> tree[MAXN];
static ll parent[MAXN], dfn[MAXN], rnk[MAXN], top[MAXN];
static ll dep[MAXN], weight[MAXN], prefer[MAXN];
static Node segt[MAXN * 4];
static ll idx = 0;
#define lc(x) segt[(x)*2]
#define rc(x) segt[(x)*2 + 1]
void buildTree(ll u, ll p) {
  parent[u] = p;
  dep[u] = dep[p] + 1;
  ++weight[u];
  for (auto v : tree[u]) {
    if (v != p) {
      buildTree(v, u);
      weight[u] += weight[v];
      if (weight[v] > weight[prefer[u]]) {
        prefer[u] = v;
      }
    }
  }
}
void treeDecomposition(ll u, ll t) {
  dfn[u] = ++idx;
  rnk[dfn[u]] = u;
  top[u] = t;
  if (prefer[u])
    treeDecomposition(prefer[u], t);
  for (auto v : tree[u]) {
    if (v == parent[u])
      continue;
    if (v != prefer[u])
      treeDecomposition(v, v);
  }
}
void buildSegt(ll l, ll r, ll cur) {
  segt[cur].l = l;
  segt[cur].r = r;
  if (l == r) {
    segt[cur].sum = segt[cur].max = val[l];
    return;
  }
  ll mid = (l + r) / 2;
  buildSegt(l, mid, cur * 2);
  buildSegt(mid + 1, r, cur * 2 + 1);
  segt[cur].sum = (lc(cur).sum + rc(cur).sum);
  segt[cur].max = max(lc(cur).max, rc(cur).max);
}
void modifySegt(ll pos, ll val, ll cur) {
  if (segt[cur].l == pos && segt[cur].r == pos) {
    segt[cur].sum = segt[cur].max = val;
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (pos <= mid)
    modifySegt(pos, val, cur * 2);
  else
    modifySegt(pos, val, cur * 2 + 1);
  segt[cur].sum = (lc(cur).sum + rc(cur).sum);
  segt[cur].max = max(lc(cur).max, rc(cur).max);
}
ll querySegtMax(ll s, ll t, ll cur) {
  if (s > t)
    swap(s, t);
  if (s <= segt[cur].l && segt[cur].r <= t) {
    return segt[cur].max;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  ll res = -INF;
  if (s <= mid)
    res = max(res, querySegtMax(s, t, cur * 2));
  if (mid + 1 <= t)
    res = max(res, querySegtMax(s, t, cur * 2 + 1));
  return res;
}
ll querySegtSum(ll s, ll t, ll cur) {
  if (s > t)
    swap(s, t);
  if (s <= segt[cur].l && segt[cur].r <= t) {
    return segt[cur].sum;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  ll res = 0;
  if (s <= mid)
    res = (res + querySegtSum(s, t, cur * 2));
  if (mid + 1 <= t)
    res = (res + querySegtSum(s, t, cur * 2 + 1));
  return res;
}
ll queryTreeMax(ll u, ll v) {
  ll res = -INF;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    res = max(res, querySegtMax(dfn[u], dfn[top[u]], 1));
    u = parent[top[u]];
  }
  res = max(res, querySegtMax(dfn[u], dfn[v], 1));
  return res;
}
ll queryTreeSum(ll u, ll v) {
  ll res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    res = (res + querySegtSum(dfn[u], dfn[top[u]], 1));
    u = parent[top[u]];
  }
  res = (res + querySegtSum(dfn[u], dfn[v], 1));
  return res;
}
static ll u, v;
string opt;
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  buildTree(1, 0);
  treeDecomposition(1, 1);
  for (int i = 1; i <= n; i++) {
    cin >> val[dfn[i]];
  }
  buildSegt(1, n, 1);
  cin >> q;
  while (q--) {
    cin >> opt;
    if (opt == "CHANGE") {
      cin >> u >> v;
      modifySegt(dfn[u], v, 1);
    } else if (opt == "QMAX") {
      cin >> u >> v;
      cout << queryTreeMax(u, v) << endl;
    } else {
      cin >> u >> v;
      cout << queryTreeSum(u, v) << endl;
    }
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}