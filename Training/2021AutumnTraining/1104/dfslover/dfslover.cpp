#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 8010;
const ll MOD = 998244353;
const ll INF = 0x3fffffffffffffff;
ll n;
ll a[MAXN];
ll premax[MAXN], submin[MAXN];
ll ans = 0;
bool check() {
  premax[0] = 0;
  submin[n + 1] = INF;
  for (int i = 1; i <= n; i++) premax[i] = max(premax[i - 1], a[i]);
  for (int i = n; i >= 1; i--) submin[i] = min(submin[i + 1], a[i]);
  for (int i = 1; i <= n; i++) {
    if (premax[i - 1] <= a[i] && a[i] <= submin[i + 1]) return false;
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  do {
    if (check()) {
      ans = (ans + 1) % MOD;
// #ifdef DEBUG
//       for (int i = 1; i <= n; i++) cout << a[i] << ' ';
//       cout << endl;
// #endif
    }
  } while (next_permutation(a + 1, a + n + 1));
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}