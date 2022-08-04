#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long
const ll MAXN = 1010;
ll n;
bool vis[MAXN];
vector<ll> graph[MAXN];
ll match[MAXN];
bool rematch(ll u) {
  for (auto v : graph[u]) {
    if (!vis[v]) {
      vis[v] = true;
      if (!match[v] || rematch(match[v])) {
        match[v] = u;
        return true;
      }
    }
  }
  return false;
}
ll bipartiteMaxMatch() {
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    memset(vis, false, sizeof(vis));
    if (rematch(i)) {
      ++res;
    }
  }
  return res;
}
tuple<ll, ll, ll> missile[MAXN];
bool check(const tuple<ll, ll, ll>& lhs, const tuple<ll, ll, ll>& rhs) {
  return (get<0>(lhs) < get<0>(rhs))
         && (get<1>(lhs) < get<1>(rhs))
         && (get<2>(lhs) < get<2>(rhs));
}
ll lis() {
  static ll dp[MAXN];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (check(missile[j], missile[i])) {
        dp[i] = max(dp[i], dp[j]);
      }
    }
    ++dp[i];
  }
  return dp[n];
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> get<0>(missile[i]) >> get<1>(missile[i]) >> get<2>(missile[i]);
  }
  cout << lis() << endl;
  sort(missile + 1, missile + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (check(missile[i], missile[j])) {
        graph[i].push_back(j);
      }
    }
  }
  ll ans = n - bipartiteMaxMatch();
  cout << ans << endl;
  return 0;
}
