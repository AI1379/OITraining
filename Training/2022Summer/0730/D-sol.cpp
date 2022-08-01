#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define abs(x) ((x) > 0 ? (x) : (-(x)))
const ll MAXN = 100010;
const ll MAXM = 200010;
struct Node {
  ll v;
  ll number;
};
ll n, m;
ll degree[MAXN];
vector<Node> graph[MAXN];
bool vis_self_circle[MAXN];
vector<ll> self_circle[MAXN];
int main() {
  ll u, v;
  cin >> n >> m;
  for (ll i = 1; i <= m; i++) {
    cin >> u >> v;
    if (u != v) {
      graph[u].push_back(Node{v, i});
      graph[v].push_back(Node{u, -i});
      ++degree[u];
      ++degree[v];
    } else {
      self_circle[u].push_back(i);
    }
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}