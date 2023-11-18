#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 63;
ll n;
char s[MAXN];
ll dp[MAXN][MAXN];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    dp[i][i] = 1;
  }
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
      dp[l][r] = 1e9;
      if (s[l] == s[r]) {
        dp[l][r] = min(dp[l][r - 1], dp[l + 1][r]);
      } else {
        for (int k = l; k + 1 <= r; ++k) {
          dp[l][r] = min(dp[l][k] + dp[k + 1][r], dp[l][r]);
        }
      }
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}