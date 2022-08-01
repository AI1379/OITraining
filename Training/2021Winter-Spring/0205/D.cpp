#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXM = 10010;
const ll MAXT = 10010;
const ll MAXN = 210;
ll m, n, t;
ll v1[MAXT], w1[MAXT], v2[MAXT], w2[MAXT];
ll dp[MAXM];
int main() {
  cin >> m >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> v1[i] >> w1[i] >> v2[i] >> w2[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= min(w1[i], w2[i]); j--) {
      if (j >= w1[i]) dp[j] = max(dp[j], dp[j - w1[i]] + v1[i]);
      if (j >= w2[i]) dp[j] = max(dp[j], dp[j - w2[i]] + v2[i]);
    }
  }
  cout << dp[m] + t << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}