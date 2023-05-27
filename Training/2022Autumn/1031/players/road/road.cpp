#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 3000010;
ll n, ans;
char str[MAXN];
int main() {
#ifndef DEBUG
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
#endif
  scanf("%s", str + 1);
  n = strlen(str + 1);
  for (int i = 1; i <= n; ++i) {
    if (i % 3 == 1 && str[i] != 'X') {
      ++ans;
    }
  }
  printf("%lld\n", ans);
  return 0;
}