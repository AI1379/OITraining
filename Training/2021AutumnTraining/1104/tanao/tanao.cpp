#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;
const ll MAXT = 10010;
const ll MAXN = 10000010;
const ll INV2 = 499122177;
ll q[MAXT], t, maxn = 0;
ll ans[MAXN];
ll fact;
void solve(int n) {
  for (int i = 1; i <= n; i++) {
    ans[i] =
        ((ans[i - 1] * i % MOD) + (i * (i - 1) * INV2 % MOD * fact % MOD)) %
        MOD;
    fact = (fact * i) % MOD;
  }
}
int main() {
  cin >> t;
  fact = 1;
  for (int i = 1; i <= t; i++) {
    cin >> q[i];
    maxn = max(maxn, q[i]);
  }
#ifdef DEBUG
  cout << maxn << endl;
#endif
  solve(maxn);
  for (int i = 1; i <= t; i++) {
    cout << ans[q[i]] << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}
