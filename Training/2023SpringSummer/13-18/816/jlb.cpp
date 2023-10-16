#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1010;
ll n, m;
ll a[MAXN];
ll dp[MAXN][MAXN];
int main() {
#ifndef DEBUG
  freopen("jlb.in", "r", stdin);
  freopen("jlb.out", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  memset(dp, 0x80, sizeof(dp));
  dp[1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 1; k < i; ++k) {
        dp[i][j] = max(dp[i][j], dp[k][j - 1] + abs(a[k] - a[i]));
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, dp[i][m]);
  }
  cout << ans << endl;
  return 0;
}