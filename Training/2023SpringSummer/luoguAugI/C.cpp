#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 1000010;
ll n;
vector<ll> tree[MAXN];
pll dep[MAXN];
ll pre[MAXN];
void getdep(ll u, ll fa) {
  dep[u].first = dep[fa].first;
  for (auto v : tree[u]) {
    if (v == fa)
      continue;
    getdep(v, u);
  }
}
int main() {
  ll u, v;
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  getdep(1, 0);
  sort(dep + 1, dep + n + 1);
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + dep[i].first;
  }
  ll idx = 1;
  while (pre[idx] < pre[n] / 2)
    ++idx;
  while (idx <= n) {
  }
  return 0;
}