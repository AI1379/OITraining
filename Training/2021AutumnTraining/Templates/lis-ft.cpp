// P1020
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int n, m;
int a[MAXN];
int b[MAXN];
int f[MAXN];
inline int lowbit(int x) { return x & (-x); }
int get_max(int x) {
  int res = 0;
  for (; x; x -= lowbit(x)) res = max(res, f[x]);
  return res;
}
void modify_max(int x, int p) {
  for (; x <= m; x += lowbit(x)) f[x] = max(f[x], p);
}
int get_min(int x) {
  int res = 0;
  for (; x <= m; x += lowbit(x)) res = max(res, f[x]);
  return res;
}
void modify_min(int x, int p) {
  for (; x; x -= lowbit(x)) f[x] = max(f[x], p);
}
int main() {
  n = 1;
  while (scanf("%d", &a[n]) != EOF) {
    b[n] = a[n];
    n++;
  }
  n--;

  // 离散化
  // a[i]范围在1e9 需要离散化把a[i]压到MAXN 否则树状数组要爆空间
  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;

  int dp, ans = 0;
  for (int i = 1; i <= n; i++) {
    // a[i]往后的dp值的max
    dp = get_min(a[i]) + 1;
    ans = max(ans, dp);
    modify_min(a[i], dp);
  }
  printf("%d\n", ans);

  ans = 0;
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    // a[i-1]往前的dp值的max
    // 树状数组中get_max(a[i])指到目前为止所有小于等于a[i]的数对应的dp值
    // i的dp值必然从一个在自己前面的小于a[i]的一个值转移而来
    dp = get_max(a[i] - 1) + 1;
    ans = max(ans, dp);
    modify_max(a[i], dp);
  }
  printf("%d\n", ans);
  return 0;
}