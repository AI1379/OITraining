#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200010;
ll n;
vector<pair<ll, ll>> graph[MAXN];
ll fa[MAXN], dfn[MAXN];
ll cycle[MAXN * 2];
bool in_cycle[MAXN];
ll vs = 0, cycle_size = 0;
void get_cycle(int u) {
  ll v;
  dfn[u] = ++vs;
  for (auto x : graph[u]) {
    v = x.first;
    if (v == fa[u]) continue;
    if (dfn[v]) {
      if (dfn[v] < dfn[u]) continue;
      in_cycle[v] = true;
      cycle[++cycle_size] = v;
      for (; v != u; v = fa[v]) {
        in_cycle[fa[v]] = true;
        cycle[++cycle_size] = fa[v];
      }
    } else {
      fa[v] = u;
      get_cycle(v);
    }
  }
}
ll maxdep[MAXN * 2], d[MAXN * 2];
ll dis[MAXN * 2];
ll maxd = 0, src, num;
ll maxpos;
bool flag;
void dfs(ll u, ll f, ll dep) {
  for (auto x : graph[u]) {
    auto v = x.first, w = x.second;
    if (v != f && (!in_cycle[v] || (in_cycle[v] && v == src))) {
      if (dep + w > maxdep[src] && flag) {
        maxdep[src] = dep + w;
        maxpos = v;
      } else if (!flag) {
        d[src] = max(d[src], dep + w);
        maxd = max(maxd, dep + w);
      }
      dfs(v, u, dep + w);
    }
  }
}
void reget_cycle(ll u, ll f, ll dep) {
  if (dep > cycle_size * 2) return;
  cycle[dep] = u;
  for (auto x : graph[u]) {
    auto v = x.first, w = x.second;
    if (v != f && in_cycle[v]) {
      dis[dep + 1] = w;
      reget_cycle(v, u, dep + 1);
    }
  }
}
ll pre[MAXN], sub[MAXN];
ll ans = 0x3fffffffffffffff;
int main() {
  ll u, v, w;
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld%lld", &u, &v, &w);
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }
  get_cycle(1);
#ifdef DEBUG
  for (int i = 1; i <= cycle_size; i++) printf("%lld\n", cycle[i]);
#endif
  reget_cycle(cycle[1], 0, 1);
  dis[1] = dis[cycle_size + 1];
#ifdef DEBUG
  for (int i = 1; i <= 2 * cycle_size; i++)
    printf("%lld %lld\n", cycle[i], dis[i]);
#endif
  for (int i = 1; i <= cycle_size; i++) {
    src = cycle[i];
    num = i;
    flag = true;
    maxpos = cycle[i];
    dfs(cycle[i], 0, 0);
    flag = false;
    dfs(maxpos, 0, 0);
    maxdep[cycle_size + i] = maxdep[i];
    d[cycle_size + i] = d[i];
  }
#ifdef DEBUG
  for (int i = 1; i <= cycle_size * 2; i++)
    printf("%lld %lld %lld\n", cycle[i], maxdep[i], d[i]);
#endif
  ll cnt = 0;
  for (int i = 1; i <= cycle_size; i++) {
    cnt += dis[i];
    pre[i] = max(pre[i - 1], cnt + maxdep[i]);
  }
  cnt = 0;
  for (int i = cycle_size; i >= 1; i++) {
    cnt += dis[i + 1];
    sub[i] = max(sub[i + 1], cnt + maxdep[i]);
  }
  for (int i = 1; i <= cycle_size - 1; i++) {
    u = cycle[i];
    v = cycle[i + 1];
    ans = min(ans, pre[u] + sub[v] - dis[1]);
  }
  ans = max(ans, maxd);
  printf("%lld\n", ans);
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}

/*
5
2 3 7
3 1 9
4 1 8
3 5 4
4 5 5


18
*/