#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int MAXM = 200010;
struct node {
  int id, w;
};
vector<node> graph[MAXN];
int dis[MAXN];
bool vis[MAXN];
int n, m, s;
bool operator<(node a, node b) { return a.w > b.w; }
void dijkstra(int st) {
  for (int i = 0; i <= n; i++) {
    dis[i] = 0x7fffffff;
  }
  priority_queue<node> q;
  q.push((node){st, 0});
  dis[st] = 0;
  node head;
  int from, to, weight;
  while (!q.empty()) {
    head = q.top();
    q.pop();
    from = head.id;
    if (dis[from] < head.w) continue;
    for (int i = 0; i < graph[from].size(); i++) {
      weight = graph[from][i].w;
      to = graph[from][i].id;
      if (dis[to] > dis[from] + weight) {
        dis[to] = dis[from] + weight;
        q.push((node){to, dis[to]});
      }
    }
  }
}
int main() {
  int x, y, z;
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    graph[x].push_back((node){y, z});
  }
  dijkstra(s);
  for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}