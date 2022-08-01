#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
int exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}
int eq(int a, int b, int c) {
  int x, y;
  int d = exgcd(a, b, x, y);
  if (c % d != 0) return 0;
  int k = c / d;
  x *= k;
  y *= k;
  return x;
}
int t;
ll n;
ll x[200010], y[200010], z[200010];
ll a[200010];
void solve() {
  scanf("%lld", n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
    x[i] %= MOD;
    y[i] %= MOD;
    z[i] %= MOD;
  }
  a[0] = 0;
  a[1] = 1;
  a[n] = eq(y[1], MOD, (z[1] - x[1] * a[1] % MOD + MOD) % MOD);
  for (int i = 2; i <= n - 1; i++) {
    a[i] = eq(x[i], MOD, (z[i] - y[i] * (a[n] - a[i - 1]) % MOD + MOD) % MOD);
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld ", a[i]);
  }
  printf("\n");
}
int main() {
  scanf("%d", &t);
  while (t--) {
    solve();
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}