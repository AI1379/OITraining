#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXK = 512;
const ll MAXN = 512;
ll n, k;
vector<ll> tree[MAXK][MAXN];
ll res;
bitset<MAXN> all[MAXN];
bitset<MAXN> st[MAXN];
void dfs(int num, int u, int fa) {
  st[u] = st[fa];
  st[u][u] = true;
  for (auto v : tree[num][u]) {
    if (v != fa) dfs(num, v, u);
  }
  all[u] &= st[u];
}
void solve(int u) {
  for (int i = 1; i <= n; i++) all[i].set();
  for (int i = 1; i <= k; i++) {
    dfs(i, u, 0);
  }
  res = 0;
  for (int i = 1; i <= n; i++) {
    res += i * all[i].count();
  }
  printf("%lld\n", res);
  return;
}
int main() {
  ll u, v;
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n - 1; j++) {
      scanf("%lld%lld", &u, &v);
      tree[i][u].push_back(v);
      tree[i][v].push_back(u);
    }
  }
  st[0].reset();
  for (int i = 1; i <= n; i++) solve(i);
#ifdef DEBUG
  system("pause");
#endif
}