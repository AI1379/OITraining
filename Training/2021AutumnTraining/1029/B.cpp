#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int n, m, k;
vector<int> graph[MAXN];
int deg[MAXN];
bool vis[MAXN];
int hSize = 0;
int heap[MAXN];
int ans = 0;
bool dfv[MAXN];
bool cmp(int a, int b) { return deg[a] > deg[b]; }
void dfs(int u, int fa) {
  int v;
  dfv[u] = true;
  for (int i = 0; i < graph[u].size(); i++) {
    v = graph[u][i];
    if (v != fa && !dfv[v]) dfs(v, u);
  }
}
int main() {
  int u, v;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  for (int i = 1; i <= n; i++) {
    heap[++hSize] = i;
    if (!dfv[i]) {
      dfs(i, 0);
      ans++;
    }
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}