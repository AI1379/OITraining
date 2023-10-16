#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll tab[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
ll ans = 0;
void dfs(ll a, ll b, ll pos) {
  if (a / tab[pos] == 0 && b / tab[pos] == 0) {
    ans = max(ans, a * b);
    return;
  }
  ll x = a / tab[pos] % 10, y = b / tab[pos] % 10;
  dfs(a, b, pos + 1);
  dfs(a - x * tab[pos] + y * tab[pos], b - y * tab[pos] + x * tab[pos],
      pos + 1);
}
int main() {
  ll a, b;
#ifndef DEBUG
  freopen("T2.in", "r", stdin);
  freopen("T2.out", "w", stdout);
#endif
  cin >> a >> b;
  dfs(a, b, 0);
  cout << ans << endl;
  return 0;
}
