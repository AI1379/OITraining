#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n;
vector<ll> tree[MAXN];
ll val[MAXN], *dp[MAXN], *cur, ans[MAXN];
ll len[MAXN], prefer[MAXN];
void decomposition(ll u, ll f) {
  for (auto v : tree[u]) {
    if (v == f)
      continue;
    decomposition(v, u);
    if (len[v] > len[prefer[u]])
      prefer[u] = v;
  }
  len[u] = len[prefer[u]] + 1;
}
void dfs(ll u, ll f) {
  dp[u][0] = 1;
  if (prefer[u]) {
    dp[prefer[u]] = dp[u] + 1;
    dfs(prefer[u], u);
    ans[u] = ans[prefer[u]] + 1;
  }
  for (auto v : tree[u]) {
    if (v == f || v == prefer[u])
      continue;
    dp[v] = cur;
    cur += len[v];
    dfs(v, u);
    for (int i = 1; i <= len[v]; ++i) {
      dp[u][i] += dp[v][i - 1];
      if ((i < ans[u] && dp[u][i] >= dp[u][ans[u]]) ||
          (i > ans[u] && dp[u][i] > dp[u][ans[u]]))
        ans[u] = i;
    }
  }
  if (dp[u][ans[u]] == 1)
    ans[u] = 0;
}
int main() {
  ll u, v;
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  decomposition(1, 0);
  dp[1] = cur = val;
  cur += len[1];
  dfs(1, 0);
  for (int i = 1; i <= n; ++i)
    cout << ans[i] << endl;
  return 0;
}