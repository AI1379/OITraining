#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int MAXM = 1010;
int n, m;
vector<int> graph[MAXN + MAXM];
bool lines[MAXM];
int st[MAXN];
int s;
int deg[MAXN + MAXM];
queue<int> q;
int f[MAXN + MAXM];
int main() {
  int x, y, s;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> s;
    memset(lines, false, sizeof(lines));
    memset(st, 0, sizeof(st));
    for (int j = 1; j <= s; j++) {
      cin >> st[j];
      lines[st[j]] = true;
    }
    for (int j = st[1]; j <= st[s]; j++) {
      if (lines[j]) {
        graph[j].push_back(n + i);
        deg[n + i]++;
      } else {
        graph[n + i].push_back(j);
        deg[j]++;
      }
    }
  }
  for (int i = 1; i <= n + m; i++) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (int i = 0; i < graph[x].size(); i++) {
      deg[graph[x][i]]--;
      if (deg[graph[x][i]] == 0) {
        q.push(graph[x][i]);
      }
      if (graph[x][i] > n) {
        f[graph[x][i]] = max(f[graph[x][i]], f[x]);
      } else {
        f[graph[x][i]] = max(f[graph[x][i]], f[x] + 1);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n + m; i++) {
    ans = max(ans, f[i]);
  }
  cout << ans + 1 << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}
