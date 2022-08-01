#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 2000010;
const ll MAXP = 150000;
ll t, n;
ll p, pri[MAXP];
bool vis[MAXN];
void init() {
  for (ll i = 2; i < MAXN; i++) {
    if (!vis[i]) {
      pri[++p] = i;
    }
    for (ll j = 1; j <= p; j++) {
      if (i * pri[j] > MAXN)
        break;
      vis[i * pri[j]] = true;
      if (i % pri[j] == 0)
        break;
    }
  }
}
void solve() {
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  ll ans = lower_bound(pri + 1, pri + p + 1, n) - pri;
  if (pri[ans] == n)
    cout << n << endl;
  else
    cout << pri[ans - 1] << endl;
  return;
}
int main() {
  init();
  cin >> t;
  while (t--)
    solve();
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}