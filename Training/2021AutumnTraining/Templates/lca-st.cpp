// P3379
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int n, s;
vector<int> tr[MAXN];
int fa[MAXN][25];
int dep[MAXN];
void dfs(int u, int f) {
  int v;
  fa[u][0] = f;
  dep[u] = dep[f] + 1;
  for (int i = 0; i < tr[u].size(); i++) {
    v = tr[u][i];
    if (v != f) {
      dfs(v, u);
    }
  }
}
void init() {
  dfs(s, 0);
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i <= n; i++) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
  }
}
int query(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 20; i >= 0; i--) {
    if ((1 << i) <= dep[x] - dep[y]) {
      x = fa[x][i];
    }
  }
  if (x == y) return x;
  for (int i = 20; i >= 0; i--) {
    if (dep[x] >= (1 << i) && fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  return fa[x][0];
}
int main() {
  int m, x, y;
  cin >> n >> m >> s;
  for (int i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    tr[x].push_back(y);
    tr[y].push_back(x);
  }
  init();
  while (m--) {
    cin >> x >> y;
    cout << query(x, y) << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}