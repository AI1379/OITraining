#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 510;
const ll MAXM = 200010;
ll n, m, t;
ll a[MAXN], b[MAXN];
ll ans = 0x3fffffffffffffff;
void dfs(ll p, ll l, ll cur) {
  if (l == 0) {
    ans = min(ans, cur);
    return;
  }
  if (p > n) {
    return;
  }
  for (ll i = 0; i <= l; i++) {
    dfs(p + 1, l - i,
        cur + t * (ll)(i != 0) + i * a[p] +
            b[p] * i * (i - 1) * (2 * i - 1) / 6);
  }
}
int main() {
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  dfs(1, m, 0);
  cout << ans - t << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}