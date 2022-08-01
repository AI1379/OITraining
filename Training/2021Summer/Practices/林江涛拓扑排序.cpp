#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
const int MAXM = 100010;
int n, m;
vector<int>graph[MAXN];
vector<int>weight[MAXN];
int deg[MAXN];
queue<int>q;
int dis[MAXN];
int main() {
  int x, y, z;
  cin >> n >> m;
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    deg[y]++;
    graph[x].push_back(y);
    weight[x].push_back(z);
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      q.push(i);
      dis[i] = 0;
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
      dis[graph[x][i]] = max(dis[graph[x][i]], dis[x] + weight[x][i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << ' ';
  }
  cout << endl;
  return 0;
}
