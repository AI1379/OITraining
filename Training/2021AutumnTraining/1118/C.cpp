#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
struct edge {
  ll u, v, w;
};
ll n, m;
bool color[MAXN];
ll dis[MAXN];
vector<pair<ll, ll>> graph[MAXN];
void dijkstra(ll u) {
  memset(dis, 0x3f, sizeof(dis));
  dis[u] = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push(make_pair(0, u));
  ll d;
  while (!q.empty()) {
    auto tmp = q.top();
    if (tmp.first > dis[tmp.second]) continue;
    d = tmp.first;
    u = tmp.second;
    for (auto x : graph[u]) {
      auto v = x.first;
      if (dis[v] > d + x.second) {
        dis[v] = d + x.second;
        q.push(make_pair(dis[v], v));
      }
    }
  }
  return;
}
int main() {
  ll u, v, w;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> color[i];
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }
  for (int i = 1; i <= n; i++) {
    if (color[i]) {
      graph[0].push_back(make_pair(i, 0));
      graph[i].push_back(make_pair(0, 0));
    }
  }
  dijkstra(0);
#ifdef DEBUG
  for (int i = 0; i <= n; i++) cout << dis[i] << endl;
#endif
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}