#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (1ll << (sizeof(ll) * 8 - 2))
#define DELTA 128ll
static ll a, b, c, d;
static ll ans = INF;
bool check(ll w, ll x, ll y, ll z) {
  static ll la, lb, lc, ld;
  la = w + x / 2 + y / 2 + z / 4;
  lb = x + w / 2 + z / 2 + y / 4;
  lc = y + w / 2 + z / 2 + x / 4;
  ld = z + x / 2 + y / 2 + w / 4;
  return la >= a && lb >= b && lc >= c && ld >= d;
}
ll calc(ll w, ll y) {
  static ll x, z, k1, k2, res;
  res = INF;
  k1 = max(2 * w + y - 4 * b, 8 * w + 4 * y - 8 * a);
  k2 = max(2 * y + w - 4 * d, 8 * y + 4 * w - 8 * c);
  x = max((k2 - 2 * k1) / 6, 0ll);
  z = max((k1 - 2 * k2) / 6, 0ll);
  for (ll dx = max(-x, -DELTA); dx <= DELTA; ++dx) {
    for (ll dz = max(-z, -DELTA); dz <= DELTA; ++dz) {
      if (check(w, x + dx, y, z + dz)) {
        res = min(res, w + x + y + z + dx + dz);
      }
    }
  }
  return res;
}
int main() {
  cin >> a >> b >> c >> d;
  ll l = 0, r = a + b + c + d;
  // ll l = 4 * (a + b + c + d) / 9, r = 5 * (a + b + c + d) / 9;
  for (ll w = l; w <= r; ++w) {
    for (ll y = l; y <= r && w + y <= r; ++y) {
      ans = min(ans, calc(w, y));
    }
  }
  cout << ans << endl;
  return 0;
}