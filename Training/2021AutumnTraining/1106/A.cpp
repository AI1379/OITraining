#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, t;
ll a, b;
ll ans = 0;
int main() {
  scanf("%lld%lld%lld", &n, &m, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a, &b);
    ans += (t * b - a);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%lld%lld", &a, &b);
    ans += (a - t * b);
  }
  if (ans == 0)
    printf("Equilibrium\n");
  else if (ans < 0)
    printf("Yes\n");
  else
    printf("No\n");
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}