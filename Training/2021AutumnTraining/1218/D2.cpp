#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 5010;
const ll MAXM = 5010;
ll n, m;
vector<pair<ll, ll>> graph[MAXN];
ll deg[MAXN];
queue<pair<ll, ll>> q;
ll ans = 0;
ll fa[MAXN];
ll siz[MAXN];
bool vis[MAXN];
ll fd(ll x) { return fa[x] == x ? fa[x] : (fa[x] = fd(fa[x])); }
ll op[MAXM], a[MAXM], b[MAXM];
int main() {
  cin >> n >> m;
  ll opt, x, y;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    siz[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    cin >> op[i] >> a[i] >> b[i];
    if (op[i] == 5) {
      x = fd(a[i]);
      y = fd(b[i]);
      if (x != y) {
        fa[x] = y;
        siz[y] += siz[x];
        siz[x] = 0;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    opt = op[i];
    x = fd(a[i]);
    y = fd(b[i]);
    if (opt == 5) continue;
    if (opt == 1 || opt == 2) {
      deg[y]++;
      graph[x].push_back(make_pair(y, opt));
    } else {
      deg[x]++;
      graph[y].push_back(make_pair(x, opt));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0 && fd(i) == i) {
      vis[i] = true;
      q.push(make_pair(i, 1));
    }
  }
  ll h, v, u;
  while (!q.empty()) {
    u = fd(q.front().first);
    h = q.front().second;
    q.pop();
    if (vis[u]) continue;
    ans += (h * siz[u]);
#ifdef DEBUG
    printf("%lld %lld %lld\n", u, h, siz[u]);
#endif
    for (auto x : graph[u]) {
      opt = x.second;
      v = fd(x.first);
      deg[v]--;
      if (deg[v] == 0) {
        q.push(make_pair(v, h + 1 - opt % 2));
      }
    }
  }
  printf("%lld\n", ans);
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}