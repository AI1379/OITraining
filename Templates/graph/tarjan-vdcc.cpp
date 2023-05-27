#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
const ll MAXN = 500010;
const ll MAXM = 2000010;

namespace TarjanVBCC {
  ll n, m;
  vector<ll> graph[MAXN];
  ll dfn[MAXN], low[MAXN], idx = 0;
  ll stk[MAXN], top = 0;
  vector<ll> vbcc[MAXN];
  ll vbcc_num = 0;
  void tarjan(ll u, ll fa) {
    dfn[u] = low[u] = ++idx;
    stk[++top] = u;
    ll child = 0;
    if (graph[u].size() == 0) {
      vbcc[++vbcc_num].emplace_back(u);
      return;
    }
    for (auto v : graph[u]) {
      if (!dfn[v]) {
        ++child;
        tarjan(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] >= dfn[u]) {
          ++vbcc_num;
          while (top && stk[top + 1] != v) {
            vbcc[vbcc_num].emplace_back(stk[top--]);
          }
          vbcc[vbcc_num].emplace_back(u);
        }
      } else if (v != fa) {
        low[u] = min(low[u], dfn[v]);
      }
    }
  }
  void run() {
    ll u, v;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      cin >> u >> v;
      // self-loop
      if (u == v) continue;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
      if (!dfn[i]) {
        top = 0;
        tarjan(i, 0);
      }
    }
    cout << vbcc_num << endl;
    for (int i = 1; i <= vbcc_num; i++) {
      cout << vbcc[i].size() << ' ';
      for (auto u : vbcc[i]) {
        cout << u << ' ';
      }
      cout << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  TarjanVBCC::run();
  return 0;
}
