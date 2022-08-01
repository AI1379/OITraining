#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int revf[5010];
long long rev(long long a, long long b) {
  if (revf[a] != -1) return revf[a];
  long long m = b;
  b -= 2;
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return revf[a] = res;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
// long long powf[5010][2010]
// long long binpow(long long a, long long b) {
//   if (b == 0) return 1;
//   long long res = binpow(a, b / 2);
//   if (b % 2)
//     return res * res * a;
//   else
//     return res * res;
// }
int p, t;
int f[5010][5010];
int solve(int x, int y) {
  cout << x << ' ' << y << endl;
  if (f[x][y] != -1) return f[x][y];
  long long num = rev(x, p) * y;
  long long res = 0;
  cout << rev(x, p) << ' ' << num << endl;
  for (int i = 0; i < x && num > 0; i++) {
    while (num % (x - i) == 0 && x - i > 1 && num > 0) {
      res = (res + i) % p;
      num /= (x - i);
      cout << '\\';
    }
    while (num % (x + i) == 0 && x + i > 1 && num > 0) {
      res = (res + i) % p;
      num /= (x + i);
      cout << '/';
    }
    cout << num << ' ' << res << endl;
  }
  cout << res << endl;
  res = res * binpow(t, (x - 1) * (p - 1) + y - 1, MOD) % MOD;
  return f[x][y] = res;
}
long long ans = 0;
int main() {
  memset(f, -1, sizeof(f));
  memset(revf, -1, sizeof(revf));
  cin >> p >> t;
  for (int i = 1; i <= p - 1; i++) {
    for (int j = 1; j <= p - 1; j++) {
      ans += solve(i, j);
    }
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}