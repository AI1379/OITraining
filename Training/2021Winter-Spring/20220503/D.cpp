#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 1010;
const ll MAXT = 10010;
static ll n, t;
static ll v[MAXN], c[MAXN];
static ll dp[MAXT];
static int i, j;
#define max(x, y) x > y ? x : y
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int main() {
  t = read();
  n = read();
  for (i = 1; i <= n; i++) {
    c[i] = read();
    v[i] = read();
  }
  for (i = 1; i <= n; i++) {
    for (j = c[i]; j <= t; j++) {
      dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
    }
  }
  printf("%lld\n", dp[t]);
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}