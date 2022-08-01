#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
const ll MOD = 1e9 + 7;
const ll INV2 = 50000004;
ll n;
ll s[MAXN];
ll ans = 0, pow2 = 1;
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &s[i]);
  sort(s + 1, s + n + 1);
  for (int i = 1; i <= n; i++) {
    ans = ((ans + s[i] * (pow2 - 1) % MOD) % MOD + MOD) % MOD;
    pow2 = pow2 * 2 % MOD;
  }
  pow2 = 1;
  sort(s + 1, s + n + 1, greater<int>());
  for (int i = 1; i <= n; i++) {
    ans = ((ans - s[i] * (pow2 - 1) % MOD) % MOD + MOD) % MOD;
    pow2 = pow2 * 2 % MOD;
  }
  printf("%lld\n", ans);
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}