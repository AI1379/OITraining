#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define ll int
constexpr ll MAXM = 11;
constexpr ll MAXN = 110;
constexpr ll kPow3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441};
ll n, m;
bool mp[MAXN][MAXM];
string str;
ll num[kPow3[MAXM]];
ll dp[MAXN][kPow3[MAXM]];
ll getCol(ll x, ll c) {
  return (x / kPow3[c - 1]) % 3;
}
ll ans = 0;
inline void dfs(ll now, ll pre, ll p, ll r, ll last2) {
  if (p > m) {
    dp[r][now] = max(dp[r][now], dp[r - 1][pre] + num[now]);
    if (r == n) {
      ans = max(ans, dp[r][now]);
    }
    return;
  }
  if (getCol(pre, p) == 2) {
    now += kPow3[p - 1];
    dfs(now, pre, p + 1, r, last2);
  } else if (getCol(pre, p) == 1) {
    dfs(now, pre, p + 1, r, last2);
  } else {
    dfs(now, pre, p + 1, r, last2);
    if (mp[r][p] && last2 + 2 < p) {
      now += 2 * kPow3[p - 1];
      dfs(now, pre, p + 1, r, p);
    }
  }
}
ll to3(ll x) {
  ll res = 0;
  while (x) {
    res *= 3;
    res += x % 10;
    x /= 10;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= kPow3[m]; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((i / kPow3[j]) % 3 == 2) {
        ++num[i];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> str;
    for (int j = 0; j < m; ++j) {
      mp[i][j + 1] = (str[j] == 'P');
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < kPow3[m]; ++j) {
      if (dp[i - 1][j] != -1) {
        dfs(0, j, 1, i, -2);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
