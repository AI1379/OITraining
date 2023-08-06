#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1023;
const ll MOD = 1000000007;
const ll dx[] = {0, 0, 1, 2};
const ll dy[] = {1, 2, 0, 0};
char s[MAXN];
ll n;
ll dp[MAXN][MAXN][3][3];
ll match[MAXN];
void dfs(ll l, ll r) {
  if (l + 1 == r) {
    dp[l][r][0][1] = dp[l][r][0][2] = dp[l][r][1][0] = dp[l][r][2][0] = 1;
  } else if (match[l] == r) {
    dfs(l + 1, r - 1);
    for (int i = 0; i <= 2; ++i) {
      for (int j = 0; j <= 2; ++j) {
        for (int k = 0; k < 4; ++k) {
          if ((dx[k] == i && i != 0) || (j == dy[k] && j != 0))
            continue;
          dp[l][r][dx[k]][dy[k]] =
              (dp[l][r][dx[k]][dy[k]] + dp[l + 1][r - 1][i][j]) % MOD;
        }
      }
    }
  } else {
    dfs(l, match[l]);
    dfs(match[l] + 1, r);
#define C dp[l][r]
#define CL dp[l][match[l]]
#define CR dp[match[l] + 1][r]
    for (int i = 0; i <= 2; ++i) {
      for (int j = 0; j <= 2; ++j) { // C[i][j]
        for (int p = 0; p <= 2; ++p) {
          for (int q = 0; q <= 2; ++q) {
            if (p == q && p != 0)
              continue;
            C[i][j] = (CL[i][p] * CR[q][j] % MOD + C[i][j]) % MOD;
          }
        }
      }
    }
#undef C
#undef CL
#undef CR
  }
}
ll stk[MAXN], top = 0;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') {
      stk[++top] = i;
    } else {
      match[stk[top--]] = i;
    }
  }
  dfs(1, n);
  ll ans = 0;
  for (int i = 0; i <= 2; ++i)
    for (int j = 0; j <= 2; ++j)
      ans = (ans + dp[1][n][i][j]) % MOD;
  printf("%lld\n", ans);
  return 0;
}