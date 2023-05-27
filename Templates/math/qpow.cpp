#include <bits/stdc++.h>
#include <complex>
using namespace std;
#define ll long long
ll qpow(ll x, ll y, ll m) {
  static ll res;
  res = 1;
  while (y) {
    if (y & 1)
      res = res * x % m;
    x = x * x % m;
    y >>= 1;
  }
  return res;
}
template <typename T = ll, typename Calc = multiplies<T>>
T binpow(T a, ll b, Calc calc) {
  T res;
  while (b) {
    if (b & 1)
      res = calc(res, a);
    a = calc(a, a);
    b >>= 1;
  }
  return res;
}
int main() { return 0; }