#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 80010;
const ll MAXM = 200010;
struct Edge {
  ll u, v, w;
  double c;
};
ll n, m, s;
ll dfn[MAXN], low[MAXN], idx;
ll stk[MAXN], top;
bool instk[MAXN];
ll scc[MAXN], sccn;
vector<ll> graph[MAXN];
Edge edges[MAXM];
void tarjan(ll u) {
  dfn[u] = low[u] = ++idx;
  stk[++top] = u;
  for (auto v : graph[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[v], low[u]);
    } else if (instk[v]) {
      low[u] = min(low[u], dfn[u]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sccn;
    while (instk[u]) {
      scc[stk[top]] = sccn;
      instk[stk[top]] = false;
      --top;
    }
  }
}
int main() {
  ll u, v, w;
  double c;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v >> w >> c;
    graph[u].emplace_back(v);
    edges[i] = (Edge){u, v, w, c};
  }
  cin >> s;
  tarjan(s);

  return 0;
}