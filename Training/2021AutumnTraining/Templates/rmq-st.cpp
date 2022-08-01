// P3865
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, m;
int a[MAXN];
int st[MAXN][25];
void init() {
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int query(int l, int r) {
  if (l > r) swap(l, r);
  int len = log2(r - l + 1);
  return max(st[l][len], st[r - (1 << len) + 1][len]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    st[i][0] = a[i];
  }
  init();
  int l, r;
  while (m--) {
    scanf("%d%d", &l, &r);
    printf("%d\n", query(l, r));
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}