#include <iostream>
#include <math.h>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
int b[maxn];
int ip(int n) {
  if (pow(int(sqrt(n)), 2) == n)
    return 1;
  return 0;
}
int main() {
  int flag;
  flag = 0;
  int c, d;
  scanf("%d%d", &c, &d);
  int res = c * d;
  for (int i = 1; i <= sqrt(res) + 1; i++) {
    if (res % i == 0) {
      flag++;
      a[flag] = i;
      b[flag] = res / i;
    }
  }
  int ans = 0;
  for (int j = 1; j <= flag; j++) {
    if (ip(a[j] + c) == 1 && ip(b[j] + d) == 1)
      ans += 1;
    if (ip(b[j] + c) == 1 && ip(a[j] + d) == 1)
      ans += 1;
  }
  printf("%d", ans);
  return 0;
}