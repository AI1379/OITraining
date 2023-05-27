#include <iostream>
using namespace std;
#define ll long long
ll qpow(ll a, ll b, ll m) {
  static ll res;
  res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
constexpr const ll kMillerRobinBase[] = {2,      325,     9375,      28178,
                                         450775, 9780504, 1795265022};
bool millerRabin(ll n) {
  if (n < 3 || n % 2 == 0)
    return n == 2;
  static ll a = n - 1, b = 0, base, val, idx, i;
  while (a % 2 == 0) {
    a >>= 1;
    ++b;
  }
  for (idx = 0; idx < 7; ++idx) {
    base = kMillerRobinBase[idx];
    val = qpow(base, a, n);
    if (val <= 1 || val == n - 1)
      continue;
    for (i = 0; i < b; ++i) {
      if (val == n - 1)
        break;
      val = val * val % n;
    }
    if (i >= b) {
      return false;
    }
  }
  return true;
}
ll n;
int main() {
  cin >> n;
  if (millerRabin(n)) {
    cout << "0" << endl;
  } else {
    cout << "1" << endl;
  }
  return 0;
}
