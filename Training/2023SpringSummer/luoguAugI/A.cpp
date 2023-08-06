#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, t;
void solve() {
  cin >> a >> b;
  ll x = 0, y = 0;
  while (a || b) {
    if (a % 2 == 1 && b % 2 == 0)
      x = 1;
    if (a % 2 == 0 && b % 2 == 1)
      y = 1;
    a >>= 1;
    b >>= 1;
  }
  cout << x + y << endl;
}
int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}