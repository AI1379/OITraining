#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 300010;
const ll MOD = 998244353;
ll n;
char seq[MAXN];
ll ans;
ll l, r, cnt;
int main() {
#ifndef DEBUG
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
#endif
  scanf("%lld", &n);
  scanf("%s", seq + 1);
  for (int i = 1; i <= n - 1; ++i)
    if (seq[i] == '1' && seq[i + 1] == '1') goto output;
  ans = 1;
  l = 1;
  r = n;
  cnt = 0;
  while (seq[l] == '0') ++l;
  while (seq[r] == '0') --r;
  if (l > r) {
    ans = (n % 2 == 0 && n > 2) ? (n / 2 + 1) : 1;
    goto output;
  }
  ans = ans * (((l - 1) % 2 != 0 && (l - 1) > 1) ? (l / 2) : 1) % MOD;
  ans = ans * (((n - r) % 2 != 0 && (n - r) > 1) ? ((n - r + 1) / 2) : 1) % MOD;
  for (int i = l; i <= r; ++i) {
    if (seq[i] == '1') {
      ans = ans * ((cnt % 2 == 0 && cnt > 2) ? (cnt / 2) : 1) % MOD;
      cnt = 0;
    } else {
      ++cnt;
    }
  }
output:
  printf("%lld\n", ans);
  return 0;
}