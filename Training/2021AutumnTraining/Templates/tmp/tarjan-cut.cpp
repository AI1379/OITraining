#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 20010;
const ll MAXM = 100010;
ll n, m;
vector<ll> graph[MAXN];
ll dfn[MAXN], low[MAXN];
ll idx = 0;
ll cutnum;
bool cut[MAXN];
void tarjan(ll u, ll fa) {
  low[u] = dfn[u] = ++idx;
  ll childn = 0;
  for (auto v : graph[u]) {
    if (!dfn[v]) {
      childn++;
      tarjan(v, u);
      low[u] = min(low[v], low[u]);
      if (u != fa && low[v] >= dfn[u] && !cut[u]) {
        cutnum++;
        cut[u] = true;
      }
    } else if (v != fa) {
      low[u] = min(low[v], low[u]);
    }
  }
  if (u == fa && childn >= 2 && !cut[u]) {
    cut[u] = true;
    cutnum++;
  }
}
int main() {
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i, i);
  cout << cutnum << endl;
  for (int i = 1; i <= n; i++)
    if (cut[i]) cout << i << ' ';
  cout << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}