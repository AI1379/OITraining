#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 510;
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
ll n;
ll dp[MAXN][MAXN];
ll pre[MAXN], a[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j <= i)
        dp[i][j] = 0;
      else
        dp[i][j] = INF;
    }
  }
  for (int k = 2; k <= n; ++k) {
    for (int i = 1, j; i + k - 1 <= n; ++i) {
      j = i + k - 1;
      for (int p = i; p <= j; ++p) {
        dp[i][j] = min(dp[i][j], max(pre[p - 1] - pre[i - 1] + dp[p + 1][j],
                                     dp[i][p - 1] + pre[j] - pre[p]));
      }
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}