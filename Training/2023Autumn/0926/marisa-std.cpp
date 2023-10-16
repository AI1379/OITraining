#include <bits/stdc++.h>
typedef long long LL;
const int MAXN = 40040;
const int MAXL = 22;
const LL MOD = 1e9 + 7;
LL dp[MAXL][MAXL], ans;
int n, a, b;
char A[MAXL], B[MAXL];
int main() {
#ifndef DEBUG
  freopen("marisa.in", "r", stdin);
  freopen("marisa.out", "w", stdout);
#endif
  scanf("%d%s%s", &n, A + 1, B + 1);
  a = strlen(A + 1);
  b = strlen(B + 1);
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = a; j >= 0; --j) {
      for (int k = b; k >= 0; --k) {
        if (j == a && k == b)
          dp[j][k] *= 26;
        else if (j == a || k == b || A[j + 1] == B[k + 1])
          dp[j][k] *= 25;
        else
          dp[j][k] *= 24;

        if (k && A[j + 1] != B[k])
          dp[j][k] += dp[j][k - 1];
        if (j && A[j] != B[k + 1])
          dp[j][k] += dp[j - 1][k];
        if (j && k && A[j] == B[k])
          dp[j][k] += dp[j - 1][k - 1];
        if (dp[j][k] >= MOD)
          dp[j][k] %= MOD;

        if (j == a && k < b)
          (ans += dp[j][k]) %= MOD;
      }
    }
  }
  ans %= MOD;
  printf("%lld\n", ans);
  return 0;
}
