#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a;
map<ll, ll> mp;
ll pr[100010];
ll num[100010];
bool vis[100010];
ll tot = 0;
int main() {
  ll x, y, cube = 0;
  cin >> n;
  for (ll k = 1; k <= n; k++) {
    cin >> a;
    x = a;
    y = 1;
    for (ll i = 2; i * i <= a; i++) {
      while (x % (i * i * i) == 0) {
        a /= (i * i * i);
        x /= (i * i * i);
      }
      if (a % (i * i) == 0) {
        a /= (i * i);
        y *= i;
      }
      if (a % i == 0) {
        a /= i;
        y *= (i * i);
      }
    }
    if (a > 1) y *= (a * a);
    if (x == 1) {
      cube = 1;
      continue;
    }

    if (!mp[x]) {
      num[++tot] = 1;
      mp[x] = tot;
    } else {
      num[mp[x]]++;
    }
    if (!mp[y]) {
      mp[y] = ++tot;
    }
    pr[mp[x]] = mp[y];
  }
  ll ans = 0;
  for (ll i = 1; i <= tot; i++) {
    if (!vis[i]) {
      ans += max(num[i], num[pr[i]]);
      vis[i] = true;
      vis[pr[i]] = true;
    }
  }

  cout << ans + cube << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}