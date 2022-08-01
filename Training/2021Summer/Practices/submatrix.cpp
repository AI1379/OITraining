#include <bits/stdc++.h>
using namespace std;
int n, m;
int mp[210][210];
int pre[210][210];
int add[210];
int dp[210];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mp[i][j];
      pre[i][j] = pre[i][j - 1] + mp[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    for (int j = i; j <= m; j++) {
      for (int k = 1; k <= n; k++) {
        dp[k] = 0;
        add[k] = pre[k][j] - pre[k][i];
      }
      for (int k = 1; k <= n; k++) {
        dp[k] = max(dp[k - 1] + add[k], dp[k]);
        ans = max(ans, dp[k]);
      }
    }
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}