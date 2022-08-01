#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
ll t;
ll n, c;
inline ll read() {
  ll s = 0;
  char ch = getchar();
  while (ch < '0' || ch > '1') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '1') s = s * 2 + ch - '0', ch = getchar();
  return s;
}
ll dp;
void solve() {
  ll len;
  n = read();
  cin >> c;
  dp = 0;
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    len = log2(i);
    if (((i * c) & ((1 << (len + 1)) - 1)) == i) dp = max(dp, i) % MOD;
    ans = (ans + dp) % MOD;
    // cout << dp << ' ';
  }
  // cout << endl;
  cout << ans << endl;
  return;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}