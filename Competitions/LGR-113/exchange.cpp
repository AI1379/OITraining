#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n;
ll a[MAXN];
ll pre[MAXN];
ll w;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> w;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }
  ll ans = upper_bound(pre + 1, pre + n + 1, min(w, a[n])) - pre - 1;
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}