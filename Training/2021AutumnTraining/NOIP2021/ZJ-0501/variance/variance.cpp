#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10010;
ll n;
ll a[MAXN];
ll sum, sq;
ll ans;
unordered_map<ll, bool> vis;
const ll BASE = 211;
const ll MOD = 998244353;
ll hsh = 0;
ll bpow[MAXN];
void dfs() {
  ll ori;
  for (int i = 2; i <= n - 1; i++) {
    if (2 * a[i] == a[i - 1] + a[i + 1]) continue;
    ori = hsh;
    hsh = (hsh - a[i] * bpow[n - i + 1] % MOD) % MOD;
    sum += (a[i - 1] + a[i + 1] - 2 * a[i]);
    sq += ((a[i - 1] + a[i + 1] - 2 * a[i]) * (a[i - 1] + a[i + 1]));
    a[i] = a[i - 1] + a[i + 1] - a[i];
    hsh = (hsh + a[i] * bpow[n - i + 1] % MOD) % MOD;
    hsh = (hsh + MOD) % MOD;
    if (!vis[hsh]) {
      vis[hsh] = true;
      ans = min(ans, n * sq - sum * sum);
      dfs();
    }
    a[i] = a[i - 1] + a[i + 1] - a[i];
    sum -= (a[i - 1] + a[i + 1] - 2 * a[i]);
    sq -= ((a[i - 1] + a[i + 1] - 2 * a[i]) * (a[i - 1] + a[i + 1]));
    hsh = ori;
  }
  return;
}
int main() {
#ifndef DEBUG
  freopen("variance.in", "r", stdin);
  freopen("variance.out", "w", stdout);
#endif
  scanf("%lld", &n);
  bpow[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    sum += a[i];
    sq += (a[i] * a[i]);
    hsh = (hsh * BASE + a[i]) % MOD;
    bpow[i] = bpow[i - 1] * BASE % MOD;
  }
  ans = n * sq - sum * sum;
  dfs();
  printf("%lld\n", ans);
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}