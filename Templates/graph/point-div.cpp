// P3806
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 1000010;
ll n, m;
vector<pll> tree[MAXN];
ll sum, rt = 0;
bool vis[MAXN];
ll siz[MAXN], maxs[MAXN];
ll dist[MAXN], dd[MAXN], cnt;
ll query[MAXN];
bool exist[MAXN], res[MAXN];
ll tag[MAXN], tot = 0;
void getsize(ll u, ll fa) {
  siz[u] = 1;
  maxs[u] = 0;
  for (auto [v, w] : tree[u]) {
    if (v == fa || vis[v])
      continue;
    getsize(v, u);
    maxs[u] = max(maxs[u], siz[v]);
    siz[u] += siz[v];
  }
  maxs[u] = max(maxs[u], sum - siz[u]);
  if (maxs[u] < maxs[rt])
    rt = u;
}
void getdist(ll u, ll fa) {
  dd[++cnt] = dist[u];
  for (auto [v, w] : tree[u]) {
    if (v == fa || vis[v])
      continue;
    dist[v] = dist[u] + w;
    getdist(v, u);
  }
}
void dfs(ll u, ll fa) {
  exist[0] = true;
  tag[++tot] = 0;
  vis[u] = true;
  for (auto [v, w] : tree[u]) {
    if (v == fa || vis[v])
      continue;
    dist[v] = w;
    getdist(v, u);
    for (int k = 1; k <= cnt; ++k) {
      for (int i = 1; i <= m; ++i) {
        if (query[i] >= dd[k]) {
          res[i] |= exist[query[i] - dd[k]];
        }
      }
    }
    for (int k = 1; k <= cnt; ++k) {
      if (dd[k] <= 1e7) {
        tag[++tot] = dd[k];
        exist[dd[k]] = true;
      }
    }
    cnt = 0;
  }
  while (tot)
    exist[tag[tot--]] = false;
  for (auto [v, w] : tree[u]) {
    if (v == fa || vis[v])
      continue;
    sum = siz[v];
    rt = 0;
    maxs[rt] = 1e9;
    getsize(v, u);
    getsize(rt, -1);
    dfs(rt, u);
  }
}
int main() {
  ll u, v, w;
  cin >> n >> m;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v >> w;
    tree[u].emplace_back(v, w);
    tree[v].emplace_back(u, w);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> query[i];
  }
  maxs[rt] = 1e9;
  sum = n;
  getsize(1, 0);
  getsize(rt, 0);
  dfs(rt, 0);
  for (int i = 1; i <= m; ++i) {
    if (res[i])
      cout << "AYE" << endl;
    else
      cout << "NAY" << endl;
  }
  return 0;
}