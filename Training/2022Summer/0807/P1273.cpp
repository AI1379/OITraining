#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll MAXN = 3010;
ll n, m;
ll val[MAXN];
vector<pll> tree[MAXN];
ll dp[MAXN][MAXN];
ll dfs(ll u) {
  if (u > n - m) {
    dp[u][1] = val[u];
    return 1;
  }
  ll res = 0, v, w, s;
  for (pll obj : tree[u]) {
    v = obj.first;
    w = obj.second;
    s = dfs(v);
    res += s;
    for (int i = res; i > 0; --i) {
      for (int j = 1; j <= s && i >= j; ++j) {
        dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j] - w);
      }
    }
  }
  return res;
}
int main() {
  ll k, a, c;
  memset(dp, ~0x3f, sizeof(dp));
  cin >> n >> m;
  for (int i = 1; i <= n - m; i++) {
    cin >> k;
    for (int j = 1; j <= k; j++) {
      cin >> a >> c;
      tree[i].emplace_back(make_pair(a, c));
    }
  }
  for (int i = n - m + 1; i <= n; i++) {
    cin >> val[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 0;
  }
  dfs(1);
  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    if (dp[1][i] >= 0) {
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
