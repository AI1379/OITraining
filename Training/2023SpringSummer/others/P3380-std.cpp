#include <bits/stdc++.h>
using namespace std;
int Rt, n, m, Tot, tot, x, y, z, o, a[50005], rt[1000005], sm[30000005],
    ls[30000005], rs[30000005], Ls[1000005], Rs[1000005];
void add(int &x, int l, int r, int p, int o) {
  if (o == 1 && !x)
    x = ++tot;
  if (x)
    sm[x] += o;
  if (!x || l == r)
    return;
  int mid = (l + r) >> 1;
  (p <= mid) ? add(ls[x], l, mid, p, o) : add(rs[x], mid + 1, r, p, o);
}
int que(int x, int l, int r, int b, int e) {
  if (!x)
    return 0;
  if (b <= l && r <= e)
    return sm[x];
  int mid = (l + r) >> 1;
  return (b <= mid ? que(ls[x], l, mid, b, e) : 0) +
         (e > mid ? que(rs[x], mid + 1, r, b, e) : 0);
}
int rnk(int x, int l, int r, int b, int e, int L, int R) {
  if (!x)
    return 0;
  if (b <= l && r <= e)
    return que(rt[x], 1, n, L, R);
  int mid = (l + r) >> 1;
  return (b <= mid ? rnk(Ls[x], l, mid, b, e, L, R) : 0) +
         (e > mid ? rnk(Rs[x], mid + 1, r, b, e, L, R) : 0);
}
int kth(int x, int l, int r, int k, int L, int R) {
  if (l == r)
    return l;
  int mid = (l + r) >> 1, tmp = que(rt[Ls[x]], 1, n, L, R);
  return (k <= tmp) ? kth(Ls[x], l, mid, k, L, R)
                    : kth(Rs[x], mid + 1, r, k - tmp, L, R);
}
void upd(int &x, int l, int r, int v, int p, int o) {
  if (o == 1 && !x)
    x = ++Tot;
  if (x)
    add(rt[x], 1, n, p, o);
  if (!x || l == r)
    return;
  int mid = (l + r) >> 1;
  (v <= mid) ? upd(Ls[x], l, mid, v, p, o) : upd(Rs[x], mid + 1, r, v, p, o);
}
int pre(int X, int Y, int Z) {
  if (rnk(Rt, 0, 1e8, 0, Z - 1, X, Y) == rnk(Rt, 0, 1e8, 0, -1e9, X, Y))
    return -2147483647;
  return kth(Rt, 0, 1e8, rnk(Rt, 0, 1e8, 0, Z - 1, X, Y), X, Y);
}
int nex(int X, int Y, int Z) {
  if (rnk(Rt, 0, 1e8, 0, Z, X, Y) == rnk(Rt, 0, 1e8, 0, 1e9, X, Y))
    return 2147483647;
  return kth(Rt, 0, 1e8, rnk(Rt, 0, 1e8, 0, Z, X, Y) + 1, X, Y);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), upd(Rt, 0, 1e8, a[i], i, 1);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &o);
    if (o == 3)
      scanf("%d%d", &x, &y);
    else
      scanf("%d%d%d", &x, &y, &z);
    if (o == 1)
      printf("%d\n", rnk(Rt, 0, 1e8, 0, z - 1, x, y) + 1);
    if (o == 2)
      printf("%d\n", kth(Rt, 0, 1e8, z, x, y));
    if (o == 3)
      upd(Rt, 0, 1e8, a[x], x, -1), upd(Rt, 0, 1e8, y, x, 1), a[x] = y;
    if (o == 4)
      printf("%d\n", pre(x, y, z));
    if (o == 5)
      printf("%d\n", nex(x, y, z));
  }
}