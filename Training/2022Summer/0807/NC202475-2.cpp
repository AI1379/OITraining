#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll MAXN = 100010;
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
ll n;
ll val[MAXN];
vector<ll> tree[MAXN];
ll dp[MAXN][2];
ll ans = -INF;
void dfs(ll u, ll dep, ll par) {
  dp[u][0] = dp[u][1] = val[u];
  for (auto v : tree[u]) {
    if (v != par) {
      dfs(v, dep + val[v], u);
      if (dp[v][0] + val[u] > dp[u][0]) {
        dp[u][1] = dp[u][0];
        dp[u][0] = dp[v][0] + val[u];
      } else if (dp[v][0] + val[u] > dp[u][1]) {
        dp[u][1] = dp[v][0] + val[u];
      }
    }
  }
  ans = max(ans, dp[u][0] + dp[u][1] - val[u]);
}
int main() {
  ll u, v;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  dfs(1, val[1], 0);
  cout << ans << endl;
  return 0;
}
