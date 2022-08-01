#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
const int MAXM = 500010;
vector<int>graph[MAXN];
vector<int>weight[MAXN];
bool vis[MAXN];
int dis[MAXN];
int n, m, s;
void spfa(int st) {
  for (int i = 0; i < MAXN; i++) {
    dis[i] = 0x7fffffff;
    vis[i] = false;
  }
  queue<int> q;
  q.push(st);
  vis[st] = true;
  dis[st] = 0;
  while (!q.empty()) {
    int head = q.front();
    q.pop();
    vis[head] = false;
    for (int i = 0; i < graph[head].size(); i++) {
      int to = graph[head][i];
      if (dis[to] > dis[head] + weight[head][i]) {
        dis[to] = dis[head] + weight[head][i];
        if (!vis[to]) {
          q.push(to);
          vis[to] = true;
        }
      }
    }
  }
}
int main() {
  int x, y, z;
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    graph[x].push_back(y);
    weight[x].push_back(z);
  }
  spfa(s);
  for (int i = 1; i <= n; i++)
    cout << dis[i] << ' ';
  return 0;
}