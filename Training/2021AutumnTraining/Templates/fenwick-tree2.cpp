// P3368
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
int get_sum(int x) {
  int res = 0;
  for (; x; x -= lowbit(x)) res += f[x];
  return res;
}
void modify_r(int l, int r, int p) {
  modify(r + 1, -p);
  modify(l, p);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    modify(i, a[i] - a[i - 1]);
  }
  int opt, x, y, z;
  while (m--) {
    cin >> opt;
    if (opt == 1) {
      cin >> x >> y >> z;
      modify_r(x, y, z);
    } else {
      cin >> x;
      cout << get_sum(x) << endl;
    }
  }
  return 0;
}