#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MAXV = 1000000;
ll n;
ll val[MAXN];
ll ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  sort(val + 1, val + n + 1);
  for (int i = 0; i <= 5; ++i) {
    ans = max(ans, (ll)(lower_bound(val + 1, val + n + 1, (i + 1) * MAXV) -
                        lower_bound(val + 1, val + n + 1, i)));
    cout << lower_bound(val + 1, val + n + 1, i) - val << ' '
         << lower_bound(val + 1, val + n + 1, (i + 1) * MAXV) - val << ' ' << i
         << ' ' << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
