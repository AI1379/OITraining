#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;

ll n, m, k;
vector<ll> graph[MAXN];
ll parent[MAXN];
ll dfn[MAXN], low[MAXN], idx = 0;
ll stk[MAXN], top = 0;
ll ecut_num = 0;
bool is_ecut[MAXN];
ll ans;
ll cnt = 0;
ll loopsize[MAXN];
ll prelpsiz[MAXN];
void tarjan(ll u, ll fa) {
  dfn[u] = low[u] = ++idx;
  parent[u] = fa;
  stk[++top] = u;
  ll child = 0;
  if (graph[u].size() == 0) {
    loopsize[++cnt] = 1;
    return;
  }
  for (auto v : graph[u]) {
    if (!dfn[v]) {
      ++child;
      tarjan(v, u);
      low[u] = min(low[v], low[u]);
      if (low[v] > dfn[u] && !is_ecut[u]) {
        is_ecut[v] = true;
        ++ecut_num;
      }
      if (low[v] >= dfn[u]) {
        ++cnt;
        while (top && stk[top + 1] != v) {
          ++loopsize[cnt];
          --top;
        }
        ++loopsize[cnt];
      }
    } else if (fa != v) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll u, v;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i, 0);
      ++ans;
    }
  }
  if (ecut_num >= k) {
    ans += k;
    goto output;
  }
  ans += ecut_num;
  k -= ecut_num;
  sort(loopsize + 1, loopsize + cnt + 1, greater<ll>());
  for (int i = 1; i <= cnt; ++i) {
    if (loopsize[i] == 1) {
      cnt = i - 1;
      break;
    }
    prelpsiz[i] = prelpsiz[i - 1] + loopsize[i];
  }
  u = upper_bound(prelpsiz + 1, prelpsiz + cnt + 1, k) - prelpsiz - 1;
  ans += prelpsiz[u] - u;
  k -= prelpsiz[u];
  if (k > 0)
    ans += k - 1;
output:
  cout << ans << endl;
  return 0;
}
