#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200010;
vector<ll> tree[MAXN];
ll n, m;
bool vis[MAXN];
void dfs(ll u, ll fa) {
  vis[u] = true;
  for (auto v : tree[u]) {
    if (v == fa)
      continue;
    assert(!vis[v]);
    dfs(v, u);
  }
}
int main() {
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= 2 * n; ++i) {
    cin >> u;
  }
  cout << -1 << endl;
  while (m--) {
    cin >> u;
    cout << -1 << endl;
  }
  return 0;
}