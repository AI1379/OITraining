#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
const ll MAXM = 100010;
ll read() {
  static char c;
  static ll res;
  res = 0;
  do
    c = getchar();
  while (c < '0' || '9' < c);
  do {
    res = res * 10 + c - '0';
    c = getchar();
  } while ('0' <= c && c <= '9');
  return res;
}
ll readw() {
  static char c;
  static ll res, k;
  res = 0;
  k = 1;
  do
    c = getchar();
  while (c < '0' || '9' < c);
  do {
    res += k * (c - '0');
    k *= 10;
    c = getchar();
  } while ('0' <= c && c <= '9');
  return res;
}
static ll n, m;
static ll s[MAXM], mk[MAXM];
vector<pll> tree[MAXN];
static ll fa[30][MAXN];
static ll dep[MAXN];
static ll dis[MAXN];
void dfs(ll u, ll f) {
  fa[0][u] = f;
  dep[u] = dep[f] + 1;
  for (pll &obj : tree[u]) {
    if (obj.first != f) {
      dis[obj.first] = dis[u] + obj.second;
      dfs(obj.first, u);
    }
  }
}
ll lca(ll u, ll v) {
  if (dep[u] > dep[v])
    swap(u, v);
  static ll d, i;
  d = dep[v] - dep[u];
  for (i = 0; d; ++i, d >>= 1)
    if (d & 1)
      v = fa[i][v];
  if (u == v)
    return u;
  for (i = 20; i >= 0; --i)
    if (fa[i][u] != fa[i][v])
      u = fa[i][u], v = fa[i][v];
  return fa[0][u];
}
ll gdis(ll u, ll v) { return dis[u] + dis[v] - 2ll * dis[lca(u, v)]; }
static ll ans = (1ll << (sizeof(ll) * 8 - 2));
static bool vis[MAXM];
void calc(ll dep, ll cur) {
  if (dep > m) {
    ans = min(ans, cur);
    return;
  }
  for (int i = 1; i <= m; ++i) {
    if (!vis[i]) {
      vis[i] = true;
      calc(dep + 1, cur + gdis(s[dep], mk[i]));
      vis[i] = false;
    }
  }
}
int main() {
  static ll i, j, u, v, w;
  n = read();
  m = read();
  for (i = 1; i <= m; ++i)
    s[i] = read();
  for (i = 1; i <= m; ++i)
    mk[i] = read();
  for (i = 1; i <= n - 1; ++i) {
    u = read(), v = read(), w = readw();
    tree[u].push_back(make_pair(v, w));
    tree[v].push_back(make_pair(u, w));
  }
  dfs(1, 0);
  for (j = 1; (1 << j) <= n; ++j)
    for (i = 1; i <= n; ++i)
      fa[j][i] = fa[j - 1][fa[j - 1][i]];
  calc(1, 0);
  printf("%lld\n", ans);
  return 0;
}