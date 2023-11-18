#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n;
vector<ll> tree[MAXN];
ll dep[MAXN], siz[MAXN];
ll dp[MAXN];
void dfs(ll u, ll fa) {
  siz[u] = 1;
  for (auto v : tree[u]) {
    if (v == fa)
      continue;
    dfs(v, u);
    siz[u] += siz[v];
    dep[u] += dep[v] + siz[v];
  }
}
void dfs2(ll u, ll fa) {
  for (auto v : tree[u]) {
    if (v == fa)
      continue;
    dp[v] = dp[u] - siz[v] + n - siz[v];
    dfs2(v, u);
  }
}
int main() {
  ll u, v;
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  dfs(1, 0);
  dp[1] = dep[1];
  dfs2(1, 0);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    // cout << dp[i] << ' ';
    if (dp[ans] < dp[i])
      ans = i;
  }
  cout << ans << endl;
  return 0;
}