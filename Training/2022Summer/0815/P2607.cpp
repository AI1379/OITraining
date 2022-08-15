#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n;
ll val[MAXN];
vector<ll> graph[MAXN];
vector<ll> loop;
bool vis[MAXN];
ll flag;
bool getLoop(ll u, ll p) {
  for (auto v : graph[u]) {
    if (v == p)
      continue;
    if (vis[v]) {
      flag = v;
      loop.emplace_back(v);
      return true;
    }
    if (getLoop(v, u)) {
      loop.emplace_back(v);
      return v != flag;
    }
  }
  return false;
}
int main() {
  ll u, v;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> val[i] >> v;
    graph[i].push_back(v);
    graph[v].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      loop.clear();
      getLoop(i, 0);
    }
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}