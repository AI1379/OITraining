#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 3010;
const ll MAXM = 6010;
const ll INF = 1000000000;
struct node {
  ll id, w;
};
bool operator<(node a, node b) { return a.w > b.w; }

vector<node> graph[MAXN];
ll dis[MAXN][MAXN];
ll n, m;

void spfa(ll st) {
  bool vis[MAXN];
  ll cnt[MAXN];
  for (ll i = 0; i <= n; i++) {
    dis[0][i] = INF;
    vis[i] = false;
    cnt[i] = 0;
  }
  queue<ll> q;
  q.push(st);
  vis[st] = true;
  dis[0][st] = 0;
  while (!q.empty()) {
    ll head = q.front();
    q.pop();
    cnt[head]++;
    vis[head] = false;

    if (cnt[head] > n) {
      cout << "-1" << endl;
#ifdef DEBUG
      system("pause");
#endif
      exit(0);
    }

    for (ll i = 0; i < graph[head].size(); i++) {
      ll to = graph[head][i].id;
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

void dijkstra(ll st) {
  for (ll i = 0; i <= n; i++) {
    dis[st][i] = INF;
  }
  priority_queue<node> q;
  q.push((node){st, 0});
  dis[st][st] = 0;
  node head;
  ll from, to, weight;

  while (!q.empty()) {
    head = q.top();
    q.pop();
    from = head.id;
    if (dis[st][from] < head.w) continue;

    for (ll i = 0; i < graph[from].size(); i++) {
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
  ll x, y, z;
  cin >> n >> m;
  for (ll i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    graph[x].push_back((node){y, z});
  }
  for (ll i = 1; i <= n; i++) {
    graph[0].push_back((node){i, 0});
  }
  spfa(0);
  for (ll i = 1; i <= n; i++) {
    for (ll j = 0; j < graph[i].size(); j++) {
      graph[i][j].w = graph[i][j].w + dis[0][i] - dis[0][graph[i][j].id];
    }
  }
  for (ll i = 1; i <= n; i++) {
    dijkstra(i);
  }
  ll ans;
  for (ll i = 1; i <= n; i++) {
    ans = 0;
    for (ll j = 1; j <= n; j++) {
      dis[i][j] =
          ((dis[i][j] == INF) ? INF : (dis[i][j] - (dis[0][i] - dis[0][j])));
      ans += (j * dis[i][j]);
    }
    cout << ans << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}