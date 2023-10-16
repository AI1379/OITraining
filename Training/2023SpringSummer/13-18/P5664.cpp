#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 127;
const ll MAXM = 2047;
const ll MOD = 998244353;
ll n, m;
ll a[MAXN][MAXM];
ll s[MAXN];
ll dp[MAXN][MAXN * 2 + 1];
ll ans = 1;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      s[i] = (a[i][j] + s[i]) % MOD;
    }
    ans = ans * (s[i] + 1) % MOD;
  }
  ans = (ans - 1 + MOD) % MOD;
  for (int k = 1; k <= m; ++k) {
    memset(dp, 0, sizeof(dp));
    dp[0][n] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = n - i; j <= n + i; ++j) {
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * a[i][k] % MOD +
                    dp[i - 1][j + 1] * (s[i] - a[i][k] + MOD) % MOD) %
                   MOD;
      }
    }
    for (int i = 1; i <= n; ++i) {
      ans = (ans - dp[n][n + i] + MOD) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}