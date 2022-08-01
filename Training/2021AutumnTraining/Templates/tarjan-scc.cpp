#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
const int MAXM = 100010;
int n, m;
int dagn, dagm;
int weight[MAXN];
vector<int> graph[MAXN];
int dfn[MAXN], low[MAXN];
int stk[MAXN], top;
bool instk[MAXN];
int cnt = 0;
int scc[MAXN];
set<int> dagst[MAXN];
vector<int> dag[MAXN];
int dagw[MAXN], deg[MAXN];
int dp[MAXN];
void tarjan(int u, int fa) {
  int v;
  low[u] = dfn[u] = ++cnt;
  stk[++top] = u;
  instk[u] = true;
  for (int i = 0; i < graph[u].size(); i++) {
    v = graph[u][i];
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (instk[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
#ifdef DEBUG
    cout << "Update DAGN " << u << endl;
#endif
    dagn++;
    while (stk[top] != u && top > 0) {
      scc[stk[top]] = dagn;
      instk[stk[top--]] = false;
    }
    scc[stk[top]] = dagn;
    instk[stk[top--]] = false;
#ifdef DEBUG
    cout << top << endl;
#endif
  }
}
int main() {
  int x, y;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    graph[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i, i);
    }
  }
#ifdef DEBUG
  cout << "DAG Num: " << dagn << endl;
  for (int i = 1; i <= n; i++) {
    cout << scc[i] << ' ';
  }
  cout << endl << endl;
#endif
  int u, v;
  for (int i = 1; i <= n; i++) {
    u = scc[i];
    dagw[u] += weight[i];
    for (int j = 0; j < graph[i].size(); j++) {
      v = scc[graph[i][j]];
      if (v != u) {
        dagst[u].insert(v);
      }
    }
#ifdef DEBUG
    cout << i << ' ' << scc[i] << endl;
#endif
  }
  for (int i = 1; i <= dagn; i++) {
    dag[i].assign(dagst[i].begin(), dagst[i].end());
#ifdef DEBUG
    for (auto a : dag[i]) {
      cout << a << ' ';
    }
    cout << endl;
#endif
  }
  queue<int> q;
  for (int i = 1; i <= dagn; i++) {
#ifdef DEBUG
    cout << "DAG weight: " << dagw[i] << endl;
#endif
    for (int j = 0; j < dag[i].size(); j++) {
      dagm++;
      deg[dag[i][j]]++;
    }
  }
  for (int i = 1; i <= dagn; i++) {
    if (deg[i] == 0) {
      dp[i] = dagw[i];
      q.push(i);
    }
  }
  int ans = 0;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int i = 0; i < dag[u].size(); i++) {
      v = dag[u][i];
      deg[v]--;
      if (deg[v] == 0) {
        q.push(v);
      }
      dp[v] = max(dp[v], dp[u] + dagw[v]);
    }
  }
  for (int i = 1; i <= dagn; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}