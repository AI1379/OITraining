#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll n, m, k;
ll a, b, cnt;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    if ((n * m) % k != 0) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    a = n * (m / k);
    b = (m * n) / k;
    cnt = k;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (j <= (m / k) * k) {
          printf("%lld ", a);
          if (j % k == 0) a--;
        } else {
          printf("%lld ", b);
          if (--cnt == 0) {
            cnt = k;
            b--;
          }
        }
      }
      printf("\n");
    }
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}