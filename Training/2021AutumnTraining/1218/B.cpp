#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n;
ll w[MAXN];
ll dp[MAXN][2];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    dp[i][1] = dp[i - 1][0] + w[i];
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}