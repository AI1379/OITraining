#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1010;
const ll dx[] = {0, 0, 1, -1};
const ll dy[] = {1, -1, 0, 0};
ll n, m;
ll mp[MAXN][MAXN];
ll vis[MAXN][MAXN];
ll lake, moun;
void bfs(ll sx, ll sy) {
  queue<pair<ll, ll>> q;
  q.push(make_pair(sx, sy));
  vis[sx][sy] = true;
  ll big = 0, les = 0;
  ll x, y;
  while (!q.empty()) {
    auto tmp = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      x = tmp.first + dx[k];
      y = tmp.second + dy[k];
      if (x <= 0 || x > n || y <= 0 || y > m) continue;
#ifdef DEBUG
      cout << x << ' ' << y << endl;
#endif
      if (!vis[x][y] && mp[x][y] == mp[tmp.first][tmp.second]) {
        q.push(make_pair(x, y));
        vis[x][y] = true;
        continue;
      }
      if (mp[x][y] > mp[tmp.first][tmp.second])
        big++;
      else if (mp[x][y] < mp[tmp.first][tmp.second])
        les++;
    }
  }
  if (big == 0) {
    moun++;
#ifdef DEBUG
    cout << "Mountain: " << sx << ' ' << sy << " " << big << ' ' << les << endl;
#endif
  }
  if (les == 0) {
    lake++;
#ifdef DEBUG
    cout << "Lake: " << sx << " " << sy << ' ' << big << ' ' << les << endl;
#endif
  }
#ifdef DEBUG
  cout << "----" << endl;
#endif
  return;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> mp[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!vis[i][j]) bfs(i, j);
  cout << lake << ' ' << moun << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}