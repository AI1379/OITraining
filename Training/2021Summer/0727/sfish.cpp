#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
int main() {
#ifndef DEBUG
  freopen("sfish.in", "r", stdin);
  freopen("sfish.out", "w", stdout);
#endif
  ll tmp, ans;
  cin >> n;
  while (n--) {
    cin >> k;
    tmp = 1;
    ans = 0;
    while (k > 0) {
      if (k % 2 == 1) {
        ans += tmp;
      }
      tmp *= 3;
      k >>= 1;
    }
    cout << ans << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}