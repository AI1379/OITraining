#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll t;
ll n, m;
ll a[MAXN];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<ll>());
  ll ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] + a[i + 1] < m) {
      ans = i;
      break;
    }
  }
  if (ans == 0)
    ans = n;
  cout << ans << endl;
  return;
}
int main() {
  cin >> t;
  while (t--)
    solve();
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}