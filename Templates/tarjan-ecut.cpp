#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
const ll MAXN = 20010;
const ll MAXM = 100010;

namespace TarjanECut {
  ll n, m;
  vector<ll> graph[MAXN];
  ll parent[MAXN];
  ll dfn[MAXN], low[MAXN], idx = 0;
  ll ecut_num = 0;
  bool is_ecut[MAXN];
  void tarjan(ll u, ll fa) {
    dfn[u] = low[u] = ++idx;
    parent[u] = fa;
    ll child = 0;
    for (auto v : graph[u]) {
      if (!dfn[v]) {
        ++child;
        tarjan(v, u);
        low[u] = min(low[v], low[u]);
        if (low[v] > dfn[u] && !is_ecut[u]) {
          is_ecut[v] = true;
          ++ecut_num;
        }
      } else if (fa != v) {
        low[u] = min(low[u], dfn[v]);
      }
    }
  }
  void run() {
    ll u, v;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(is_ecut, false, sizeof(is_ecut));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      cin >> u >> v;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
      if (!dfn[i]) {
        tarjan(i, 0);
      }
    }
    cout << ecut_num << endl;
    for (int i = 1; i <= n; i++) {
      if (is_ecut[i]) {
        cout << i << ' ' << parent[i];
      }
    }
  }
}
int main() {
  TarjanECut::run();
  return 0;
}
