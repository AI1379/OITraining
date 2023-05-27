#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1023;
ll n, m, l, p;
bool mp[MAXN][MAXN];
ll dp[MAXN][MAXN];
ll maxf, maxpos, sndmax, sndmaxpos;
ll mindiff = 1ll << (sizeof(ll) * 8 - 2), ans = 0;
int main() {
#ifndef DEBUG
  freopen("jump.in", "r", stdin);
  freopen("jump.out", "w", stdout);
#endif
  ll x;
  cin >> n >> m >> l >> p;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> x;
      if (x) mp[i][j] = true;
    }
  }
  for (int i = m; i >= 1; --i) {
    maxf = maxpos = sndmax = sndmaxpos = 0;
    if (i + l < m) {
      for (int j = 1; j <= n; ++j) {
        if (dp[j][i + l] > maxf) {
          sndmax = maxf;
          sndmaxpos = maxpos;
          maxf = dp[j][i + l];
          maxpos = j;
        }
      }
    }
    for (int j = 1; j <= n; ++j) {
      if (j == maxpos)
        dp[j][i] = max(dp[j][i + 1], sndmax);
      else
        dp[j][i] = max(dp[j][i + 1], maxf);
      if (!mp[j][i]) ++dp[j][i];
    }
  }
  for (int i = m; i >= 1; --i) {
    for (int j = 1; j <= n; ++j) {
      if (abs(dp[j][i] - p) < mindiff) {
        mindiff = abs(dp[j][i] - p);
        ans = i;
      }
    }
  }
  --ans;
  cout << ans << endl;
  return 0;
}