#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, p;
ll ans = 1ll << (sizeof(ll) * 8 - 2);
ll calc(ll x) {}
int main() {
  cin >> n >> p;
  if (n < 100) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= 44; ++i) {
    ans = min(ans, calc(i));
  }
  return 0;
}