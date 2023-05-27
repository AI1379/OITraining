// https://www.luogu.com.cn/problem/P3387

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
const ll MAXN = 10010;
const ll MAXM = 100010;
namespace TarjanSCC {
ll n, m;
ll val[MAXN];
vector<ll> graph[MAXN];
bool in_stk[MAXN];
ll dfn[MAXN], low[MAXN];
ll stk[MAXN], top = 0;
ll scc[MAXN];
ll idx = 0;
void init() {
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(in_stk, 0, sizeof(in_stk));
}
void run();
void tarjan(ll u);
void makeDAG();
} // namespace TarjanSCC
namespace DAG {
ll n = 0;
ll val[MAXN];
ll deg[MAXN];
ll dp[MAXN];
ll ans = 0;
vector<ll> graph[MAXN];
void run();
} // namespace DAG

void TarjanSCC::run() {
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> TarjanSCC::val[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].emplace_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i])
      TarjanSCC::tarjan(i);
  }
  TarjanSCC::makeDAG();
}

void TarjanSCC::tarjan(ll u) {
  using namespace TarjanSCC;
  dfn[u] = low[u] = ++idx;
  stk[++top] = u;
  in_stk[u] = true;
  for (auto v : graph[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stk[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++DAG::n;
    while (top && stk[top] != u) {
      scc[stk[top]] = DAG::n;
      in_stk[stk[top]] = false;
      --top;
    }
    scc[stk[top]] = DAG::n;
    in_stk[stk[top]] = false;
    --top;
  }
}

void TarjanSCC::makeDAG() {
  for (int u = 1; u <= n; u++) {
    DAG::val[scc[u]] += TarjanSCC::val[u];
    for (auto v : TarjanSCC::graph[u]) {
      if (scc[v] == scc[u]) {
        continue;
      }
      DAG::graph[scc[u]].emplace_back(scc[v]);
      ++DAG::deg[scc[v]];
    }
  }
}

void DAG::run() {
  using namespace DAG;
  queue<ll> q;
  for (int i = 1; i <= n; i++) {
    dp[i] = val[i];
    ans = max(ans, dp[i]);
    if (deg[i] == 0) {
      q.push(i);
    }
  }
  ll u;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (auto v : graph[u]) {
      --deg[v];
      if (deg[v] == 0) {
        q.push(v);
      }
      dp[v] = max(dp[v], dp[u] + val[v]);
      ans = max(ans, dp[v]);
    }
  }
  cout << ans << endl;
}

int main() {
  TarjanSCC::run();
  DAG::run();
  return 0;
}
