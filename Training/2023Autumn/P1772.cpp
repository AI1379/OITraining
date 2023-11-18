#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 127;
const ll MAXM = 31;
const ll INF = 1e14;
ll n, m, k, e, d;
ll mp[MAXM][MAXM];
ll cost[MAXN][MAXN];
ll dis[MAXM];
ll dp[MAXN];
bool vis[MAXM];
bool avail[MAXN][MAXM];
bool availnow[MAXM];
void dij() {
  memset(vis, false, sizeof(vis));
  memset(dis, 0x3f, sizeof(dis));
  ll u = 1;
  dis[u] = 0;
  for (int i = 1; i <= m; ++i) {
    u = 0;
    for (int v = 1; v <= m; ++v) {
      if (!vis[v] && availnow[v] && dis[v] < dis[u])
        u = v;
    }
    vis[u] = true;
    for (int v = 1; v <= m; ++v) {
      if (availnow[v])
        dis[v] = min(dis[v], dis[u] + mp[u][v]);
    }
  }
}
int main() {
  ll u, v, w;
  cin >> n >> m >> k >> e;
  memset(mp, 0x3f, sizeof(mp));
  for (int i = 1; i <= m; ++i)
    mp[i][i] = 0;
  for (int i = 1; i <= e; ++i) {
    cin >> u >> v >> w;
    mp[u][v] = mp[v][u] = min(mp[u][v], w);
  }
  cin >> d;
  memset(avail, true, sizeof(avail));
  for (int i = 1; i <= d; ++i) {
    cin >> w >> u >> v;
    for (int t = u; t <= v; ++t) {
      avail[t][w] = false;
    }
  }
  for (int u = 1; u <= n; ++u) {
    for (int v = u; v <= n; ++v) {
      memset(availnow, true, sizeof(availnow));
      for (int i = 1; i <= m; ++i) {
        for (int t = u; t <= v; ++t) {
          if (!avail[t][i])
            availnow[i] = false;
        }
      }
      dij();
      cost[u][v] = dis[m];
      // cout << u << ' ' << v << endl;
      // for (int i = 1; i <= m; ++i) {
      //   cout << dis[i] << ' ';
      // }
      // cout << endl;
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i - 1; ++j) {
      if (cost[j + 1][i] < INF)
        dp[i] = min(dp[i], dp[j] + cost[j + 1][i] * (i - j) + (j == 0 ? 0 : k));
      // for (int i = 1; i <= n; ++i)
      //   cout << dp[i] << ' ';
      // cout << endl;
    }
  }
  // for (int i = 1; i <= n; ++i)
  //   cout << dp[i] << ' ';
  cout << dp[n] << endl;
  return 0;
}