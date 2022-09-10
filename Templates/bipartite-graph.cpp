#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll MAXN = 510;
const ll MAXM = 510;
ll n, m, e;
vector<ll> graph[MAXN];
ll ans = 0;
bool vis[MAXM];
ll match[MAXM];
bool matched(ll u) {
  for (auto v : graph[u]) {
    if (!vis[v]) {
      vis[v] = true;
      if (!match[v] || matched(match[v])) {
        match[v] = u;
        return true;
      }
    }
  }
  return false;
}
int main() {
  ll u, v;
  cin >> n >> m >> e;
  for (int i = 1; i <= e; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    memset(vis, false, sizeof(vis));
    if (matched(i)) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
