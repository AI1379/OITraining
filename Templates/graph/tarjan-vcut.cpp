#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
const ll MAXN = 20010;
const ll MAXM = 100010;

namespace TarjanVCut {
  ll n, m;
  vector<ll>graph[MAXN];
  ll dfn[MAXN], low[MAXN], idx = 0;
  ll vcut_num = 0;
  bool is_vcut[MAXN];
  void tarjan(ll u, ll fa) {
    dfn[u] = low[u] = ++idx;
    ll child = 0;
    for (auto v : graph[u]) {
      if (!dfn[v]) {
        ++child;
        tarjan(v, u);
        low[u] = min(low[v], low[u]);
        if (fa != 0 && low[v] >= dfn[u] && !is_vcut[u]) {
          is_vcut[u] = true;
          ++vcut_num;
        }
      } else if (fa != v) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (fa == 0 && child >= 2 && !is_vcut[u]) {
      is_vcut[u] = true;
      ++vcut_num;
    }
  }
  void run() {
    ll u, v;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(is_vcut, false, sizeof(is_vcut));
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
    cout << vcut_num << endl;
    for (int i = 1; i <= n; i++) {
      if (is_vcut[i]) {
        cout << i << ' ';
      }
    }
  }
}
int main() {
  TarjanVCut::run();
  return 0;
}
