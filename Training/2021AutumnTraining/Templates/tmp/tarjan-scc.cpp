#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10010;
const ll MAXM = 100010;
ll n, m;
ll w[MAXN];
vector<ll> graph[MAXN];
ll scc[MAXN];
ll dfn[MAXN], low[MAXN];
ll idx;
bool instk[MAXN];
ll stk[MAXN], top = 0;
ll dagn, dagm;
ll deg[MAXN];
ll dp[MAXN];
ll dagw[MAXN];
vector<ll> dag[MAXN];
bool vis[MAXN];
void tarjan(ll u) {
  low[u] = dfn[u] = ++idx;
  instk[u] = true;
  stk[++top] = u;
  for (auto v : graph[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (instk[v]) {
      low[u] = min(low[u], low[v]);
    }
  }
  if (dfn[u] == low[u]) {
    dagn++;
    while (top > 0 && stk[top] != u) {
      scc[stk[top]] = dagn;
      instk[stk[top]] = false;
      top--;
    }
    scc[stk[top]] = dagn;
    instk[stk[top]] = false;
    top--;
  }
  return;
}
void getSCC() {
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= n; i++) {
    dagw[scc[i]] += w[i];
    for (auto v : graph[i]) {
      if (scc[v] == scc[i]) continue;
      dag[scc[i]].push_back(scc[v]);
      deg[scc[v]]++;
    }
  }
  return;
}
ll ans = 0;
void getDis() {
  queue<ll> q;
  for (int i = 1; i <= dagn; i++) {
    if (deg[i] == 0) {
      q.push(i);
      dp[i] = dagw[i];
      ans = max(ans, dp[i]);
    }
  }
  ll u;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (auto v : dag[u]) {
      deg[v]--;
      if (deg[v] == 0) q.push(v);
      dp[v] = max(dp[v], dp[u] + dagw[v]);
      ans = max(ans, dp[v]);
    }
  }
}
int main() {
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
  }
  getSCC();
  getDis();
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}