#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
constexpr const ll MAXN = 100010;
constexpr const ll INF = 1ll << (sizeof(ll) * 8 - 2);
static ll n, m, s;
static ll dis[MAXN];
vector<pll> graph[MAXN];
ll heap[MAXN], top = 0, idx[MAXN];
bool cmp(ll lhs, ll rhs) {
  return dis[lhs] > dis[rhs];
}

void pushUp(ll x) {
  while (x > 1) {
    if (cmp(heap[x / 2], heap[x])) {
      swap(idx[heap[x / 2]], idx[heap[x]]);
      swap(heap[x / 2], heap[x]);
      x /= 2;
    } else {
      break;
    }
  }
}

void pushDown(ll x) {
  ll s = x * 2;
  while (s <= top) {
    if (s <= top - 1 && cmp(heap[s], heap[s + 1])) {
      ++s;
    }
    if (cmp(heap[x], heap[s])) {
      swap(idx[heap[x]], idx[heap[s]]);
      swap(heap[x], heap[s]);
      x = s;
      s = x * 2;
    } else {
      break;
    }
  }
}
void dijkstra() {
  ll u, v, d;
  for (int i = 1; i <= n; i++) {
    dis[i] = INF;
    heap[i] = i;
    idx[i] = i;
  }
  dis[s] = 0;
  top = n;
  swap(idx[heap[s]], idx[heap[1]]);
  swap(heap[s], heap[1]);
  while (top > 0) {
    u = heap[1];
    swap(idx[heap[1]], idx[heap[top]]);
    swap(heap[1], heap[top]);
    --top;
    pushDown(1);
    for (pll obj : graph[u]) {
      v = obj.first;
      d = obj.second;
      if (dis[v] > dis[u] + d) {
        dis[v] = dis[u] + d;
        pushUp(idx[v]);
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
