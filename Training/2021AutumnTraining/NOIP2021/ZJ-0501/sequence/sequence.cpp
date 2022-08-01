#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 40;
const ll MAXM = 110;
const ll MOD = 998244353;
ll n, m, k;
ll v[MAXM];
ll num[MAXM + 5];
ll ans = 0;
ll qpow(ll a, ll b, ll p) {
  a %= p;
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}
ll calc(ll a, ll b) {
  if (a == b || a * b == 0) return 1;
  ll x = 1, y = 1;
  for (int i = a; i >= a - b + 1; i--) x = x * i % MOD;
  for (int i = b; i >= 1; i--) y = y * i % MOD;
  ll res = x * qpow(y, MOD - 2, MOD) % MOD;
  return res;
}
ll dfs(ll x, ll dep, ll mx) {
  ll res = 0;
  if (dep == n) {
    res = 1;
    ll sol = 1, tmp = n;
    for (int i = 0; i <= m; i++) {
      res = res * qpow(v[i], num[i], MOD) % MOD;
      sol = sol * calc(tmp, num[i]);
      tmp -= num[i];
    }
    return res * sol % MOD;
  }
  if (x <= 0 || dep > n) return 0;
  ll cnt = 0;
  if (x > m) {
    ll ori = num[x];
    num[x - 1] += 2 * num[x];
    num[x] = 0;
    res = dfs(x - 1, dep + ori, mx - 1) % MOD;
    num[x] = ori;
    num[x - 1] -= ori * 2;
  } else {
    res = dfs(x - 1, dep, mx) % MOD;
    while (num[x]) {
      num[x]--;
      num[x - 1] += 2;
      cnt++;
      if (dep + cnt > n) break;
      res = (res + dfs(x - 1, dep + cnt, mx - (num[x] == 0))) % MOD;
    }
    num[x] += cnt;
    num[x - 1] -= cnt * 2;
  }
  return res;
}
// val s
ll solve(ll x) {
  ll tmp = x;
  ll cnt = 0, count = 0;
  memset(num, 0, sizeof(num));
  while (tmp) {
    if (tmp & 1) {
      num[cnt]++;
      count++;
    }
    tmp >>= 1;
    cnt++;
  }
  if (count > n || count > k) return 0ll;
  ll res = 0;
  res = dfs((ll)(log2(x)), count, (ll)(log2(x)));
  return res;
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  for (int i = 0; i <= m; i++) scanf("%lld", v + i);
  for (int i = n; i <= (n << m); i++) {
    ans = (ans + solve(i)) % MOD;
  }
  printf("%lld\n", ans);
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}