#include <bits/stdc++.h>
using namespace std;
long long m, h;
long long a, b;
long long ans = 0;
long long binpow() {
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
  // freopen("B.in", "r", stdin);
  cin >> m >> h;
  for (int i = 1; i <= h; i++) {
    cin >> a >> b;
    ans = (ans + binpow()) % m;
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}