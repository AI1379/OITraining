#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
constexpr const ll MAXN = 100010;
constexpr const ll INF = 1ll << (sizeof(ll) * 8 - 2);
static ll n, m, s;
static ll dis[MAXN];
vector<pll> graph[MAXN];
ll heap[MAXN], top = 0;
bool cmp(ll lhs, ll rhs) {
  return dis[lhs] > dis[rhs];
}
void pushUp(ll pos) {
  while (pos && dis[heap[pos / 2]] > dis[heap[pos]]) {
    swap(heap[pos / 2], heap[pos]);
    pos /= 2;
  }
}
void dijkstra() {
  ll u;
  for (int i = 1; i <= n; i++) {
    dis[i] = INF;
    heap[i] = i;
  }
  dis[s] = 0;
  top = n;
  make_heap(heap + 1, heap + top + 1, cmp);
  while (top > 0) {
    u = heap[1];
    pop_heap(heap + 1, heap + top + 1, cmp);
    --top;
    for (auto &&[v, d] : graph[u]) {
      if (dis[v] > dis[u] + d) {
        dis[v] = dis[u] + d;
        pushUp(v);
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
