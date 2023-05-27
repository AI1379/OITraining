#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 310;
const ll MOD = 1e9 + 7;
ll n;
ll p[MAXN];
ll dp[MAXN][MAXN];
ll qpow(ll a, ll b) {
  static ll res;
  res = 1;
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
  for (int i = 1; i <= n - 1; ++i) {
    cin >> p[i];
  }

  return 0;
}