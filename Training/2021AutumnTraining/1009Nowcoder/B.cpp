#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int n;
int a[100010];
int tri[100010];
int inv[100010];
void getTri(int x) {
  tri[1] = 1;
  inv[1] = 1;
  for (int i = 2; i <= x; i++) {
    inv[i] = (MOD - (MOD / i)) * inv[MOD % i] % MOD;
  }
  for (int i = 2; i <= x; i++) {
    tri[i] = tri[i - 1] * (x - i + 1) % MOD * inv[i - 1] % MOD;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  // cout << n / 2 + 1 << endl;
  getTri(n / 2 + 1);
  ll ans = 0;
  for (int i = 1; i <= n / 2 + 1; i++) {
    if (n % 2 == 0) {
      ans = (ans +
             (tri[i] * ((a[2 * i - 1] + a[2 * i]) % MOD) % MOD *
                  (i % 2 == 0 ? -1 : 1) +
              MOD) %
                 MOD +
             MOD) %
            MOD;
    } else {
      ans = (ans +
             (tri[i] * a[2 * i - 1] % MOD * (i % 2 == 0 ? -1 : 1) + MOD) % MOD +
             MOD) %
            MOD;
    }
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}