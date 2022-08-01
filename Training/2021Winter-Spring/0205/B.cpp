#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1010;
ll n;
ll mp[MAXN][MAXN];
ll dp[MAXN][MAXN];
int main() {
  scanf("%lld", &n);
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &mp[i][j]);
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + mp[i][j];
      if (i == j && i == 1) dp[i][j] = mp[i][j];
    }
  }
  printf("%lld\n", dp[n][n]);
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}