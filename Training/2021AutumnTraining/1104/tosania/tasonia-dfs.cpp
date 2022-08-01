#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll MAXK = 512;
const ll MAXN = 512;
ll n, k;
ll tree[MAXK][MAXN][MAXN];
ll dis[MAXN][MAXN];
// ll ans = 0;
ll ans[MAXN];
ll num, src;
void dfs(int u, int fa, int dep) {
  dis[src][u] += dep;
  // dis[u][src] += dep;
  for (int i = 1; i <= tree[num][u][0]; i++) {
    if (tree[num][u][i] != fa) dfs(tree[num][u][i], u, dep + 1);
  }
}
int main() {
  ll u, v, i, j, t;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= k; i++) {
    for (j = 1; j <= n - 1; j++) {
      scanf("%d%d", &u, &v);
      tree[i][u][++tree[i][u][0]] = v;
      tree[i][v][++tree[i][v][0]] = u;
    }
  }
  for (i = 1; i <= k; i++) {
    for (u = 1; u <= n; u++) {
      num = i;
      src = u;
      dfs(u, 0, 0);
    }
  }
  for (i = 1; i <= n; i++) {
    ans[i] += i;
    for (j = i + 1; j <= n; j++) {
      for (t = 1; t <= n; t++) {
        if (dis[i][t] + dis[t][j] == dis[i][j]) {
          ans[i] += j;
          ans[j] += i;
        }
      }
    }
    // printf("%d\n", ans);
  }
  for (i = 1; i <= n; i++) printf("%d\n", ans[i]);
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}