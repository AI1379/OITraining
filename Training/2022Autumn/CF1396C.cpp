#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n, r1, r2, r3, d;
ll val[MAXN];
ll dp[MAXN];
int main() {
  cin >> n >> r1 >> r2 >> r3 >> d;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i <= n; ++i) {
    dp[i + 1] = min(dp[i + 1], dp[i] + val[i + 1] * r1 + r3 + d);
    dp[i + 1] =
        min(dp[i + 1], dp[i] + min((val[i + 1] + 1) * r1, r2) + d + d + r1 + d);
    dp[i + 2] = min(dp[i + 2], dp[i] + min((val[i + 1] + 1) * r1, r2) + d +
                                   min((val[i + 2] + 1) * r1, r2) + d + r1 + d +
                                   r1 + d);
  }
  cout << min(dp[n] - d, dp[n - 2] + min((val[n - 1] + 1) * r1, r2) + d +
                             val[n] * r1 + r3 + d + r1)
       << endl;
  return 0;
}