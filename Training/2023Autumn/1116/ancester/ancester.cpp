#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, m, k;
vector<ll> tree[MAXN];
namespace Gen {
unsigned int seed1, seed2;
unsigned int tseed = 0, ans = 0, mul = 1;
void getquery(ll &x, ll &d) {
  tseed = (tseed * seed1 + seed2) ^ ans;
  x = tseed % n + 1;
  tseed = (tseed * seed1 + seed2) ^ ans;
  d = tseed % k;
}
void update(ll t) {
  ans = ans + mul * t + seed2;
  mul = mul * seed2;
}
} // namespace Gen
ll fa[MAXN][31];
void dfs(ll u) {
  for (auto v : tree[u]) {
    if (v == fa[u][0])
      continue;
    fa[v][0] = u;
    dfs(v);
  }
}
ll query(ll x, ll d) {
  ll cur = x, idx = 0;
  while (d) {
    if (d & 1)
      cur = fa[cur][idx];
    ++idx;
    d >>= 1;
  }
  return cur;
}
int main() {
  freopen("ancester.in", "r", stdin);
  freopen("ancester.out", "w", stdout);
  ll u, v;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> Gen::seed1 >> Gen::seed2;
  cin >> n >> m >> k;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  dfs(1);
  for (int i = 1; (1 << i) <= n; ++i) {
    for (u = 1; u <= n; ++u) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
  }
  for (int i = 1; i <= m; ++i) {
    Gen::getquery(u, v);
    Gen::update(query(u, v));
  }
  cout << Gen::ans << endl;
  return 0;
}