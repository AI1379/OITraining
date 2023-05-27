#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 500010;
ll n;
char val[MAXN];
ll fa[MAXN];
vector<ll> tree[MAXN];
ll ans[MAXN];
ll pre[MAXN], cnt[MAXN];
ll res = 0;
void dfs(ll u) {
  if (val[u] == ')') {
    if (pre[fa[u]] != 0) {
      pre[u] = pre[fa[pre[fa[u]]]];
      ans[u] = ans[fa[u]] + cnt[fa[pre[fa[u]]]] + 1;
      cnt[u] = cnt[fa[pre[fa[u]]]] + 1;
    } else {
      pre[u] = pre[fa[u]];
      ans[u] = ans[fa[u]];
    }
  } else {
    pre[u] = u;
    ans[u] = ans[fa[u]];
  }
  for (auto v : tree[u]) {
    if (v != fa[u]) dfs(v);
  }
}
int main() {
  scanf("%lld", &n);
  scanf("%s", val + 1);
  for (int i = 2; i <= n; ++i) {
    scanf("%lld", fa + i);
    tree[fa[i]].emplace_back(i);
    tree[i].emplace_back(fa[i]);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) res ^= i * ans[i];
  printf("%lld\n", res);
  return 0;
}