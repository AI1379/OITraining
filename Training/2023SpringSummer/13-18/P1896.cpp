#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10;
ll n, k;
ll dp[MAXN][1 << MAXN][MAXN * MAXN];
ll cnt;
ll popcnt(ll x) { return __builtin_popcount(x); }
int main() {
  cin >> n >> k;
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (mask & (mask << 1))
        continue;
      cnt = popcnt(mask);
      for (int mask2 = 0; mask2 < (1 << n); ++mask2) {
        if ((mask & mask2) || (mask & (mask2 << 1)) || mask & (mask2 >> 1))
          continue;
        for (int j = cnt; j <= k; ++j) {
          dp[i][mask][j] += dp[i - 1][mask2][j - cnt];
        }
      }
    }
  }
  cnt = 0;
  for (int mask = 0; mask < (1 << n); ++mask)
    cnt += dp[n][mask][k];
  cout << cnt << endl;
  return 0;
}