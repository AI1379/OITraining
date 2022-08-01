#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n;
string strs[MAXN];
vector<int> pre[26], sub[26];
ll dis[MAXN], path[MAXN];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, less<pair<ll, ll>>> q;
void dijkstra(int u) {
  for (int i = 1; i <= n + 2; i++) dis[i] = INF;
  // memset(dis, 0x3f, sizeof(dis));
  dis[u] = 0;
  path[u] = -1;
  q.push(make_pair(dis[u], u));
  pair<ll, ll> tmp;
  int c;
  while (!q.empty()) {
    tmp = q.top();
    q.pop();
    u = tmp.second;
    if (dis[u] < tmp.first) continue;
    c = strs[u][strs[u].length() - 1] - 'A';
    for (auto v : pre[c]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(make_pair(dis[v], v));
        path[v] = u;
      }
    }
  }
}
int main() {
  cin >> strs[1] >> strs[2];
  pre[strs[2][0] - 'A'].push_back(2);
  cin >> n;
  for (int i = 3; i <= n + 2; i++) {
    cin >> strs[i];
    if (strs[i] == strs[2]) continue;
    pre[strs[i][0] - 'A'].push_back(i);
  }
  dijkstra(1);
  if (dis[2] == INF) {
    cout << "-1" << endl;
    return 0;
  }
  cout << dis[2] << endl;
#ifdef DEBUG
  for (int i = 1; i <= n + 2; i++) cout << path[i] << ' ';
  cout << endl;
#endif
  stack<int> stk;
  for (int v = 2; v != -1; v = path[v]) {
    stk.push(v);
  }
  while (!stk.empty()) {
    cout << strs[stk.top()];
    stk.pop();
    if (!stk.empty()) cout << " -> ";
  }
  cout << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}