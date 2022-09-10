#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n, m;
ll a[MAXN];
ll minp, maxp;
ll ans = 0;
void dfs(ll x, ll y, ll p) {
  if (x < y)
    swap(x, y);
  if (p > m) {
    ans = max(ans, x - y);
    // cout << x << ' ' << y << ' ' << ans << endl;
    return;
  }
  if (x > 0) {
    dfs(x * 2, y, p + 1);
    dfs(x + 2, y, p + 1);
  } else if (x == 0) {
    dfs(x + 2, y, p + 1);
  } else {
    dfs(x - 2, y, p + 1);
    dfs(x / 2, y, p + 1);
  }
  if (y > 0) {
    dfs(x, y / 2, p + 1);
    dfs(x, y - 2, p + 1);
  } else if (y == 0) {
    dfs(x, y - 2, p + 1);
  } else {
    dfs(x, y + 2, p + 1);
    dfs(x, y * 2, p + 1);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  minp = maxp = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > a[maxp])
      maxp = i;
    if (a[i] < a[minp])
      minp = i;
  }
  dfs(a[maxp], a[minp], 1);
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}