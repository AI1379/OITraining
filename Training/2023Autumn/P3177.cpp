#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 2047;
ll n, k;
ll dp[MAXN][MAXN];
ll siz[MAXN];
vector<pll> tree[MAXN];
void dfs(ll u, ll fa) {
  siz[u] = 1;
  for (pll tmp : tree[u]) {
    ll v = tmp.first, w = tmp.second;
    if (v == fa)
      continue;
    dfs(v, u);
    siz[u] += siz[v];
    for (int i = min(k, siz[u]); i >= 0; --i) {
      if (dp[u][i] != -1) {
      }
    }
  }
}
int main() {
  ll u, v, w;
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v, w);
    tree[v].emplace_back(u, w);
  }
  dfs(1, 0);
  cout << dp[1][k] << endl;
  return 0;
}