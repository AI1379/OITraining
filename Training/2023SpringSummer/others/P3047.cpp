#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MAXK = 31;
ll n, k;
ll val[MAXN];
vector<ll> tree[MAXN];
ll sum[MAXN][MAXK], dp[MAXN][MAXK];
void init(ll u, ll fa) {
  for (int i = 0; i <= k; ++i) {
    sum[u][i] = val[u];
  }
  for (auto v : tree[u]) {
    if (v == fa)
      continue;
    init(v, u);
    for (int i = 1; i <= k; ++i) {
      sum[u][i] += sum[v][i - 1];
    }
  }
}
void dfs(ll u, ll fa) {
  for (auto v : tree[u]) {
    if (v == fa)
      continue;
    dp[v][1] = sum[v][1] + val[u];
    for (int i = 2; i <= k; ++i) {
      dp[v][i] = sum[v][i] + dp[u][i - 1] - sum[v][i - 2];
    }
    dfs(v, u);
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
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  init(1, 0);
  for (int i = 0; i <= k; ++i) {
    dp[1][i] = sum[1][i];
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    cout << dp[i][k] << endl;
  }
  return 0;
}