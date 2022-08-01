#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
#define ll long long
const ll MAXN = 50010;
const ll MAXM = 100010;
ll n, m, k;
vector<pair<ll, ll>> graph[MAXN];
ll dis1[MAXN], dis2[MAXN];
bool vis1[MAXN], vis2[MAXN];
void spfa(ll s, ll *dis, bool *vis) {
  queue<pair<ll, ll>> q;
  dis[s] = 0;
  q.push(make_pair(s, 0));
  vis[s] = true;
  pair<ll, ll> tmp;
  while (!q.empty()) {
    tmp = q.front();
    q.pop();
    vis[tmp.first] = false;
    for (auto i : graph[tmp.first]) {
      if (dis[i.first] > dis[tmp.first] + tmp.second) {
        dis[i.first] = dis[tmp.first] + tmp.second;
        q.push(make_pair(i.first, dis[i.first]));
        vis[i.first] = true;
      }
    }
  }
}
int main() {
  ll x, y, z;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> z;
    graph[x].push_back(make_pair(y, z));
    graph[y].push_back(make_pair(x, z));
  }
  memset(dis1, 0x3f, sizeof(dis1));
  memset(dis2, 0x3f, sizeof(dis2));
  memset(vis1, false, sizeof(vis1));
  memset(vis2, false, sizeof(vis2));
  spfa(n, dis1, vis1);
  for (int i = 1; i <= k; i++) {
    cin >> x >> y;
    graph[n + 1].push_back(make_pair(x, dis1[x] - y));
  }
  spfa(n + 1, dis2, vis1);
  for (int i = 1; i < n; i++) {
    if (dis2[i] <= dis1[i]) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}