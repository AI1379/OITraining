#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 127;
const ll MAXM = 2047;
const ll MOD = 998244353;
ll n, m, k, mod;
ll mat[MAXN][MAXM], sum[MAXN][MAXM];
ll s1, s2;
ll seq[MAXN * MAXM];
ll dp[MAXN * MAXM], pre[MAXN * MAXM];
map<ll, ll> mp;
int main() {
#ifndef DEBUG
  freopen("feature.in", "r", stdin);
  freopen("feature.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
  cin >> n >> m >> k >> mod;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mat[i][j];
      sum[i][j] = ((((mat[i][j] + sum[i - 1][j]) % mod + sum[i][j - 1]) % mod -
                    sum[i - 1][j - 1]) %
                       mod +
                   mod) %
                  mod;
    }
  }
  for (int p = 0; p <= n; ++p) {
    for (int q = p + 1; q <= n; ++q) {
      mp = decltype(mp)();
      for (int i = 0; i <= m; ++i) {
        ++mp[((sum[p][i] - sum[q][i]) % mod + mod) % mod];
      }
      for (auto obj : mp) {
        if (obj.second >= 2) {
          s1 = (s1 + obj.second * (obj.second - 1) / 2) % MOD;
        }
      }
    }
  }
  if (k == 0) {
    cout << s1 + 1 << endl;
    return 0;
  }
  if (k == 1) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        seq[(i - 1) * m + j] = mat[i][j];
      }
    }
  } else if (k == 2) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (i % 2 == 1) {
          seq[(i - 1) * m + j] = mat[i][j];
        } else {
          seq[i * m - j + 1] = mat[i][j];
        }
      }
    }
  }
  dp[0] = 1;
  mp = decltype(mp)();
  for (int i = 1; i <= n * m; ++i) {
    if (mp[seq[i]])
      dp[i] = (dp[i - 1] * 2 % MOD - dp[mp[seq[i]] - 1]) % MOD;
    else
      dp[i] = dp[i - 1] * 2 % MOD;
    mp[seq[i]] = i;
  }
  s2 = dp[n * m];
  cout << s1 << ' ' << s2 << endl;
  cout << (s1 + s2) % MOD << endl;
  return 0;
}