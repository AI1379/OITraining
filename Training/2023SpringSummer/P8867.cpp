#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 500010;
const ll MOD = 1000000007;
ll n, m;
vector<ll> graph[MAXN];
ll tre[MAXN], trv[MAXN], s[MAXN], cur = 0;
vector<ll> tree[MAXN];
ll dp[MAXN][2]; // root  exist and cross root
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
ll dfn[MAXN], low[MAXN], cnt = 0, bcc[MAXN];
ll stk[MAXN], top = 0;
void tarjan(ll u, ll fa) {
  dfn[u] = low[u] = ++cnt;
  stk[++top] = u;
  for (auto v : graph[u]) {
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (dfn[v] < dfn[u] && v != fa) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    ++cur;
    while (top > 0 && stk[top + 1] != u) {
      bcc[stk[top]] = cur;
      --top;
    }
  }
}
ll ans = 0;
void dfs(ll u, ll fa) {
  dp[u][0] = qpow(2, tre[u]);
  dp[u][1] = qpow(2, tre[u] + trv[u]);
  s[u] = tre[u];
  for (auto v : tree[u]) {
    if (v == fa)
      continue;
    dfs(v, u);
    dp[u][0] = dp[u][0] * 2 % MOD * dp[v][0] % MOD;
    dp[u][1] = dp[u][1] * (2 * dp[v][0] % MOD + dp[v][1]) % MOD;
    s[u] += s[v] + 1;
  }
  dp[u][1] = ((dp[u][1] - dp[u][0]) % MOD + MOD) % MOD;
}
int main() {
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  tarjan(1, 0);
  for (int i = 1; i <= n; ++i) {
    ++trv[bcc[i]];
    for (auto v : graph[i]) {
      if (bcc[v] == bcc[i])
        ++tre[bcc[i]];
      else
        tree[bcc[i]].emplace_back(bcc[v]);
    }
  }
  for (int i = 1; i <= cnt; ++i)
    tre[i] /= 2;
  dfs(1, 1);
  ans = dp[1][1];
  for (int i = 2; i <= cnt; ++i)
    ans = (ans + dp[i][1] * qpow(2, m - s[i] - 1)) % MOD;
  cout << ans << endl;
  return 0;
}