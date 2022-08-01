#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll, ll> mp;
priority_queue<pair<ll, ll> > q;

const ll INF = 0x3f3f3f3f;
ll n, m, u, v, w, k, K, cnt;
ll st[1000010], dis[1000010], vis[1000010], g[30][30];
ll f[30][(1 << 13) + 50], val[1000010], head[1000010];

struct cc {
  ll x, y;
} e[1000010];

struct c {
  ll x, next, w;
} a[2000010];

void add(ll x, ll y, ll w) {
  a[++k].x = y;
  a[k].next = head[x];
  a[k].w = w;
  head[x] = k;
}

void Dijk(ll now) {
  ll s = st[now];
  memset(dis, INF, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  while (!q.empty()) q.pop();
  dis[s] = 0;
  vis[s] = 1;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    ll x = q.top().second;
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (int i = head[x]; i; i = a[i].next) {
      ll y = a[i].x;
      if (dis[y] > dis[x] + a[i].w) {
        dis[y] = dis[x] + a[i].w;
        q.push(make_pair(-dis[y], y));
      }
    }
  }
  for (int i = 1; i <= cnt; i++) g[now][i] = dis[st[i]];
}

int main() {
  scanf("%lld%lld%lld", &n, &m, &K);
  st[++cnt] = 1, mp[1] = cnt;
  for (int i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
    if (i <= K && !mp[u]) st[++cnt] = u, mp[u] = cnt;
    if (i <= K && !mp[v]) st[++cnt] = v, mp[v] = cnt;
    if (i <= K) e[i].x = mp[u], e[i].y = mp[v], val[i] = w;
  }
  for (ll i = 1; i <= cnt; i++) Dijk(i);
  memset(f, INF, sizeof(f));
  f[1][0] = 0;
  for (ll s = 0; s < (1 << K); s++) {
    for (ll i = 1; i <= cnt; i++) {
      if (f[i][s] == INF) continue;
      for (ll j = 0; j < K; j++) {
        if (!((s >> j) & 1)) {
          ll x = e[j + 1].x, y = e[j + 1].y;
          f[x][s | 1 << j] =
              min(f[x][s | 1 << j], f[i][s] + g[i][y] + val[j + 1]);
          f[y][s | 1 << j] =
              min(f[y][s | 1 << j], f[i][s] + g[i][x] + val[j + 1]);
        }
      }
      f[1][s] = min(f[1][s], f[i][s] + g[i][1]);
    }
  }
  printf("%lld", f[1][(1 << K) - 1]);
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}