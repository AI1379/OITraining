#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 500010;
static ll n, m, q, cur;
vector<ll> graph[MAXN], invg[MAXN];
static ll deg[MAXN], indeg[MAXN];
static bool avail[MAXN];
map<pll, bool> des;
ll num;
void modify1() {
  static ll u, v;
  cin >> u >> v;
  des[{u, v}] = true;
  if (deg[u] == 1)
    --num;
  --deg[u];
  if (deg[u] == 1)
    ++num;
  --indeg[v];
  if (indeg[v] == 0) {
    --cur;
    avail[v] = false;
  }
}
void modify2() {
  static ll v;
  cin >> v;
  for (const ll &u : invg[v]) {
    if (des[{u, v}])
      continue;
    des[{u, v}] = true;
    if (deg[u] == 1)
      --num;
    --deg[u];
    if (deg[u] == 1)
      ++num;
  }
  --cur;
  avail[v] = false;
  indeg[v] = 0;
}
void modify3() {
  static ll u, v;
  cin >> u >> v;
  des[{u, v}] = false;
  if (deg[u] == 1)
    --num;
  ++deg[u];
  if (deg[u] == 1)
    ++num;
  if (indeg[v] == 0) {
    ++cur;
    avail[v] = true;
  }
  ++indeg[v];
}
void modify4() {
  static ll v;
  cin >> v;
  for (const ll &u : invg[v]) {
    if (!des[{u, v}])
      continue;
    des[{u, v}] = false;
    if (deg[u] == 1)
      --num;
    ++deg[u];
    if (deg[u] == 1)
      ++num;
  }
  ++cur;
  avail[v] = true;
  indeg[v] = invg[v].size();
}
void (*modify[])() = {nullptr, &modify1, &modify2, &modify3, &modify4};
int main() {
#ifndef DEBUG
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
  static ll opt, u, v;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    graph[u].emplace_back(v);
    invg[v].emplace_back(u);
    ++deg[u];
    ++indeg[v];
  }
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 1)
      ++num;
  }
  cur = n;
  memset(avail, true, sizeof(avail));
  cin >> q;
  while (q--) {
    cin >> opt;
    modify[opt]();
    if (num == n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}