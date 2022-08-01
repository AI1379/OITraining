#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;
#define ll long long
const ll MAXM = 110;
const ll MAXN = 110;
ll m, n;
ll mp[MAXM][MAXN];
char res[100010];
ll ans = 0;
bool flag[MAXM];
bool work(ll x, ll y) {
  ll p = 0;
  ll a = x, b = n - x + 1, c = y, d = m - y + 1;
  p |= (ll)(mp[a][c] != y) << 3;
  p |= (ll)(mp[a][d] != y) << 2;
  p |= (ll)(mp[b][c] != y) << 1;
  p |= (ll)(mp[b][d] != y);
  ans += 4;
  if (flag[c] || flag[d]) {
    p = ((p >> 2) | (p << 2)) & 0b1111;
  }
  switch (p) {
  case 0b0101:
    ans -= 4;
    return true;
  case 0b0110:
    sprintf(res + strlen(res), "1 %lld\n0 %lld\n1 %lld\n0 %lld\n", c, b, c, b);
    return true;
  case 0b1001:
    sprintf(res + strlen(res), "1 %lld\n0 %lld\n1 %lld\n0 %lld\n", d, a, d, a);
    return true;
  case 0b0011:
    flag[c] = !flag[c];
    flag[d] = !flag[d];
    sprintf(res + strlen(res), "0 %lld\n1 %lld\n0 %lld\n1 %lld\n", a, c, a, d);
    return true;
  case 0b1010:
    flag[c] = !flag[c];
    flag[d] = !flag[d];
    sprintf(res + strlen(res), "0 %lld\n1 %lld\n1 %lld\n0 %lld\n", a, c, d, a);
    return true;
  case 0b1100:
    flag[c] = !flag[c];
    flag[d] = !flag[d];
    sprintf(res + strlen(res), "0 %lld\n1 %lld\n0 %lld\n1 %lld\n", b, c, b, d);
    return true;
  default:
    return false;
  }
}
ll count[MAXN];
int main() {
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%lld", &(mp[i][j]));
      count[mp[i][j]]++;
      if (mp[i][j] != j && mp[i][j] != m - j + 1) {
        printf("NO\n");
#ifdef VSCODE
        system("pause");
#endif
        return 0;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (count[i] != n) {
      printf("NO\n");
#ifdef VSCODE
      system("pause");
#endif
      return 0;
    }
  }
  for (int i = 1; 2 * i <= n; i++) {
    for (int j = 1; 2 * j <= m; j++) {
      if (!work(i, j)) {
        printf("NO\n");
#ifdef VSCODE
        system("pause");
#endif
        return 0;
      }
    }
  }
  printf("YES\n%lld\n%s", ans, res);
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}