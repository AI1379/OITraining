#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
ll n, u, v, ans;
bool vis[100010];
void solve() {
  pll t;
  cin >> u >> v;
  ans = 0;
  memset(vis, false, sizeof(vis));
  queue<pll>q;
  q.push(make_pair(u, 0));
  while (!q.empty()) {
    t = q.front();
    q.pop();
    if (t.first == v) {
      cout << t.second << endl;
      return ;
    }
    if (t.first < v && !vis[t.first * 2]) {
      q.push(make_pair(t.first * 2, t.second + 1));
      vis[t.first * 2] = true;
    }
    if (!vis[t.first + 1]) {
      q.push(make_pair(t.first + 1, t.second + 1));
      vis[t.first + 1] = true;
    }
    if (t.first % 2 == 0 && !vis[t.first / 2]) {
      q.push(make_pair(t.first / 2, t.second + 1));
      vis[t.first / 2] = true;
    }
  }
}
int main() {
#ifndef DEBUG
  freopen("soul.in", "r", stdin);
  freopen("soul.out", "w", stdout);
#endif
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
/*
  997 0
  998 1
  499 2
  500 3
  250 4
  125 5
  126 6
  63 7
  64 8
  32 9
  16 10
  8 11
  4 12
  5 13
  6 14
  7 15
  14 16
  15 17
  30 18
  60 19
  120 20
 */
