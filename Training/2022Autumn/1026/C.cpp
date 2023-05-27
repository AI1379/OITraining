#include <bits/stdc++.h>
using namespace std;
#define ull unsigned int
double a, b;
ull p, q;
char opt;
ull d2f(double x) { return (ull)(x * (1 << 8) + 0.5); }
double f2d(ull x) { return x / (double)(1 << 8); }
int main() {
#ifndef DEBUG
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
#endif
  cin >> a >> b >> opt;
  cout << fixed << setprecision(8) << a << ' ' << b << endl;
  p = d2f(a);
  q = d2f(b);
  switch (opt) {
    case '+': {
      cout << f2d(p + q) << endl;
      break;
    }
    case '-': {
      cout << f2d(p - q) << endl;
      break;
    }
    case '*': {
      cout << f2d(p * q) << endl;
      break;
    }
    case '/': {
      cout << f2d(p / q) << endl;
      break;
    }
  }
  return 0;
}