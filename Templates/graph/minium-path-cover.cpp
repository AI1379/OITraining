#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
const ll MAXN = 1010;
ll n, m;
bool vis[MAXN];
vector<ll> graph[MAXN];
ll match[MAXN];
bool rematch(ll u) {
  for (auto v : graph[u]) {
    if (!vis[v]) {
      vis[v] = true;
      if (!match[v] || rematch(match[v])) {
        match[v] = u;
        return true;
      }
    }
  }
  return false;
}
ll bipartiteMaxMatch() {
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    memset(vis, false, sizeof(vis));
    if (rematch(i)) {
      ++res;
    }
  }
  return res;
}
int main() {
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
  }
  ll ans = n - bipartiteMaxMatch();
  cout << ans << endl;
  return 0;
}
