#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
ll n, m;
ll w[MAXN];
vector<ll> graph[MAXN];
ll stk[MAXN], top = 0;
ll dfn[MAXN], low[MAXN], scc[MAXN], cnt = 0, tot = 0;
bool instk[MAXN];
vector<ll> dag[MAXN];
ll dagmx[MAXN], dagmn[MAXN];
ll indeg[MAXN];
ll ans = 0;
bool connected[MAXN], vis[MAXN];
void tarjan(ll u) {
  low[u] = dfn[u] = ++cnt;
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
    ++tot;
    dagmn[tot] = 1e9;
    while (stk[top + 1] != u) {
      scc[stk[top]] = tot;
      instk[stk[top]] = false;
      dagmn[tot] = min(dagmn[tot], w[stk[top]]);
      dagmx[tot] = max(dagmx[tot], w[stk[top]]);
      --top;
    }
  }
}
int main() {
  ll u, v, opt;
  ios::sync_with_stdio(false);
  cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v >> opt;
    if (opt == 1) {
      graph[u].emplace_back(v);
    } else {
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
  }
  tarjan(1);
  for (int u = 1; u <= n; ++u) {
    for (auto v : graph[u]) {
      if (scc[u] == scc[v])
        continue;
      dag[scc[u]].emplace_back(scc[v]);
      ++indeg[scc[v]];
    }
  }
  queue<ll> q;
  q.push(scc[1]);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (auto v : dag[u]) {
      dagmn[v] = min(dagmn[v], dagmn[u]);
      --indeg[v];
      if (indeg[v] == 0)
        q.push(v);
    }
  }
  function<void(ll)> dfs = [&](ll cur) {
    vis[cur] = true;
    if (cur == scc[n]) {
      connected[cur] = true;
      return;
    }
    for (auto v : dag[cur]) {
      if (!vis[v])
        dfs(v);
      connected[cur] |= connected[v];
    }
  };
  dfs(scc[1]);
  for (int i = 1; i <= tot; ++i) {
    if (connected[i])
      ans = max(ans, dagmx[i] - dagmn[i]);
  }
  if (ans == 0)
    cout << "mei zuan dao" << endl;
  else
    cout << ans << endl;
  return 0;
}