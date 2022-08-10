#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n;
vector<ll>graph[MAXN];
bool vis[MAXN];
vector<ll>loop;
bool dfs(ll u, ll fa) {
  vis[u] = true;
  for (auto v : graph[u]) {
    if (v == fa)continue;
    if (vis[v]) {
      loop.push_back(u);
      return true;
    }
    if (dfs(v, u)) {
      loop.push_back(u);
      return true;
    }
  }
  return false;
}
int main() {
  ll u, v;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
//    graph[v].push_back(u);
  }
  dfs(6,0);
//  for (int i = 1; i <= n; i++) {
//    if (dfs(i, 0)) {
//      break;
//    }
//  }
  for (auto v : loop) {
    cout << v << ' ';
  }
  return 0;
}
/*
14
1 4
4 5
5 3
3 2
2 1
6 1
8 7
7 4
11 10
10 5
9 5
14 12
13 12
12 3
 */
