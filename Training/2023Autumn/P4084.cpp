#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MOD = 1e9 + 7;
ll n, k;
vector<ll> tree[MAXN];
ll dp[MAXN][5];
void dfs(ll u, ll fa) {
  for (auto v : tree[u]) {
    if (v == fa)
      continue;
    dfs(v, u);
    dp[u][1] = dp[u][1] * (dp[v][2] + dp[v][3]) % MOD;
    dp[u][2] = dp[u][2] * (dp[v][3] + dp[v][1]) % MOD;
    dp[u][3] = dp[u][3] * (dp[v][1] + dp[v][2]) % MOD;
  }
}
int main() {
  ll u, v;
  cin >> n >> k;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i)
    dp[i][1] = dp[i][2] = dp[i][3] = 1;
  for (int i = 1; i <= k; ++i) {
    cin >> u >> v;
    dp[u][(v) % 3 + 1] = dp[u][(v + 1) % 3 + 1] = 0;
  }
  dfs(1, 0);
  cout << (dp[1][1] + dp[1][2] + dp[1][3]) % MOD << endl;
  return 0;
}