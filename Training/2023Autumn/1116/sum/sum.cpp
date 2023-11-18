#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 511;
const ll INF = 1e9;
ll n;
ll mp[MAXN][MAXN];
ll dp[MAXN][MAXN];
ll ans = 0;
int main() {
  freopen("sum.in", "r", stdin);
  freopen("sum.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> mp[i][j];
      mp[i][j] = (mp[i][j] == -1 ? INF : mp[i][j]);
    }
  }
  for (int b = 1; b <= n; ++b) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = (i == b || j == b ? INF : mp[i][j]);
      }
    }
    for (int k = 1; k <= n; ++k) {
      if (k == b)
        continue;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
    // cout << b << endl;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        // cout << (dp[i][j] >= INF ? -1 : dp[i][j]) << ' ';
        if (i == b || j == b)
          continue;
        if (dp[i][j] < INF)
          ans += dp[i][j];
        else
          --ans;
      }
      // cout << endl;
    }
  }
  cout << ans << endl;
  return 0;
}