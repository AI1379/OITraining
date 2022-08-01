#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int n, m;
int a[MAXN], ori[MAXN];
int b[MAXN];
int f[MAXN], pos[MAXN];
int pre[MAXN];
inline int lowbit(int x) { return x & (-x); }
// 返回小于x的dp以及它的位置
pair<int, int> get_max(int x) {
  int res = 0, respos = 0;
  for (; x; x -= lowbit(x)) {
    if (f[x] > res) {
      res = f[x];
      respos = pos[x];
    }
  }
  return make_pair(res, respos);
}
void modify_max(int x, int p, int xpos) {
  for (; x <= m; x += lowbit(x)) {
    if (f[x] < p) {
      f[x] = p;
      pos[x] = xpos;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ori[i] = b[i] = a[i];
  }

  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;

  int dp, ans = 0, beg;
  pair<int, int> tmp;
  for (int i = 1; i <= n; i++) {
    tmp = get_max(a[i] - 1);
    dp = tmp.first + 1;
    pre[i] = tmp.second;
    if (ans < dp) {
      ans = dp;
      beg = i;
    }
    modify_max(a[i], dp, i);
  }
  printf("%d\n", ans);
  stack<int> stk;  // STL栈写起来方便
  for (; beg; beg = pre[beg]) stk.push(beg);
  while (!stk.empty()) {
    printf("%d ", ori[stk.top()]);
    stk.pop();
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}