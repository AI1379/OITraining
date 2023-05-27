#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a, m, ans;
int main() {
  m = ans = -(1ll << (sizeof(ll) * 8 - 2));
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    ans = max(ans, m - a);
    m = max(a, m);
  }
  cout << ans << endl;
  return 0;
}