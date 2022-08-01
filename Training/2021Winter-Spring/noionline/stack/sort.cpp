#include <iostream>
#include <map>
#include <utility>
using namespace std;
#define ll long long
const ll MAXM = 8;
const ll MAXN = 200010;
ll m, n;
ll a[MAXM][MAXN];
ll ans = 0;
int main() {
#ifndef DEBUG
#ifndef VSCODE
  freopen("sort.in", "r", stdin);
  freopen("sort.out", "w", stdout);
#endif
#endif
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (m == 2) {
        ans += a[i][j];
      }
    }
  }
  if (m == 2) {
    cout << ans * 2 * n << endl;
#ifdef VSCODE
    system("pause");
#endif
    return 0;
  }
  ll mn, mx;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      mn = 0x3fffffffffffffff;
      mx = 0;
      for (int k = 1; k <= m; k++) {
        mn = min(a[k][i] + a[k][j], mn);
        mx = max(a[k][i] + a[k][j], mx);
      }
      ans += (mn + mx);
    }
  }
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}