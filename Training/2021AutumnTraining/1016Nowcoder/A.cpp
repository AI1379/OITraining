#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long n, m;
long long rev;
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
int main() {
  long long t, tmp;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    rev = binpow(m, MOD - 2, MOD);
    tmp = binpow(m, n, MOD);
    cout << (rev * tmp) % MOD << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}