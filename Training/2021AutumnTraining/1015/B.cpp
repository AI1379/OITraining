#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[2000010];
ll dp[2000010];
int main() {
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    a[n + i] = a[i];
  }
  ll ans = 0;
  ll cnt = 0;
  for (ll i = 1; i <= 2 * n; i++) {
    if (dp[i - 1] + a[i] - a[cnt] * (i - cnt >= n) > a[i]) {
      dp[i] = dp[i - 1] + a[i] - a[cnt] * (i - cnt >= n);
      cnt += (i - cnt >= n);
    } else {
      dp[i] = a[i];
      cnt = i;
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}