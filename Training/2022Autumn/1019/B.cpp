#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MAXA = 1010;
ll n;
ll times[MAXA];
ll x, k;
ll maxa;
ll ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    ++times[x];
    maxa = max(maxa, x);
  }
  k = times[0];
  for (int i = 0; i <= maxa + 1; ++i) {
    ans += max(k - times[i], 0ll) * i;
    k = min(k, times[i]);
    if (k == 0) break;
  }
  cout << ans << endl;
  return 0;
}