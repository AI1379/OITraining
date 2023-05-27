#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 200010;
const ll MAXM = 200010;
struct Edge {
  ll u, v, w;
};
ll n, m;
namespace GetWX {
ll wx;
ll w[MAXM];
void run() {
  ll f = 0, sum = 0;
  for (int k = 0; k < 32; ++k) {
    f = sum = 0;
    for (int i = 1; i <= m - 1; ++i) {
      if ((w[i] >> k) & 1) f = i - f;
      sum += f;
    }
    wx += (sum << k);
  }
}
}  // namespace GetWX
namespace SecondMST {
ll fa[MAXN];
ll ans;
bool choose[MAXM];
ll st[31][MAXN], maxe[31][MAXN], sndmaxe[31][MAXN];
ll dep[MAXN];
Edge edges[MAXM];
vector<pll> tree[MAXN];
ll mst;
ll log2n[MAXM];
void init() {
  for (int i = 1; i <= n; ++i) fa[i] = i;
  log2n[0] = log2n[1] = 1;
  for (int i = 2; i <= m; ++i) log2n[i] = log2n[i / 2] + 1;
}
ll find(ll x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void dfs(ll u) {
  for (int i = 1; i < 32; ++i) {
    st[i][u] = st[i - 1][st[i - 1][u]];
    if (maxe[i - 1][u] > maxe[i - 1][st[i - 1][u]]) {
      maxe[i][u] = maxe[i - 1][u];
      sndmaxe[i][u] = max(sndmaxe[i - 1][u], maxe[i - 1][st[i - 1][u]]);
    } else if (maxe[i - 1][u] == maxe[i - 1][st[i - 1][u]]) {
      maxe[i][u] = maxe[i - 1][u];
      sndmaxe[i][u] = max(sndmaxe[i - 1][i], sndmaxe[i - 1][st[i - 1][u]]);
    } else {
      maxe[i][u] = maxe[i - 1][st[i - 1][u]];
      sndmaxe[i][u] = max(sndmaxe[i - 1][st[i - 1][u]], maxe[i - 1][u]);
    }
  }
  for (auto obj : tree[u]) {
    if (obj.first != st[0][u]) {
      st[0][obj.first] = u;
      maxe[0][obj.first] = obj.second;
      sndmaxe[0][obj.first] = 0;
      dep[obj.first] = dep[u] + 1;
      dfs(obj.first);
    }
  }
}
ll query(ll u, ll v, ll w) {
  if (dep[u] < dep[v]) swap(u, v);
  ll diff = dep[u] - dep[v], s = log2n[diff];
  ll maxw, sndmaxw;
  while (dep[u] != dep[v]) {
    if (dep[st[s][u]] >= dep[v]) u = st[s][u];
    --s;
  }
  for (int k = 31; k >= 0; --k) {
    if (st[k][u] != st[k][v]) {
      u = st[k][u];
      v = st[k][v];
      if (maxe[k][u] > maxe[k][v]) {
        maxw = maxe[k][u];
        sndmaxw = max(maxe[k][v], max(sndmaxe[k][u], sndmaxe[k][v]));
      } else if (maxe[k][u] == maxe[k][v]) {
        maxw = maxe[k][u];
        sndmaxw = max(sndmaxe[k][u], sndmaxe[k][v]);
      } else {
        maxw = maxe[k][v];
        sndmaxw = max(maxe[k][u], max(sndmaxe[k][u], sndmaxe[k][v]));
      }
    }
  }
  if (maxw < w)
    return mst - maxw + w;
  else
    return mst - sndmaxw + w;
}
void run() {
  init();
  sort(edges + 1, edges + m + 1,
       [](const Edge& lhs, const Edge& rhs) { return lhs.w < rhs.w; });
  for (int i = 1, j = 0; i <= m && j <= n - 1; ++i) {
    if (find(edges[i].u) != find(edges[i].v)) {
      fa[find(edges[i].u)] = find(edges[i].v);
      ++j;
      choose[i] = true;
      tree[edges[i].u].emplace_back(edges[i].v, edges[i].w);
      tree[edges[i].v].emplace_back(edges[i].u, edges[i].w);
      mst += edges[i].w;
    }
  }
  dfs(1);
  ans = (1ll << (sizeof(ll) * 8 - 2));
  for (int i = 1; i <= m; ++i) {
    if (choose[i]) continue;
    ans = min(ans, query(edges[i].u, edges[i].v, edges[i].w));
  }
}
}  // namespace SecondMST
int main() {
  using SecondMST::edges;
  cin >> n >> m;
  for (int i = 1; i <= m - 1; ++i) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
    GetWX::w[i] = edges[i].w;
  }
  cin >> edges[m].u >> edges[m].v;
  GetWX::run();
  edges[m].w = GetWX::wx;
  SecondMST::run();
  cout << SecondMST::ans << endl;
  return 0;
}