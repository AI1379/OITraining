#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll MAXN = 500010;
ll n, m;
vector<ll> graph[MAXN];
ll low[MAXN], dfn[MAXN], idx = 0;
ll bcc[MAXN], stk[MAXN], top = 0, curbcc = 0;
vector<ll> tree[MAXN];
ll tree_e[MAXN], tree_v[MAXN];
ll dp[MAXN][2]; // dp[u][0] 不取u dp[u][1] 取u
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
void tarjan(ll u, ll fa) {
  low[u] = dfn[u] = ++idx;
  stk[++curbcc] = u;
  for (auto v : graph[u]) {
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (dfn[v] < dfn[u] && v != fa) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    ++curbcc;
    while (top && stk[top + 1] != u) {
      bcc[stk[top]] = curbcc;
      --top;
    }
  }
}
void dfs(ll u) {
  dp[u][0] = qpow(2, tree_e[u]);
  dp[u][1] = qpow(2, tree_v[u] + tree_e[u]);
  for (auto v : tree[u]) {
  }
}
int main() {
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
  }
  tarjan(1, 0);
  for (u = 1; u <= n; ++u) {
    ++tree_v[bcc[u]];
    for (auto v : graph[u]) {
      if (bcc[u] == bcc[v]) {
        ++tree_e[bcc[u]];
      } else {
        tree[bcc[u]].emplace_back(bcc[v]);
        tree[bcc[v]].emplace_back(bcc[u]);
      }
    }
  }
  for (int i = 1; i <= curbcc; ++i) {
    tree_e[i] /= 2;
  }
  dfs(1);
  return 0;
}