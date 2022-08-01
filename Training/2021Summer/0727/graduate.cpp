#include <bits/stdc++.h>
using namespace std;
struct node {
  int id;
  int time;
};
int n, m, t;
vector<int> graph[15][100];
bool vis[100][15];
queue<node> q;
int main() {
#ifndef DEBUG
  freopen("graduate.in", "r", stdin);
  freopen("graduate.out", "w", stdout);
#endif
  node head;
  int a, b;
  cin >> n >> m >> t;
  for (int i = 1; i <= t; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a >> b;
      graph[i][a].push_back(b);
      graph[i][b].push_back(b);
    }
  }
  q.push((node){1, 0});
  vis[1][1] = true;
  while (!q.empty()) {
    head = q.front();
    q.pop();
    a = head.id;
    b = head.time % t + 1;
    if (a == 0) {
      cout << head.time << endl;
#ifdef DEBUG
      system("pause");
#endif
      return 0;
    }
    for (int i = 0; i < graph[b][a].size(); i++) {
      if (!vis[graph[b][a][i]][(head.time + 1) % t + 1]) {
        q.push((node){graph[b][a][i], head.time + 1});
        vis[graph[b][a][i]][(head.time + 1) % t + 1] = true;
      }
    }
  }
  cout << "Poor guys!" << endl;
#ifdef DBEUG
  system("pause");
#endif
  return 0;
}