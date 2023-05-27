#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
ll a, b, c, d, g;
ll gcd(ll a, ll b) {
  if (a < b)
    swap(a, b);
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    g = gcd(a, b);
    if (d % gcd(c, g) == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}