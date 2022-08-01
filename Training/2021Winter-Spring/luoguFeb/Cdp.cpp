#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 510;
const ll MAXM = 200010;
ll n, m, t;
ll a[MAXN], b[MAXN];
ll dp[MAXM];
int main() {
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      for (int p = j; p >= 0; p--) {
        dp[j] = min(dp[j], dp[j - p] + t * (ll)(p != 0) + a[i] * p +
                               b[i] * p * (p - 1) * (2 * p - 1) / 6);
      }
    }
  }
  cout << dp[m] - t << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}