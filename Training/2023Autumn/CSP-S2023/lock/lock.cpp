#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10;
const ll pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
ll n;
map<ll, ll> avail;
ll next1(ll x, ll p) {
  ll cur = x / pow10[p] % 10;
  return x - cur * pow10[p] + ((cur + 1) % 10) * pow10[p];
}
ll next2(ll x, ll p) { return next1(next1(x, p), p + 1); }
int main() {
#ifndef DEBUG
  freopen("lock.in", "r", stdin);
  freopen("lock.out", "w", stdout);
#endif
  ll x, cur;
  ios::sync_with_stdio(false);
  cin >> n;
  if (n == 1) {
    cout << 81 << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    cur = 0;
    for (int d = 0; d < 5; ++d) {
      cin >> x;
      cur = cur * 10 + x;
    }
    for (int d = 0; d < 5; ++d) {
      x = next1(cur, d);
      while (x != cur) {
        ++avail[x];
        x = next1(x, d);
      }
      if (d == 4) continue;
      x = next2(cur, d);
      while (x != cur) {
        ++avail[x];
        x = next2(x, d);
      }
    }
  }
  ll ans = 0;
  for (auto tmp : avail) {
    if (tmp.second == n) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}