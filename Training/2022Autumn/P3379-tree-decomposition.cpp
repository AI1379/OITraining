#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 500010;
static ll n, m, s;
static ll top[MAXN], fa[MAXN], dep[MAXN];
static ll prefer[MAXN], siz[MAXN];
vector<ll> tree[MAXN];
void build(ll u, ll p) {
  siz[u] = 1;
  fa[u] = p;
  dep[u] = dep[p] + 1;
  for (const ll &v : tree[u]) {
    if (v == p)
      continue;
    build(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[prefer[u]])
      prefer[u] = v;
  }
}
void decomposition(ll u, ll t) {
  top[u] = t;
  if (prefer[u] != 0)
    decomposition(prefer[u], t);
  for (const ll &v : tree[u]) {
    if (v != fa[u] && v != prefer[u]) {
      decomposition(v, v);
    }
  }
}
ll lca(ll u, ll v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] > dep[top[v]])
      u = fa[top[u]];
    else
      v = fa[top[v]];
  }
  if (dep[u] > dep[v])
    return v;
  return u;
}
int main() {
  static ll u, v;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> s;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  build(s, 0);
  decomposition(s, s);
  while (m--) {
    cin >> u >> v;
    cout << lca(u, v) << endl;
  }
  return 0;
}