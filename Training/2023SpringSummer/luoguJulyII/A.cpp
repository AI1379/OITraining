#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll popcnt(ll x) {
  ll res = 0;
  while (x) {
    res += x % 2;
    x /= 2;
  }
  return res;
}
ll lowbit(ll x) { return x & (-x); }
ll t, x, p;
int main() {
  cin >> t;
  while (t--) {
    cin >> x;
    p = popcnt(x);
    if (p >= 3) {
      cout << "No,Commander" << endl;
    } else if (p == 1) {
      cout << x + 1 << endl;
    } else {
      cout << x + lowbit(x) << endl;
    }
  }
  return 0;
}