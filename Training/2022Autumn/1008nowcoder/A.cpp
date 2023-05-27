#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define edge tuple<ll, ll, ll>
const ll MAXN = 5010;
static ll n, m;
static ll a[MAXN];
vector<edge> edges;
// static edge edges[MAXN * MAXN];
static ll ans = 0;
static bool vis[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  // scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; ++i) {
    // scanf("%lld", a + i);
    cin >> a[i];
  }
  edges.reserve(n * (n + 1) / 2);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      edges.emplace_back(make_tuple(i, j, abs(a[i] - a[j])));
    }
  }
  sort(edges.begin(), edges.end(), [](const edge& lhs, const edge& rhs) {
    return get<2>(lhs) < get<2>(rhs);
  });
  for (int cnt = 0, i = 0; cnt < m && i < (int)edges.size(); ++i) {
    if (!vis[get<0>(edges[i])] && !vis[get<1>(edges[i])]) {
      ans += get<2>(edges[i]);
      ++cnt;
      vis[get<0>(edges[i])] = vis[get<1>(edges[i])] = true;
    }
  }
  // printf("%lld\n", ans);
  cout << ans << endl;
  return 0;
}