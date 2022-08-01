#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll a, b, c, d, ans, x, y;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    x = min(abs(a - c), abs(b - d));
    y = max(abs(a - c), abs(b - d));
    ans = x + y + (abs(x - y) / 2) * 2;
    printf("%lld\n", ans);
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}