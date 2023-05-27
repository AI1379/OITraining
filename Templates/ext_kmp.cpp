#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 20000010;
char a[MAXN], b[MAXN];
ll n, m;
ll z[MAXN], p[MAXN];
ll valz, valp;
int main() {
  ll l = 0, r = 0;
  scanf("%s%s", a, b);
  n = strlen(b);
  m = strlen(a);
  z[0] = n;
  valz = n + 1;
  for (int i = 1; i < n; ++i) {
    if (i <= r && i + z[i - l] - 1 < r) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0ll, r - i + 1);
      while (i + z[i] < n && b[i + z[i]] == b[z[i]])
        ++z[i];
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
#ifdef DEBUG
    printf("%lld ", z[i]);
#endif
    valz ^= ((i + 1) * (z[i] + 1));
  }
#ifdef DEBUG
  printf("\n");
#endif
  l = r = -1;
  for (int i = 0; i < m; ++i) {
    if (i <= r && i + z[i - l] - 1 < r) {
      p[i] = z[i - l];
    } else {
      p[i] = max(0ll, r - i + 1);
      while (p[i] < n && i + p[i] < m && a[i + p[i]] == b[p[i]])
        ++p[i];
    }
    if (i + p[i] - 1 > r) {
      l = i;
      r = i + p[i] - 1;
    }
#ifdef DEBUG
    printf("%lld ", p[i]);
#endif
    valp ^= ((i + 1) * (p[i] + 1));
  }
#ifdef DEBUG
  printf("\n");
#endif
  printf("%lld\n%lld\n", valz, valp);
  return 0;
}