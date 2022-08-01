#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 100;
struct node {
  int len, place;
};
node ties[MAXN];
int n, ori[MAXN], f[MAXN], g[MAXN], ans[MAXN];
bool cmp(node x, node y) { return x.len < y.len; }
int main() {
#ifndef DEBUG
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n + 1; i++) {
    scanf("%d", &ties[i].len);
    ties[i].place = i;
  }
  sort(ties + 1, ties + n + 2, cmp);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ori[i]);
  }
  sort(ori + 1, ori + n + 1);
  for (int i = 1; i <= n; i++) {
    f[i] = max(f[i - 1], max(ties[i].len - ori[i], 0));
  }
  for (int i = n; i; i--) {
    g[i] = max(g[i + 1], max(ties[i + 1].len - ori[i], 0));
  }
  for (int i = 1; i <= n + 1; i++) {
    ans[ties[i].place] = max(f[i - 1], g[i]);
  }
  for (int i = 1; i <= n + 1; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}
