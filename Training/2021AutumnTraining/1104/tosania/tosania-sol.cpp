#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXK = 512;
const ll MAXN = 512;
ll n, k;
ll maxd = 0;
vector<ll> tree[MAXK][MAXN];
ll st[MAXK][MAXN][10];
ll dep[MAXK][MAXN];
ll dis[MAXN][MAXN];
ll ans = 0;
void dfs(int num, int u, int fa) {
  ll v;
  st[num][u][0] = fa;
  dep[num][u] = dep[num][fa] + 1;
  maxd = max(maxd, dep[num][u]);
  for (int i = 0; i < tree[num][u].size(); i++) {
    v = tree[num][u][i];
    if (v != fa) dfs(num, v, u);
  }
}
void init(int num) {
  // dep[num][0] = -1;
  // dfs(num, 1, 0);
  for (int j = 1; j < maxd; j++) {
    for (int i = 1; i <= n; i++) {
      st[num][i][j] = st[num][st[num][i][j - 1]][j - 1];
    }
  }
}
ll query(int num, int x, int y) {
  ll a = x, b = y, lca, len;
  // if (x == y) return 0;
  if (dep[num][x] < dep[num][y]) swap(x, y);
  for (int i = maxd; i >= 0; i--) {
    if ((1 << i) <= dep[num][x] - dep[num][y]) {
      x = st[num][x][i];
#ifdef DEBUG
      cout << x << ' ' << y << endl;
#endif
    }
  }
  if (x != y) {
    for (int i = maxd; i >= 0; i--) {
      if (dep[num][x] >= (1 << i) && st[num][x][i] != st[num][y][i]) {
        x = st[num][x][i];
        y = st[num][y][i];
#ifdef DEBUG
        cout << x << ' ' << y << endl;
#endif
      }
    }
    lca = st[num][x][0];
  } else
    lca = x;
  len = dep[num][a] + dep[num][b] - 2 * dep[num][lca];
#ifdef DEBUG
  cout << "LCA: " << a << ' ' << b << ' ' << lca << ' ' << len << ' ';
#endif
  return len;
}
int main() {
  ll u, v;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n - 1; j++) {
      cin >> u >> v;
      tree[i][u].push_back(v);
      tree[i][v].push_back(u);
    }
    dfs(i, 1, 0);
  }
  maxd = log2(maxd) + 1;
  for (int i = 1; i <= k; i++) {
    init(i);
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        dis[x][y] += query(i, x, y);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = 0;
    for (int j = 1; j <= n; j++) {
      for (int t = 1; t <= n; t++) {
        if (dis[i][t] + dis[t][j] == dis[i][j]) {
          ans += j;
        }
      }
    }
    cout << ans << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}