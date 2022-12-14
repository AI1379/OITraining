#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
const ll MAXN = 500010;
const ll MAXM = 2000010;

// TODO: fix this
namespace TarjanEBCC {
  ll n, m;
  vector<ll> graph[MAXN];
  ll parent[MAXN];
  ll dfn[MAXN], low[MAXN], idx = 0;
  ll ecut_num = 0;
  bool is_ecut[MAXN];
  ll ebcc_num = 0;
  vector<ll> ebcc[MAXN];
  ll stk[MAXN], top = 0;
  void tarjan(ll u, ll fa) {
    dfn[u] = low[u] = ++idx;
    parent[u] = fa;
    ll child = 0;
    stk[++top] = u;
    if (graph[u].size() == 0) {
      ebcc[++ebcc_num].emplace_back(u);
      return;
    }
    for (auto v : graph[u]) {
      if (!dfn[v]) {
        ++child;
        tarjan(v, u);
        low[u] = min(low[v], low[u]);
        if (low[v] > dfn[u] && !is_ecut[u]) {
          is_ecut[v] = true;
          ++ecut_num;
          ++ebcc_num;
          while (top && stk[top + 1] != v) {
            ebcc[ebcc_num].emplace_back(stk[top--]);
          }
        }
      } else if (fa != v) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (fa == 0 && top != 0) {
      ++ebcc_num;
      while (top) {
        ebcc[ebcc_num].emplace_back(stk[top--]);
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
    cout << ebcc_num << endl;
    for (int i = 1; i <= ebcc_num; i++) {
      cout << ebcc[i].size() << ' ';
      for (auto u : ebcc[i]) {
        cout << u << ' ';
      }
      cout << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  TarjanEBCC::run();
  return 0;
}
