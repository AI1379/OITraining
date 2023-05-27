#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
const ll INV2 = 499122177;
const ll INV6 = 166374059;
static ll n, res, a, b;
int main() {
#ifndef DEBUG
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
#endif
  scanf("%lld", &n);
  a = n * (n + 1) % MOD * (2 * n + 1) % MOD * INV6 % MOD;
  b = n * (n + 1) % MOD * INV2 % MOD;
  res = ((a - b) * INV2 % MOD + MOD) % MOD;
  printf("%lld\n", res);
  return 0;
}