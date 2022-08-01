#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 50010;
const ll MAXM = 200010;
struct node {
  ll v, d;
};
struct cmp {
  bool operator()(node a, node b) { return a.d > b.d; }
};
ll n, m, k;
vector<pair<ll, ll>> graph[MAXN];
ll bridge[30], len[30];
ll dis[30][MAXN];
ll f[30][(1 << 13) + 10];
void dijkstra(int upos) {
  ll u = bridge[upos], v, d;
  priority_queue<node, vector<node>, cmp> q;
  q.push((node){u, 0});
  dis[upos][u] = 0;
  while (!q.empty()) {
    auto x = q.top();
    q.pop();
    if (x.d > dis[upos][x.v]) continue;
    u = x.v;
    for (auto ed : graph[u]) {
      v = ed.first;
      d = ed.second;
      if (dis[upos][v] > dis[upos][u] + d) {
        dis[upos][v] = dis[upos][u] + d;
        q.push((node){v, dis[upos][v]});
      }
    }
  }
#ifdef DEBUG
  for (int i = 1; i <= n; i++) {
    printf("%lld ", dis[upos][i]);
  }
  printf("\n");
#endif
}
ll ans = 0;
int main() {
  ll u, v, w;
  memset(dis, 0x3f, sizeof(dis));
  scanf("%lld%lld%lld", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &u, &v, &w);
    if (i <= k) {
      bridge[i] = u;
      bridge[i + k] = v;
      len[i] = w;
    }
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }
  bridge[0] = 1;
  for (int i = 0; i <= 2 * k; i++) dijkstra(i);
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (ll s = 0; s < (1 << k); s++) {
    for (ll i = 0; i <= 2 * k; i++) {
      if (f[i][s] >= 0x3f3f3f3f) continue;
      for (ll j = 0; j < k; j++) {
        if (!((s >> j) & 1)) {
          ll x = bridge[j + 1], y = bridge[(j + 1) * 2];
          f[x][s | 1 << j] =
              min(f[x][s | 1 << j], f[i][s] + dis[i][bridge[y]] + len[j + 1]);
          f[y][s | 1 << j] =
              min(f[y][s | 1 << j], f[i][s] + dis[i][bridge[x]] + len[j + 1]);
        }
      }
      f[0][s] = min(f[0][s], f[i][s] + dis[i][bridge[1]]);
    }
  }
  printf("%lld", f[0][(1 << k) - 1]);
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}