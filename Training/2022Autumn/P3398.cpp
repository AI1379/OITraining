#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
static ll n, q;
vector<ll> tree[MAXN];
static ll top[MAXN], siz[MAXN], fa[MAXN], pref[MAXN], dep[MAXN], dfn[MAXN], idx;
void build(ll u, ll p) {
  fa[u] = p;
  siz[u] = 1;
  for (const ll &v : tree[u]) {
    if (v == p)
      continue;
    build(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[pref[u]])
      pref[u] = v;
  }
}
void decomp(ll u, ll t) {
  dep[u] = dep[fa[u]] + 1;
  dfn[u] = ++idx;
  top[u] = t;
  if (!pref[u])
    return;
  decomp(pref[u], t);
  for (const ll &v : tree[u]) {
    if (v == fa[u] || v == pref[u])
      continue;
    decomp(v, v);
  }
}
ll lca(ll a, ll b) {
  while (top[a] != top[b]) {
    if (dep[top[a]] > dep[top[b]])
      a = fa[top[a]];
    else
      b = fa[top[b]];
  }
  if (dep[a] > dep[b])
    return b;
  return a;
}
#define RUN(a, b, y)                                                           \
  while (top[a] != top[b]) {                                                   \
    if (dep[top[a]] > dep[top[b]]) {                                           \
      if (dfn[top[a]] <= dfn[y] && dfn[y] <= dfn[a])                           \
        goto output;                                                           \
      a = fa[top[a]];                                                          \
    } else {                                                                   \
      if (dfn[top[b]] <= dfn[y] && dfn[y] <= dfn[b])                           \
        goto output;                                                           \
      b = fa[top[b]];                                                          \
    }                                                                          \
  }                                                                            \
  if (dfn[a] > dfn[b])                                                         \
    swap(a, b);                                                                \
  if (dfn[a] <= dfn[y] && dfn[y] <= dfn[b])                                    \
    goto output;

static ll a, b, c, d;
void solve() {
  cin >> a >> b >> c >> d;
  static ll x, y;
  x = lca(a, b);
  y = lca(c, d);
  RUN(a, b, y);
  RUN(c, d, x);
  cout << "N\n";
  return;
output:
  cout << "Y\n";
  return;
}
int main() {
  ll u, v;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> q;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  build(1, 0);
  decomp(1, 1);
  while (q--)
    solve();
  return 0;
}