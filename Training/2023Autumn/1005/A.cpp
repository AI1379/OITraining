#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 210;
const ll MOD = 998244353;
ll n;
ll dp[MAXN * MAXN];
ll ans = 1;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
int main() {
  cin >> n;
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i * (i + 1) / 2; j >= i; --j) {
      dp[j] = (dp[j] + dp[j - i]) % (MOD - 1);
    }
  }
  for (int i = 1; i <= n * (n + 1) / 2; ++i) {
    ans = ans * qpow(i, dp[i]) % MOD;
  }
  cout << ans << endl;
  return 0;
}