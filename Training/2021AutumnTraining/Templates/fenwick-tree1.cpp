// P3374
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int n, m;
int a[MAXN];
int f[MAXN];
inline int lowbit(int x) { return x & (-x); }
void modify(int x, int p) {
  for (; x <= n; x += lowbit(x)) f[x] += p;
}
int get_pre_sum(int x) {
  int res = 0;
  for (; x; x -= lowbit(x)) res += f[x];
  return res;
}
int get_sum(int l, int r) { return get_pre_sum(r) - get_pre_sum(l - 1); }
int main() {
  int x, y, z;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    modify(i, a[i]);
  }
  while (m--) {
    cin >> x >> y >> z;
    if (x == 1)
      modify(y, z);
    else
      cout << get_sum(y, z) << endl;
  }
  return 0;
}