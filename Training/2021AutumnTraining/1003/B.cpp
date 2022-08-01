#include <bits/stdc++.h>
using namespace std;
int n;
int f[1010][1010];
int sum[1010];
int gcd(int a, int b) {
  if (f[a][b] != -1) return f[a][b];
  f[a][b] = (b == 0 ? a : gcd(b, a % b));
  return f[a][b];
}
long long ans = 0;
int main() {
  memset(f, -1, sizeof(f));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      sum[i] += gcd(i, j);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans += sum[f[i][j]];
    }
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}