#include <bits/stdc++.h>
using namespace std;
bitset<1005> a[1005];
int T;
int n;
int main() {
  freopen("discuss.in", "r", stdin);
  freopen("discuss.out", "w", stdout);
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i <= 1000; i++)
      a[i] = 0;
    for (int i = 1; i <= n; i++) {
      int ks;
      scanf("%d", &ks);
      for (int j = 1, p; j <= ks; j++) {
        scanf("%d", &p);
        a[i].set(p);
      }
    }
    int flag = 0, ansi = -1, ansj = -1;
    for (int i = 1; i <= n; i++) {
      if (flag)
        break;
      for (int j = i + 1; j <= n; j++) {
        bitset<1005> tmp = a[i] & a[j];
        if (tmp.count() > 0 && (a[i] ^ tmp).count() > 0 &&
            (a[j] ^ tmp).count() > 0)
          flag = 1, ansi = i, ansj = j;
      }
    }
    if (flag) {
      puts("YES");
      printf("%d %d\n", ansi, ansj);
    } else
      puts("NO");
  }
}
