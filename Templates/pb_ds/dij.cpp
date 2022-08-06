#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
constexpr const ll MAXN = 100010;
constexpr const ll INF = 1ll << (sizeof(ll) * 8 - 2);
static ll n, m, s;
static ll dis[MAXN];
vector<pll> graph[MAXN];
__gnu_pbds::priority_queue<pll, greater<pll>> q;
decltype(q)::point_iterator its[MAXN];
void dijkstra() {
  ll u;
  for (int i = 1; i <= n; i++) {
    dis[i] = INF;
  }
  dis[s] = 0;
  for (int i = 1; i <= n; i++) {
    its[i] = q.push(make_pair(dis[i], i));
  }
  while (!q.empty()) {
    u = q.top().second;
    q.pop();
    for (auto &&[v, d] : graph[u]) {
      if (dis[v] > dis[u] + d) {
        dis[v] = dis[u] + d;
        q.modify(its[v], make_pair(dis[u] + d, v));
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
