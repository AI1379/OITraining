#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define pos(i) ((((i)-1) % n + n) % n + 1)
const ll MAXN = 100010;
ll n;
ll a[MAXN];
ll ans[MAXN];
ll sum = 0;
vector<ll> graph[MAXN];
ll deg[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    if (a[pos(i - 1)] > a[i]) {
      graph[i].emplace_back(pos(i - 1));
      ++deg[pos(i - 1)];
    }
    if (a[pos(i + 1)] > a[i]) {
      graph[i].emplace_back(pos(i + 1));
      ++deg[pos(i + 1)];
    }
  }
  queue<pll> q;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) {
      q.emplace(i, 1);
    }
  }
  while (!q.empty()) {
    auto [p, v] = q.front();
    q.pop();
    ans[p] = v;
    sum += v;
    for (auto u : graph[p]) {
      --deg[u];
      if (deg[u] == 0)
        q.emplace(u, v + 1);
    }
  }
  cout << sum << endl;
  return 0;
}