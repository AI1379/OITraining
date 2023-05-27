#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 127;
const ll MAXM = 511;
ll n, m;
ll w[MAXN];
ll v[MAXN];
ll fa[MAXN];
vector<ll> graph[MAXN];
bool instk[MAXN];
ll stk[MAXN], top;
ll dfn[MAXN], low[MAXN], idx = 0;
vector<ll> tree[MAXN];
ll scc[MAXN];
ll sccn;
ll sccval[MAXN], sccweight[MAXN];
bool vis[MAXN];
void tarjan(ll u) {
  dfn[u] = low[u] = ++idx;
  stk[++top] = u;
  instk[u] = true;
  for (auto v : graph[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (instk[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sccn;
    while (instk[u]) {
      instk[stk[top]] = false;
      sccval[sccn] += v[stk[top]];
      sccweight[sccn] += w[stk[top]];
      scc[stk[top]] = sccn;
      --top;
    }
  }
}
ll deg[MAXN];
ll f[MAXN][MAXM];
void dp(ll u) {
  vis[u] = true;
  for (int i = sccweight[u]; i <= m; ++i)
    f[u][i] = sccval[u];
  for (const ll &v : tree[u]) {
    if (vis[v])
      continue;
    dp(v);
    for (int wu = m; wu >= sccweight[u]; --wu) {
      for (int wv = 1; wv + sccweight[u] <= wu; ++wv) {
        f[u][wu] = max(f[u][wu], f[u][wu - wv] + f[v][wv]);
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> fa[i];
    if (fa[i] != 0)
      graph[fa[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (!dfn[i])
      tarjan(i);
  }
  for (int i = 1; i <= n; ++i) {
    for (auto v : graph[i]) {
      if (scc[i] != scc[v]) {
        tree[scc[i]].emplace_back(scc[v]);
        ++deg[scc[v]];
      }
    }
  }
  for (int i = 1; i <= sccn; ++i) {
    if (deg[i] == 0)
      tree[0].emplace_back(i);
  }
  dp(0);
  cout << f[0][m] << endl;
  return 0;
}