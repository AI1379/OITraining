#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 2510;
ll n, m, k;
ll val[MAXN];
vector<ll> graph[MAXN];
ll dis[MAXN][MAXN];
vector<ll> joint[MAXN];
ll ans = 0;
int main() {
  ll u, v;
  cin >> n >> m >> k;
  for (int i = 2; i <= n; ++i) {
    cin >> val[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  memset(dis, 0x3f, sizeof(dis));
  queue<ll> q;
  for (int i = 1; i <= n; ++i) {
    q.push(i);
    dis[i][i] = -1;
    while (!q.empty()) {
      u = q.front();
      q.pop();
      if (dis[i][u] > k)
        break;
      for (auto v : graph[u]) {
        if (dis[i][v] <= n)
          continue;
        dis[i][v] = dis[i][u] + 1;
        q.push(v);
      }
    }
    while (!q.empty())
      q.pop();
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     if (dis[i][j] <= n)
  //       cout << dis[i][j] << ' ';
  //     else
  //       cout << "INF ";
  //   }
  //   cout << endl;
  // }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j == i)
        continue;
      if (dis[1][j] <= k && dis[j][i] <= k) {
        joint[i].emplace_back(j);
      }
    }
    sort(joint[i].begin(), joint[i].end(),
         [](ll l, ll r) { return val[l] > val[r]; });
  }
  ans = 0;
  unsigned ll l, r;
  for (int i = 2; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      l = r = 0;
      if (joint[i].empty() || joint[j].empty() || dis[i][j] > k)
        continue;
      while (joint[i][l] == joint[j][r] || joint[i][l] == j ||
             joint[j][r] == i || joint[i][l] == 1 || joint[j][r] == 1) {
        if (l + 1 == joint[i].size() && r + 1 == joint[j].size()) {
          break;
        } else if (r + 1 == joint[j].size()) {
          ++l;
        } else if (l + 1 == joint[i].size()) {
          ++r;
        } else {
          if (val[joint[i][l + 1]] > val[joint[j][r + 1]]) {
            ++l;
          } else {
            ++r;
          }
        }
      }
      if (joint[i][l] == joint[j][r] || joint[i][l] == j || joint[j][r] == i ||
          joint[i][l] == 1 || joint[j][r] == 1)
        continue;
      ans = max(ans, val[i] + val[j] + val[joint[i][l]] + val[joint[j][r]]);
      // cout << ans << ' ' << joint[i][l] << ' ' << i << ' ' << j << ' '
      //      << joint[j][r] << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
/**
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
**/