#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
const ll MAXN = 40;
const ll MAXM = 110;
ll n, m, k;
ll v[MAXM];
ll dp[MAXM][MAXM][MAXM][MAXM];
ll c[MAXM][MAXM];
ll vpow[MAXM][MAXM];
ll popcnt(ll x) {
  ll res = 0;
  while (x) {
    res += (x & 1);
    x >>= 1;
  }
  return res;
}
ll ans = 0;
int main() {
  cin >> n >> m >> k;
  m++;
  for (int i = 1; i <= m; i++) cin >> v[i];
  for (int i = 1; i <= m; i++) {
    vpow[i][0] = 1;
    for (int j = 1; j <= n; j++) {
      vpow[i][j] = vpow[i][j - 1] * v[i] % MOD;
    }
  }
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
  dp[0][0][0][0] = 1;
  ll tmp = 0;
  for (int i = 1; i <= m; i++) {            // 当前取i 2^i
    for (int j = 0; j <= n; j++) {          // 包括i已经填了j个
      for (int l = 0; l <= i; l++) {        // 到目前的S中有l个1 考虑i
        for (int p = 0; p <= j / 2; p++) {  // 进位数量为p
          for (int q = 0; q <= j; q++) {    // 填q个i <=> i位q个1
            tmp = 0;
            if (p * 2 - q >= 0) tmp += dp[i - 1][j - q][l][p * 2 - q];
            if (l >= 1 && p * 2 - q + 1 >= 0)
              tmp += dp[i - 1][j - q][l - 1][p * 2 - q + 1];
            tmp = tmp % MOD * c[n - j + q][q] % MOD * vpow[i][q] % MOD;
            dp[i][j][l][p] = (dp[i][j][l][p] + tmp) % MOD;
          }
        }
      }
    }
  }
  for (int l = 0; l <= m; l++) {
    for (int p = 0; p <= n / 2; p++) {
      if (l + popcnt(p) <= k) {
        ans = (ans + dp[m][n][l][p]) % MOD;
      }
    }
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}