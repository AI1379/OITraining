#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 127;
ll n;
ll val[MAXN];
char sym[MAXN];
ll dp[MAXN][MAXN], dpm[MAXN][MAXN];
int main() {
  ll ans = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> sym[i] >> val[i];
    sym[n + i] = sym[i];
    val[n + i] = val[i];
  }
  memset(dp, 0x80, sizeof(dp));
  memset(dpm, 0x7f, sizeof(dpm));
  for (int i = 1; i <= n * 2; ++i) {
    dp[i][i] = dpm[i][i] = val[i];
    // cout << i << ' ' << i << ' ' << dp[i][i] << endl;
  }
  // cout << endl;
  for (int diff = 2; diff <= n; ++diff) {
    for (int i = 1, j = i + diff - 1; j <= n * 2; ++i, ++j) {
      for (int k = i; k + 1 <= j; ++k) {
        if (sym[k + 1] == 't') {
          dp[i][j] = max(dp[i][k] + dp[k + 1][j], dp[i][j]);
          dpm[i][j] = min(dpm[i][k] + dpm[k + 1][j], dpm[i][j]);
        } else {
          auto f = max(max(dp[i][k] * dp[k + 1][j], dpm[i][k] * dpm[k + 1][j]),
                       max(dpm[i][k] * dp[k + 1][j], dp[i][k] * dpm[k + 1][j]));
          auto g = min(min(dp[i][k] * dp[k + 1][j], dpm[i][k] * dpm[k + 1][j]),
                       min(dpm[i][k] * dp[k + 1][j], dp[i][k] * dpm[k + 1][j]));
          dp[i][j] = max(dp[i][j], f);
          dpm[i][j] = min(dpm[i][j], g);
        }
        // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
      }
      // cout << endl;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, dp[i][i + n - 1]);
    // cout << dp[i][i + n - 1] << ' ' << ans << endl;
  }
  cout << ans << endl;
  for (int i = 1; i <= n; ++i) {
    if (ans == dp[i][i + n - 1])
      cout << i << ' ';
  }
  cout << endl;
  return 0;
}