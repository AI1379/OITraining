#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = 2010;

ll n, m, a, b;
vector<ll>graph[MAXN];
bool mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
ll dis[MAXN][MAXN];
void bfs(ll s) {
  queue<ll> q;
  vis[s][s] = true;
  dis[s][s] = 0;
  q.push(s);
  ll u;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (auto v : graph[u]) {
      if (!vis[s][v]) {
        vis[s][v] = true;
        dis[s][v] = dis[s][u] + 1;
        q.push(v);
      }
    }
  }
}
ll ans = 0;
int main() {
  ll u, v;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> a >> b;
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    mp[u][v] = mp[v][u] = true;
  }
  for (int i = 1; i <= n; i++) {
    bfs(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!mp[i][j]
          && dis[a][i] + dis[j][b] + 1 >= dis[a][b]
          && dis[a][j] + dis[i][b] + 1 >= dis[a][b]) {
        ++ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
