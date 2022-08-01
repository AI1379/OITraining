#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n, f;
ll a[MAXN];
ll pre[MAXN];
bool check(ll x) {
  for (int i = 0; i + x <= n; i++)
    if (pre[i + x] - pre[i] <= f) return true;
  return false;
}
int main() {
  cin >> n >> f;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  ll l = 0, r = n, mid;
  ll ans = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}