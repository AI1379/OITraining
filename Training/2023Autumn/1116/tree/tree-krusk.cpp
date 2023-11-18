#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Edge {
  ll u, v, w;
};
const ll MAXN = 100010;
ll n;
ll fa[MAXN];
ll val[MAXN];
ll fd(ll x) { return fa[x] == x ? x : fa[x] = fd(fa[x]); }
vector<Edge> edges;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
    fa[i] = i;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      edges.push_back(Edge{i, j, val[i] ^ val[j]});
    }
  }
  sort(edges.begin(), edges.end(),
       [](Edge lhs, Edge rhs) { return lhs.w < rhs.w; });
  ll idx = 0, res = 0;
  for (auto e : edges) {
    if (fd(e.u) == fd(e.v))
      continue;
    res += e.w;
    fa[fd(e.u)] = fd(e.v);
    ++idx;
    if (idx == n - 1)
      break;
  }
  cout << res << endl;
  return 0;
}