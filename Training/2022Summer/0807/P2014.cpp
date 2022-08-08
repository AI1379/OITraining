#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll MAXN = 310;
const ll MAXM = 310;
ll n, m;
ll val[MAXN];
vector<ll> tree[MAXN];
ll dp[MAXN][MAXM];
void dfs(ll u, ll p) {
  dp[u][0] = 0;
  for (auto v : tree[u]) {
    if (v != p) {
      dfs(v, u);
      for (int t = m; t >= 0; --t) {
        for (int j = 0; j <= t; ++j) {
          dp[u][t] = max(dp[u][t], dp[u][t - j] + dp[v][j]);
        }
      }
    }
  }
  if (u != 0) {
    for (int t = m; t > 0; --t) {
      dp[u][t] = dp[u][t - 1] + val[u];
    }
  }
}
int main() {
  ll pa;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> pa >> val[i];
    tree[i].emplace_back(pa);
    tree[pa].emplace_back(i);
  }
  dfs(0, 0);
  cout << dp[0][m] << endl;
  return 0;
}
