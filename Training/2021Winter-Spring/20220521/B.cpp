#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 2e3 + 5;
const ll INF = 0x3f3f3f3f;
ll n;
ll a[MAXN];
ll dp[MAXN][2], ok[MAXN][2];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  a[0] = -INF;
  a[n + 1] = INF;
  for (int i = 1; i <= n; i++) {
    if (a[i + 1] - a[i] < a[i] - a[i - 1])
      ok[i][0] = 1;
    else
      ok[i][1] = 1;
  }
  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = min(dp[i - 1][0] + (!ok[i - 1][0]), dp[i - 1][1] + 1);
    dp[i][1] = min(dp[i - 1][1] + (!ok[i][1]), dp[i - 1][0] + 1);
  }
  cout << min(dp[n][0], dp[n][1]) << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}