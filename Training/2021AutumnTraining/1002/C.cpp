#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> graph[100010];
int deg[100010];
int ans[100010];
int main() {
  int x, y;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    graph[x].push_back(y);
    deg[y]++;
  }
  queue<pair<int, int> > q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      q.push(make_pair(i, 1));
    }
  }
  int head, cnt;
  while (!q.empty()) {
    head = q.front().first;
    cnt = q.front().second;
    q.pop();
    ans[head] = cnt;
    // cout << head << endl;
    for (int i = 0; i < graph[head].size(); i++) {
      deg[graph[head][i]]--;
      if (deg[graph[head][i]] == 0) {
        q.push(make_pair(graph[head][i], cnt + 1));
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}