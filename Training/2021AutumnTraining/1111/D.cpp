#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200010;
ll n, m, q;
vector<pair<ll, ll>> graph[MAXN];
ll low[MAXN], dfn[MAXN], dfs_clock;
bool is_bridge[MAXN];
ll numedge = 0;
void tarjan(ll u, ll f) {
  low[u] = dfn[u] = ++dfs_clock;
  for (auto x : graph[u]) {
    auto v = x.first;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) is_bridge[x.second] = true;
    } else if (dfn[v] < dfn[u] && v != f) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}
bool vis[MAXN];
ll siz;
void dfs(int u) {
  vis[u] = true;
  siz++;
  for (auto x : graph[u]) {
    auto v = x.first;
    if (vis[v] || is_bridge[x.second]) continue;
    dfs(v);
  }
}
void solve() {
  ll u, v;
  cin >> u >> v;
  graph[u].push_back(make_pair(v, ++numedge));
  graph[v].push_back(make_pair(u, numedge));
  dfs_clock = 0;
  siz = 0;
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(vis, 0, sizeof(vis));
  memset(is_bridge, 0, sizeof(is_bridge));
  tarjan(u, u);
  if (!dfn[v]) {
    cout << "No" << endl;
    return;
  }
  tarjan(v, v);
  dfs(u);
  if (!vis[v])
    cout << "No" << endl;
  else
    cout << siz << endl;
}
int main() {
  ll u, v;
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(make_pair(v, ++numedge));
    graph[v].push_back(make_pair(u, numedge));
  }
  while (q--) solve();
  return 0;
}