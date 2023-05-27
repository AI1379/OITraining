#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, c, d;
bool judge(ll tot) {
  static ll w, x, y, z, need, aprx, cur;
  for (w = 0; w <= a; ++w) {
    for (z = 0; z <= d; ++z) {
      need = max(a - w - z / 4, d - z - w / 4);
      if ((tot - w - z) / 2 < need)
        continue;
      cur = tot - w - z;
      x = max(0ll, b - w / 2 - z / 2);
      y = max(0ll, c - w / 2 - z / 2);
      aprx = max(0ll, (x - cur / 4) * 4 / 3);
      for (ll k = max(0ll, aprx - 5); k <= min(aprx + 5, cur); ++k) {
        if (k + (cur - k) / 4 >= x && k / 4 + cur - k >= y) {
          return true;
        }
      }
    }
  }
  return false;
}
int main() {
  cin >> a >> b >> c >> d;
  ll l = 0, r = a + b + c + d, mid, ans = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (judge(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}