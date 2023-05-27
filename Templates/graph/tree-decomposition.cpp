// https://www.luogu.com.cn/problem/P3384
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll MAXN = 100010;
struct Node {
  ll l, r, val, tag;
};
ll n, m, r, p;
ll orig[MAXN], val[MAXN];
vector<ll> tree[MAXN];
ll parent[MAXN], prefer[MAXN], weight[MAXN];
ll dfn[MAXN], dep[MAXN];
ll top[MAXN], bottom[MAXN];
ll idx = 0;
Node segt[MAXN * 4];
#define lc(x) segt[(x)*2]
#define rc(x) segt[(x)*2 + 1]
void buildTree(ll u, ll p) {
  parent[u] = p;
  dep[u] = dep[p] + 1;
  for (auto v : tree[u]) {
    if (v != p) {
      buildTree(v, u);
      weight[u] += weight[v];
      if (weight[v] > weight[prefer[u]])
        prefer[u] = v;
    }
  }
  ++weight[u];
}
void treeDecomposition(ll u, ll t) {
  dfn[u] = ++idx;
  top[u] = t;
  bottom[u] = dfn[u];
  if (prefer[u])
    treeDecomposition(prefer[u], t);
  for (auto v : tree[u]) {
    if (v == parent[u])
      continue;
    if (v != prefer[u])
      treeDecomposition(v, v);
    bottom[u] = max(bottom[u], bottom[v]);
  }
}
void buildSegt(ll l, ll r, ll cur) {
  segt[cur].l = l;
  segt[cur].r = r;
  if (l == r) {
    segt[cur].val = val[l];
    return;
  }
  ll mid = (l + r) / 2;
  buildSegt(l, mid, cur * 2);
  buildSegt(mid + 1, r, cur * 2 + 1);
  segt[cur].val = (segt[cur * 2].val + segt[cur * 2 + 1].val) % p;
}
void pushdown(ll cur) {
  if (segt[cur].tag) {
    lc(cur).val =
        (lc(cur).val + segt[cur].tag * (lc(cur).r - lc(cur).l + 1) % p) % p;
    rc(cur).val =
        (rc(cur).val + segt[cur].tag * (rc(cur).r - rc(cur).l + 1) % p) % p;
    lc(cur).tag = (lc(cur).tag + segt[cur].tag) % p;
    rc(cur).tag = (rc(cur).tag + segt[cur].tag) % p;
    segt[cur].tag = 0;
  }
}
void modifySegt(ll s, ll t, ll delta, ll cur) {
  if (s > t)
    swap(s, t);
  if (s <= segt[cur].l && segt[cur].r <= t) {
    segt[cur].val =
        (segt[cur].val + delta * (segt[cur].r - segt[cur].l + 1) % p) % p;
    segt[cur].tag = (segt[cur].tag + delta) % p;
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  pushdown(cur);
  if (s <= mid)
    modifySegt(s, t, delta, cur * 2);
  if (mid + 1 <= t)
    modifySegt(s, t, delta, cur * 2 + 1);
  segt[cur].val = (lc(cur).val + rc(cur).val) % p;
}
ll querySegt(ll s, ll t, ll cur) {
  if (s > t)
    swap(s, t);
  if (s <= segt[cur].l && segt[cur].r <= t) {
    return segt[cur].val;
  }
  ll res = 0, mid = (segt[cur].l + segt[cur].r) / 2;
  pushdown(cur);
  if (s <= mid)
    res = (res + querySegt(s, t, cur * 2)) % p;
  if (mid + 1 <= t)
    res = (res + querySegt(s, t, cur * 2 + 1)) % p;
  return res;
}
void modifyPath(ll u, ll v, ll delta) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    modifySegt(dfn[u], dfn[top[u]], delta, 1);
    u = parent[top[u]];
  }
  modifySegt(dfn[u], dfn[v], delta, 1);
}
ll queryPath(ll u, ll v) {
  ll res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    res = (res + querySegt(dfn[u], dfn[top[u]], 1)) % p;
    u = parent[top[u]];
  }
  res = (res + querySegt(dfn[u], dfn[v], 1)) % p;
  return res;
}
void modifySubtree(ll u, ll delta) { modifySegt(dfn[u], bottom[u], delta, 1); }
ll querySubtree(ll u) { return querySegt(dfn[u], bottom[u], 1); }
int main() {
  ll opt, x, y, z;
  cin >> n >> m >> r >> p;
  for (int i = 1; i <= n; i++) {
    cin >> orig[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  buildTree(r, 0);
  treeDecomposition(r, r);
  for (int i = 1; i <= n; i++) {
    val[dfn[i]] = orig[i] % p;
  }
  buildSegt(1, n, 1);
  while (m--) {
    cin >> opt;
    if (opt == 1) {
      cin >> x >> y >> z;
      modifyPath(x, y, z);
    } else if (opt == 2) {
      cin >> x >> y;
      cout << queryPath(x, y) << endl;
    } else if (opt == 3) {
      cin >> x >> y;
      modifySubtree(x, y);
    } else {
      cin >> x;
      cout << querySubtree(x) << endl;
    }
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}