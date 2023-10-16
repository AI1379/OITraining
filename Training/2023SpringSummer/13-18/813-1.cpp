#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
ll n, m;
vector<pll> graph[MAXN];
ll dp[MAXN];
ll deg[MAXN];
bool vis[MAXN];
int main() {
  ll u, v, w;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v >> w;
    graph[u].emplace_back(v, w);
    ++deg[v];
  }
  queue<ll> q;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) {
      q.emplace(i);
      vis[i] = true;
    }
  }
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (auto [v, w] : graph[u]) {
      if (vis[v]) {
        cout << "loop" << endl;
        return 0;
      }
      --deg[v];
      dp[v] = max(dp[v], dp[u] + w);
      if (deg[v] == 0) {
        q.emplace(v);
      }
    }
  }
  v = 0;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      cout << "loop" << endl;
      return 0;
    }
    v = max(v, dp[i]);
  }
  cout << v << endl;
  return 0;
}