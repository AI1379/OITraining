#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
ll a, b, m, n;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
ll f1, f2, f3;
int main() {
#ifndef DEBUG
  freopen("fat.in", "r", stdin);
  freopen("fat.out", "w", stdout);
#endif
  cin >> a >> b >> m >> n;
  f1 = f2 = f3 = 1;
  for (int i = 3; i <= n; ++i) {
    f3 = (a * f1 % (MOD - 1) + b * f2 % (MOD - 1)) % (MOD - 1);
    f1 = f2;
    f2 = f3;
  }
  cout << qpow(m, f3) << endl;
  return 0;
}