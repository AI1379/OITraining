#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll t;
ll n, r;
ll binpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void solve() {
  ll ans;
  ans = binpow(r, n + 1, MOD);
  ans = (ans - r * n % MOD - r + n) % MOD;
  while (ans < 0) {
    ans = (ans + MOD) % MOD;
  }
  ans = ans * n % MOD;
  ans = ans * binpow((r - 1) * (r - 1), MOD - 2, MOD) % MOD;
  cout << ans << endl;
  return;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> r >> n;
    solve();
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}