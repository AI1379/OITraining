#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10010;
const ll MAXP = 1300;
const ll MOD = 998244353;
ll n, k;
ll p[MAXN];
ll tab[MAXP][MAXN];
ll pri[MAXP], tot;
bool notprime[MAXN];
ll divk[MAXP], cnt;
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
void init(ll maxn) {
  for (int i = 2; i <= maxn; ++i) {
    if (!notprime[i])
      pri[++tot] = i;
    for (int j = 1; j <= tot; ++j) {
      if (1ll * pri[j] * i > maxn)
        break;
      notprime[pri[j] * i] = true;
      if (i % pri[j] == 0)
        break;
    }
  }
}
int main() {
  ll x = 0, idx = 1;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    x = max(x, p[i]);
  }
  init(x);
  for (int i = 1; i <= n; ++i) {
    idx = 1;
    x = p[i];
    while (x > 1 && idx <= tot) {
      while (x % pri[idx] == 0) {
        x /= pri[idx];
        ++tab[idx][i];
      }
      ++idx;
    }
  }
  x = k;
  idx = 1;
  while (x > 1 && idx <= tot) {
    while (x % pri[idx] == 0) {
      x /= pri[idx];
      ++divk[idx];
    }
    ++idx;
  }
  ll cur, ans = 1, res = 1;
  for (int i = 1; i <= tot; ++i) {
    cur = n + divk[i];
    res = 1;
    for (int j = 1; j <= n; ++j) {
      cur += tab[i][j];
      res = res * (tab[i][j] + 1) % MOD;
    }
    if (divk[i] != 0) {
      sort(tab[i] + 1, tab[i] + n + 1, greater<ll>());
      for (int j = 1; j <= n; ++j) {
        if ((tab[i][j] + 1) * (n - j + 1) > cur) {
          cur -= tab[i][j] + 1;
        } else {
          res = res * qpow(tab[i][j] + 1, MOD - 2) % MOD;
          res = res * (cur / (n - j + 1)) % MOD;
          cur -= cur / (n - j + 1);
        }
      }
    }
    ans = ans * res % MOD;
  }
  cout << ans << endl;
  return 0;
}
/**
3 60
8 243 250

2304
**/