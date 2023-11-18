#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 500010;
ll n, m, k;
namespace Gen {
#define ui unsigned int
ui s;
unsigned ll ans = 0, res = 0;
inline ui get() {
  ui x = s;
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  return s = x;
}
} // namespace Gen
vector<ll> tree[MAXN];
ll fa[MAXN][31];
ll dep[MAXN];
void dfs(ll u) {
  dep[u] = dep[fa[u][0]] + 1;
  for (auto v : tree[u]) {
    if (v == fa[u][0])
      continue;
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
  ll u = 0, v = 0;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // cin >> Gen::seed1 >> Gen::seed2;
  cin >> n >> m >> Gen::s;
  for (int i = 1; i <= n; ++i) {
    cin >> fa[i][0];
    if (fa[i][0] == 0) {
      u = i;
    } else {
      tree[fa[i][0]].emplace_back(i);
      tree[i].emplace_back(fa[i][0]);
    }
  }
  dfs(u);
  for (int i = 1; (1 << i) <= n; ++i) {
    for (u = 1; u <= n; ++u) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
  }
  for (int i = 1; i <= m; ++i) {
    u = (Gen::get() ^ Gen::ans) % n + 1;
    v = (Gen::get() ^ Gen::ans) % dep[u];
    Gen::ans = query(u, v);
    Gen::res ^= i * Gen::ans;
    // cout << Gen::ans << endl;
  }
  cout << Gen::res << endl;
  return 0;
}