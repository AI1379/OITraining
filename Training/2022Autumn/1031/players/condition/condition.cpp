#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 50010;
ll n, m, q;
vector<ll> graph[MAXN];
bool vis[MAXN];
string query(ll u, ll v) {
  ll t;
  bool flaga = false, flagb = false;
  queue<ll> q;
  memset(vis, false, sizeof(vis));
  q.push(u);
  vis[u] = true;
  while (!q.empty()) {
    t = q.front();
    q.pop();
    for (auto k : graph[t]) {
      if (!vis[k]) {
        q.push(k);
        vis[k] = true;
      }
    }
    if (vis[v]) {
      flaga = true;
      break;
    }
  }
  while (!q.empty())
    q.pop();
  swap(u, v);
  memset(vis, false, sizeof(vis));
  q.push(u);
  vis[u] = true;
  while (!q.empty()) {
    t = q.front();
    q.pop();
    for (auto k : graph[t]) {
      if (!vis[k]) {
        q.push(k);
        vis[k] = true;
      }
    }
    if (vis[v]) {
      flagb = true;
      break;
    }
  }
  swap(u, v);
  stringstream ss;
  if (flaga && flagb)
    ss << u << " <-> " << v;
  else if (flaga)
    ss << u << " -> " << v;
  else if (flagb)
    ss << u << " <- " << v;
  else
    ss << "Fail";
  return ss.str();
}
int main() {
#ifndef DEBUG
  freopen("condition.in", "r", stdin);
  freopen("condition.out", "w", stdout);
#endif
  ll u, v;
  string s;
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> s >> v;
    if (s == "<->") {
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    } else if (s == "->") {
      graph[u].emplace_back(v);
    } else {
      graph[v].emplace_back(u);
    }
  }
  while (q--) {
    cin >> u >> v;
    cout << query(u, v) << endl;
  }
  return 0;
}