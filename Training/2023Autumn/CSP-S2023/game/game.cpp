#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 8010;
ll n;
char s[MAXN];
bool dp[MAXN][MAXN];
ll ans = 0;
int main() {
#ifndef DEBUG
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
#endif
  scanf("%lld", &n);
  scanf("%s", s + 1);
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
      for (int d = l; d + 1 <= r; ++d) {
        if (dp[l][d] && dp[d + 1][r]) {
          dp[l][r] = true;
          break;
        }
      }
      if (s[l] == s[r] && (r == l + 1 || dp[l + 1][r - 1])) {
        dp[l][r] = true;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      if (dp[i][j]) {
        ++ans;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}