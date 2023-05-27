#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 511;
const ll MAXT = 63;
ll n, m;
ll num[7];
ll val[MAXN];
ll dp[MAXT][MAXT][MAXT][MAXT];
int main() {
  ll x;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> val[i];
  for (int i = 1; i <= m; ++i) {
    cin >> x;
    ++num[x];
  }
  dp[0][0][0][0] = val[1];
  for (int a = 0; a <= num[1]; ++a) {
    for (int b = 0; b <= num[2]; ++b) {
      for (int c = 0; c <= num[3]; ++c) {
        for (int d = 0; d <= num[4]; ++d) {
          x = 1 + a + b * 2 + c * 3 + d * 4;
          if (a != 0)
            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + val[x]);
          if (b != 0)
            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + val[x]);
          if (c != 0)
            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + val[x]);
          if (d != 0)
            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + val[x]);
        }
      }
    }
  }
  cout << dp[num[1]][num[2]][num[3]][num[4]] << endl;
  return 0;
}