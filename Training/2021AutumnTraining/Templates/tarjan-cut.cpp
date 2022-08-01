#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20010;
const int MAXM = 100010;
int n, m;
vector<int> graph[MAXN];
int dfn[MAXN], low[MAXN];
bool cut[MAXN];
int cnt;
int res;
void tarjan(int u, int fa) {
  int num = 0;
  low[u] = dfn[u] = ++cnt;
  for (auto v : graph[u]) {
    if (!dfn[v]) {
      num++;
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (fa != u && low[v] >= dfn[u] && !cut[u]) {
        res++;
        cut[u] = true;
      }
    } else if (v != fa) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (u == fa && num >= 2 && !cut[u]) {
    res++;
    cut[u] = true;
  }
}
int main() {
  int x, y;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i, i);
    }
  }
  cout << res << endl;
  for (int i = 1; i <= n; i++) {
    if (cut[i]) {
      cout << i << ' ';
    }
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}