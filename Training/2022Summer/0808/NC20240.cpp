// https://ac.nowcoder.com/acm/problem/20240
// https://www.luogu.com.cn/problem/P1896
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
const ll MAXN = 11;
const ll MAXK = 100;
ll n, k;
ll num[(1 << MAXN)];
ll dp[MAXN][MAXK][(1 << MAXN)];
#define check(x,y)                       \
        ((((x) & ((x) << 1)) == 0)       \
        && (((y) & ((y) << 1)) == 0)     \
        && (((x) & (y)) == 0)            \
        && (((x) & (y << 1)) == 0)       \
        && (((x) & (y >> 1)) == 0))
int main() {
  cin >> n >> k;
  for (int st = 0; st < (1 << n); ++st) {
    for (int p = 0; p < n; ++p) {
      if ((st & (1 << p)) != 0) {
        ++num[st];
      }
    }
    if ((st & (st << 1)) == 0) {
      ++dp[1][num[st]][st];
    }
  }
  dp[1][0][0] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i][0][0] = 1;
    for (int j = 1; j <= k; ++j) {
      for (int st = 0; st < (1 << n); ++st) {
        for (int p = 0; p < (1 << n); ++p) {
          if (check(st, p)) {
            dp[i][j][st] += dp[i - 1][j - num[st]][p];
          }
        }
      }
    }
  }
  ll ans = 0;
  for (int st = 0; st < (1 << n); ++st) {
    if ((st & (st << 1)) == 0) {
      ans += dp[n][k][st];
    }
  }
  cout << ans << endl;
  return 0;
}
