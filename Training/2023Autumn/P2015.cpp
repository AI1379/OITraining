#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 127;
ll n, q;
vector<pll> tree[MAXN];
ll dp[MAXN][MAXN];
ll siz[MAXN];
void dfs(ll u, ll fa) {
  siz[u] = 1;
  for (auto tmp : tree[u]) {
    ll v = tmp.first, w = tmp.second;
    if (v == fa)
      continue;
    dfs(v, u);
    siz[u] += siz[v];
    for (int i = min(siz[u], q); i >= 1; --i) {
      for (int j = min(siz[v], i - 1ll); j >= 0; --j) {
        dp[u][i] = max(dp[u][i], dp[u][i - j - 1] + dp[v][j] + w);
      }
    }
    // for (int i = 1; i <= siz[u] - 1 && i <= q; ++i) {
    //   for (int j = 0; j <= siz[v] - 1 && j < i && j <= q; ++j) {
    //   }
    //   // cout << u << ' ' << i << ' ' << v << ' ' << w << ' ' << dp[u][i] <<
    //   endl;
    // }
  }
}
int main() {
  ll u, v, w;
  cin >> n >> q;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v >> w;
    tree[u].emplace_back(v, w);
    tree[v].emplace_back(u, w);
  }
  dfs(1, 0);
  cout << dp[1][q] << endl;
  return 0;
}
/**
5 2
1 3 1
1 4 10
2 3 20
3 5 20

21

**/