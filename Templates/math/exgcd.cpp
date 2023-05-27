#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll g = exgcd(b, a % b, x, y), t;
  t = x;
  x = y;
  y = t - a / b * y;
  return g;
}
int main() { return 0; }