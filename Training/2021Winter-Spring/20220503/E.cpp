#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
static constexpr const ll MAXN = 5010;
static ll n;
static ll a[MAXN];
static ll i = 0, mn = 0, s;
ll dfs(ll l, ll r) {
  mn = 0x7fffffffffffffff;
  s = l;
  for (i = l; i <= r; i++) {
    mn = min(a[i], mn);
  }
  for (i = l; i <= r; i++) {
    a[i] -= mn;
  }
  ll ans = mn;
  for (i = s; i <= r; i++) {
    if (a[i] == 0) {
      ans += dfs(s, i - 1);
      s = i + 1;
    }
  }
  if (s <= r) {
    ans += dfs(s, r);
  }
  return min(r - l + 1, ans);
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << dfs(1, n);
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}