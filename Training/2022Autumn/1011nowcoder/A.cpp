#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pll pair<ll, ll>
const ll MAXN = 500010;
#define state bitset<MAXN>
ull base_pow[MAXN];
random_device rd;
mt19937_64 rng(rd());
ll t;
ll n;
vector<pll> graph[MAXN];
ull dis[MAXN];
ll ans;
void dfs(ll u, ll fa) {
  for (auto obj : graph[u]) {
    if (obj.first != fa) {
      dis[obj.first] = dis[u] ^ obj.second;
      dfs(obj.first, u);
    }
  }
}
void solve() {
  static ll u, v, w;
  memset(dis, 0, sizeof(dis));
  cin >> n;
  map<ll, ull> valmp;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v >> w;
    if (valmp.find(w) == valmp.end()) valmp[w] = rng();
    graph[u].emplace_back(v, valmp[w]);
    graph[v].emplace_back(u, valmp[w]);
  }
  dfs(1, 0);
  map<ull, ll> ansmp;
  for (int i = 1; i <= n; ++i) ++ansmp[dis[i]];
  ans = n * (n - 1) / 2;
  for (auto obj : ansmp) ans -= obj.second * (obj.second - 1) / 2;
  cout << ans << endl;
  for (int i = 1; i <= n; ++i) graph[i].clear();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) solve();
  return 0;
}