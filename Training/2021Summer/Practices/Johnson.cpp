#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3010;
const int MAXM = 6010;
const int INF = 1000000000;
struct node {
  int id, w;
};
bool operator<(node a, node b) { return a.w > b.w; }

vector<node> graph[MAXN];
int dis[MAXN][MAXN];
int n, m;

void spfa(int st) {
  bool vis[MAXN];
  int cnt[MAXN];
  for (int i = 0; i <= n; i++) {
    dis[0][i] = INF;
    vis[i] = false;
    cnt[i] = 0;
  }
  queue<int> q;
  q.push(st);
  vis[st] = true;
  dis[0][st] = 0;
  while (!q.empty()) {
    int head = q.front();
    q.pop();
    cnt[head]++;
    vis[head] = false;

    if (cnt[head] > n) {
      cout << "-1" << endl;
      exit(0);
    }

    for (int i = 0; i < graph[head].size(); i++) {
      int to = graph[head][i].id;
      if (dis[0][to] > dis[0][head] + graph[head][i].w) {
        dis[0][to] = dis[0][head] + graph[head][i].w;
        if (!vis[to]) {
          q.push(to);
          vis[to] = true;
        }
      }
    }
  }
}

void dijkstra(int st) {
  for (int i = 0; i <= n; i++) {
    dis[st][i] = INF;
  }
  priority_queue<node> q;
  q.push((node){st, 0});
  dis[st][st] = 0;
  node head;
  int from, to, weight;

  while (!q.empty()) {
    head = q.top();
    q.pop();
    from = head.id;
    if (dis[st][from] < head.w) continue;

    for (int i = 0; i < graph[from].size(); i++) {
      weight = graph[from][i].w;
      to = graph[from][i].id;
      if (dis[st][to] > dis[st][from] + weight) {
        dis[st][to] = dis[st][from] + weight;
        q.push((node){to, dis[st][to]});
      }
    }
  }
}

int main() {
  int x, y, z;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    graph[x].push_back((node){y, z});
  }
  for (int i = 1; i <= n; i++) {
    graph[0].push_back((node){i, 0});
  }
  spfa(0);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      graph[i][j].w = graph[i][j].w + dis[0][i] - dis[0][graph[i][j].id];
    }
  }
  for (int i = 1; i <= n; i++) {
    dijkstra(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dis[i][j] == INF) {
        cout << "-1 ";
      } else {
        dis[i][j] = dis[i][j] - (dis[0][i] - dis[0][j]);
        cout << dis[i][j] << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}