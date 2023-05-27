#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 5010;
ll n, m;
ll a[MAXN];
ll dp[MAXN][MAXN / 2];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i <= n; ++i) dp[i][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m && 2 * j <= i; ++j) {
      dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + a[i] - a[i - 1]);
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}