#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 500010;
ll n, m, s;
vector<ll> tree[MAXN];
ll cnt = 0;
ll pos[MAXN], st[MAXN * 2][50];
void dfs(ll u, ll fa) {
  pos[u] = ++cnt;
  st[cnt][0] = u;
  for (auto v : tree[u]) {
    if (v == fa) continue;
    dfs(v, u);
    st[++cnt][0] = u;
  }
  return;
}
void init() {
  ll x, y;
  dfs(s, 0);
  for (int j = 1; (1 << j) <= 2 * n - 1; j++) {
    for (int i = 1; i + (1 << j) <= 2 * n; i++) {
      x = st[i][j - 1];
      y = st[i + (1 << (j - 1))][j - 1];
      st[i][j] = pos[x] < pos[y] ? x : y;
    }
  }
  return;
}
ll query(ll l, ll r) {
  if (pos[l] > pos[r]) swap(l, r);
  ll x, a, b;
  x = log2(pos[r] - pos[l] + 1);
  a = st[pos[l]][x];
  b = st[pos[r] - (1 << x) + 1][x];
  return pos[a] < pos[b] ? a : b;
}
int main() {
  ll u, v, lca;
  scanf("%lld%lld%lld", &n, &m, &s);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%lld%lld", &u, &v);
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  init();
  while (m--) {
    scanf("%lld%lld", &u, &v);
    lca = query(u, v);
    printf("%lld\n", lca);
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}