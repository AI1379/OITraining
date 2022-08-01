#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[2010];
int dp[2010][2010][2];
// dp[i][j][0/1]: 前i+1个 能取j个 第i个取/不取的ans
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j][1] = dp[i - 1][j - 1][0] + min(a[i - 1], a[i + 1]) - 1;
      dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
    }
    ans = max(ans, max(dp[i][k][0], dp[i][k][1]));
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}