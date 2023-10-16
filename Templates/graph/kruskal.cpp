#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200010;
const ll MAXM = 500010;
struct Edge {
  ll u, v, w;
};
ll n, m;
Edge edges[MAXM];
ll fa[MAXN];
ll find(ll x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  sort(edges + 1, edges + m + 1,
       [](Edge lhs, Edge rhs) { return lhs.w < rhs.w; });
  ll ans = 0, cnt = 0;
  for (int i = 1; i <= m; ++i) {
    if (find(edges[i].u) == find(edges[i].v))
      continue;
    ans += edges[i].w;
    fa[find(edges[i].u)] = find(edges[i].v);
    ++cnt;
    if (cnt == n - 1)
      break;
  }
  cout << ans << endl;
  return 0;
}