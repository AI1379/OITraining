#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, m, c;
ll t[MAXN];
bool check(ll x) {
  ll st = -x, stn = 0, nm = 0;
  for (int i = 1; i <= n; i++) {
    if (t[i] - st > x || i - stn + 1 > c) {
      nm++;
      st = t[i];
      stn = i;
    }
  }
  return nm <= m;
}
int main() {
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  sort(t + 1, t + n + 1);
  ll l = 0, r = t[n] - t[1], mid, ans;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}