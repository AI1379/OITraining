#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m, a[3][MAXN], ans;
char ch[MAXN];
int find(int p, int x) {
  if (x > n) return x;
  int l = 1, r = a[p][0], mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (a[p][mid] < x) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  if (a[p][l] >= x) {
    x = a[p][l + m - 1];
  } else {
    x = 0;
  }
  if (!x) {
    return n + 1;
  } else {
    return x;
  }
}
int main() {
#ifndef DEBUG
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  scanf("%s", ch + 1);
  for (int i = 1; i <= n; i++) {
    if (ch[i] == 'J')
      a[0][++a[0][0]] = i;
    else if (ch[i] == 'O')
      a[1][++a[1][0]] = i;
    else
      a[2][++a[2][0]] = i;
  }
  ans = n;
  for (int i = 1; i + 3 * m - 1 <= n; i++) {
    int x = i - 1;
    for (int j = 0; j < 3; j++) {
      x = find(j, x + 1);
    }
    if (x <= n) {
      ans = min(ans, x - i + 1 - 3 * m);
    }
  }
  if (ans < n) {
    printf("%d", ans);
  } else {
    printf("-1");
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}