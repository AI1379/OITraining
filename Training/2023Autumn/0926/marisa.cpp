#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 40010;
const ll MAXS = 31;
const ll MOD = 1000000007;
ll n;
ll inv[MAXN], fact[MAXN], factinv[MAXN], pow26[MAXN];
ll dp[MAXN][MAXS][MAXS];
ll dp2[MAXN][MAXS];
char a[MAXS], b[MAXS];
ll s, t;
ll qpow(ll x, ll y) {
  static ll res;
  res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
void init() {
  pow26[0] = fact[0] = fact[1] = factinv[0] = factinv[1] = inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    fact[i] = fact[i - 1] * i % MOD;
    factinv[i] = factinv[i - 1] * inv[i] % MOD;
  }
  for (int i = 1; i <= n; ++i) {
    pow26[i] = pow26[i - 1] * 26 % MOD;
  }
}
ll comb(ll x, ll y) {
  return fact[x] * factinv[x - y] % MOD * factinv[y] % MOD;
}
ll calc(ll x, ll y) {
  ll res = 0;
  for (int j = 0; j <= x - y; ++j) {
    res = (res + comb(x, j + y) * qpow(25, x - y - j) % MOD) % MOD;
  }
  return res;
}
int main() {
#ifndef DEBUG
  freopen("marisa.in", "r", stdin);
  freopen("marisa.out", "w", stdout);
#endif
  scanf("%lld", &n);
  scanf("%s%s", a + 1, b + 1);
  init();
  for (int i = 4; i <= 7; ++i) {
    cout << calc(7, i) << endl;
  }
  s = strlen(a + 1);
  t = strlen(b + 1);
  dp[0][0][0] = 1;
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= s && i <= k; ++i) {
      dp[k][0][i] = dp[k][i][0] = comb(k, i);
      // cout << k << ' ' << i << ' ' << dp[k][i][0] << endl;
    }
    for (int i = 1; i <= s && i <= k; ++i) {
      for (int j = 1; j <= t && j <= k; ++j) {
        if (a[i] == b[j]) {
          dp[k][i][j] =
              (dp[k - 1][i][j] * 25 % MOD + dp[k - 1][i - 1][j - 1]) % MOD;
        } else {
          dp[k][i][j] = (dp[k - 1][i][j] * 24 % MOD + dp[k - 1][i - 1][j] +
                         dp[k - 1][i][j - 1]) %
                        MOD;
        }
        // cout << k << ' ' << i << ' ' << j << ' ' << dp[k][i][j] << endl;
      }
    }
  }
  dp2[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp2[i][0] = qpow(26, i);
    for (int j = 1; j <= s; ++j) {
      dp2[i][j] = (dp2[i - 1][j] * 25 + dp2[i - 1][j - 1]) % MOD;
    }
  }
  // printf("%lld\n", dp2[n][s]);
  printf("%lld\n", (dp2[n][s] - dp[n][s][t] + MOD) % MOD);
  ll ans = (calc(n, s) - dp[n][s][t] + MOD) % MOD;
  cout << ans << endl;
  return 0;
}