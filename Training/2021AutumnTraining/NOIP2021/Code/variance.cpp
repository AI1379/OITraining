#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10010;
const ll MAXA = 610;
const ll INF = 0x3fffffffffffffff;
ll n;
ll a[MAXN], d[MAXN];
ll sum[MAXN];
ll dp[2][MAXN * MAXA];
ll maxj;
ll beg = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) d[i] = a[i + 1] - a[i];
  maxj = a[n] * n;
  n--;
  sort(d + 1, d + n + 1);
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0) beg++;
    sum[i] = sum[i - 1] + d[i];
  }
  ll x, y;
  for (int i = 1; i <= maxj; i++) dp[beg & 1][i] = INF;
  for (int i = beg + 1; i <= n; i++) {
    for (int j = 0; j <= maxj; j++) dp[i & 1][j] = INF;
    for (int j = 0; j <= maxj; j++) {
      if (dp[(i & 1) ^ 1][j] == INF) continue;
      x = dp[(i & 1) ^ 1][j] + sum[i] * sum[i];
      y = dp[(i & 1) ^ 1][j] + 2 * j * d[i] + d[i] * d[i] * i;
      dp[i & 1][j + sum[i]] = min(dp[i & 1][j + sum[i]], x);
      dp[i & 1][j + d[i] * i] = min(dp[i & 1][j + d[i] * i], y);
    }
  }
  ll ans = INF;
  maxj -= a[n + 1];
  for (int i = 0; i <= maxj; i++)
    if (dp[n & 1][i] != INF) ans = min(ans, dp[n & 1][i] * (n + 1) - i * i);
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}