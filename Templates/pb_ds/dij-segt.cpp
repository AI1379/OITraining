#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
constexpr const ll MAXN = 100010;
constexpr const ll INF = 1ll << (sizeof(ll) * 8 - 2);
static ll n, m, s;
static ll dis[MAXN];
vector<pll> graph[MAXN];
struct Node {
  ll l, r, val, pos;
};
static Node segt[MAXN * 4];
ll cmp(ll lhs, ll rhs) {
  return dis[lhs] < dis[rhs] ? lhs : rhs;
}
void build(ll beg, ll end, ll root) {
  if (beg == end) {
    segt[root].val = dis[beg];
    segt[root].pos = beg;
    segt[root].l = beg;
    segt[root].r = end;
    return;
  }
  ll mid = (beg + end) / 2;
  build(beg, mid, root * 2);
  build(mid + 1, end, root * 2 + 1);
  if (segt[root * 2].val < segt[root * 2 + 1].val) {
    segt[root].val = segt[root * 2].val;
    segt[root].pos = segt[root * 2].pos;
  } else {
    segt[root].val = segt[root * 2 + 1].val;
    segt[root].pos = segt[root * 2 + 1].pos;
  }
  segt[root].l = beg;
  segt[root].r = end;
}
void modify(ll pos, ll root, ll val) {
  if (segt[root].l == pos && segt[root].r == pos) {
    segt[root].val = val;
    return;
  }
  ll mid = (segt[root].l + segt[root].r) / 2;
  if (pos <= mid) {
    modify(pos, root * 2, val);
  } else {
    modify(pos, root * 2 + 1, val);
  }
  if (segt[root * 2].val < segt[root * 2 + 1].val) {
    segt[root].val = segt[root * 2].val;
    segt[root].pos = segt[root * 2].pos;
  } else {
    segt[root].val = segt[root * 2 + 1].val;
    segt[root].pos = segt[root * 2 + 1].pos;
  }
}
void dijkstra() {
  ll u, v, w;
  for (int i = 1; i <= n; i++) {
    dis[i] = INF;
  }
  dis[s] = 0;
  build(1, n, 1);
  while (segt[1].val != INF) {
    u = segt[1].pos;
    modify(u, 1, INF);
    for (pll obj : graph[u]) {
      v = obj.first;
      w = obj.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        modify(v, 1, dis[v]);
      }
    }
  }
}
int main() {
  ll u, v, w;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
  }
  dijkstra();
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << ' ';
  }
  cout << endl;
  return 0;
}
