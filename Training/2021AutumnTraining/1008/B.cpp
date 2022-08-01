#include <bits/stdc++.h>
using namespace std;
int n, m, p, ans;
int a[501][1001], dis[501][1001];
int st[501], num[501], fa[501];
int find(int x) {
  if (x != fa[x])
    return fa[x] = find(fa[x]);
  else
    return fa[x];
}
void add(int x, int y) {
  int anx = find(x), any = find(y);
  if (anx == any) return;
  ans += num[x];
  num[x] += num[y];
  num[y] = 0;
  fa[any] = anx;
}
int main() {
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    num[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
    sort(a[i] + 1, a[i] + 1 + m);
    for (int j = 2; j <= m; j++) {
      dis[i][j - 1] = a[i][j] - a[i][j - 1];
    }
    dis[i][m] = a[i][1] - a[i][m] + p;
    for (int j = 1; j <= m; j++) {
      dis[i][m + j] = dis[i][j];
    }
    int x = 1, y = 2, k = 0;
    while (x <= m && y <= m) {
      while (k < m && dis[i][x + k] == dis[i][y + k]) k++;
      if (k == m) break;
      if (dis[i][x + k] > dis[i][y + k]) {
        x = x + k + 1;
        k = 0;
        if (x == y) x++;
      } else {
        y = y + k + 1;
        k = 0;
        if (x == y) y++;
      }
    }
    st[i] = min(x, y);
  }
  bool flag;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      flag = true;
      for (int l = 0; l < m; l++) {
        if (dis[i][st[i] + l] != dis[j][st[j] + l]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        int fx = find(i), fy = find(j);
        if (fx == fy) continue;
        ans += num[i];
        num[i] += num[j];
        num[j] = 0;
        fa[fy] = fx;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
