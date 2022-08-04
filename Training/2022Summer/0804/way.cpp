#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;
#define ll long long
const ll MAXR = 1010;
const ll MAXA = 1010;
ll r, a, t;
pair<ll, ll>portals[MAXA];
pair<ll, ll>pos[MAXR];
ll v[MAXR];
bool vis[MAXA];
vector<ll> graph[MAXR];
ll match[MAXA];
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
  for (int i = 1; i <= r; i++) {
    memset(vis, false, sizeof(vis));
    if (rematch(i)) {
      ++res;
    }
  }
  return res;
}
int main() {
  cin >> r >> a >> t;
  for (int i = 1; i <= a; i++) {
    cin >> portals[i].first >> portals[i].second;
  }
  for (int i = 1; i <= r; i++) {
    cin >> pos[i].first >> pos[i].second >> v[i];
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= a; j++) {
      if (v[i] * v[i] * t * t
          >= abs(pos[i].first - portals[j].first) * abs(pos[i].first - portals[j].first)
          + abs(pos[i].second - portals[j].second) * abs(pos[i].second - portals[j].second)) {
        graph[i].push_back(j);
      }
    }
  }
  ll ans = bipartiteMaxMatch();
  cout << ans << endl;
  return 0;
}
