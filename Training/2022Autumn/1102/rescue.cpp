#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define t3l tuple<ll, ll, ll>
const ll MAXN = 1023;
const ll dx[] = {-1, 0, 1, 0};
const ll dy[] = {0, 1, 0, -1};
ll n, m, sx, sy, tx, ty, px, py;
bool mp[MAXN][MAXN], vis[MAXN][MAXN], check[MAXN][MAXN];
pll pre[MAXN][MAXN];
int main() {
#ifndef DEBUG
  freopen("rescue.in", "r", stdin);
  freopen("rescue.out", "w", stdout);
#endif
  cin >> n >> m >> sx >> sy >> tx >> ty >> px >> py;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mp[i][j];
    }
  }
  queue<pll> q;
  pll tmp;
  queue<t3l> q2;
  t3l tmp2;
  ll ans = -1;
  q.emplace(sx, sy);
  vis[sx][sy] = true;
  while (!q.empty()) {
    tmp = q.front();
    q.pop();
    if (tmp.first == px && tmp.second == py) {
      break;
    }
    for (int k = 0; k < 4; ++k) {
      if (!vis[tmp.first + dx[k]][tmp.second + dy[k]] &&
          !mp[tmp.first + dx[k]][tmp.second + dy[k]] &&
          1 <= tmp.first + dx[k] && tmp.first + dx[k] <= n &&
          1 <= tmp.second + dy[k] && tmp.second + dy[k] <= m) {
        q.emplace(tmp.first + dx[k], tmp.second + dy[k]);
        vis[tmp.first + dx[k]][tmp.second + dy[k]] = true;
        pre[tmp.first + dx[k]][tmp.second + dy[k]] = tmp;
      }
    }
  }
  if (!vis[px][py]) goto output;
  tmp = make_pair(px, py);
  check[px][py] = check[sx][sy] = true;
  while (tmp.first != sx || tmp.second != sy) {
    check[tmp.first][tmp.second] = true;
    tmp = pre[tmp.first][tmp.second];
  }
  memset(vis, false, sizeof(vis));
  q2.emplace(tx, ty, 0);
  vis[tx][ty] = true;
  while (!q2.empty()) {
    tmp2 = q2.front();
    q2.pop();
    if (check[get<0>(tmp2)][get<1>(tmp2)]) {
      ans = get<2>(tmp2);
      break;
    }
    for (int k = 0; k < 4; ++k) {
      if (!vis[get<0>(tmp2) + dx[k]][get<1>(tmp2) + dy[k]] &&
          !mp[get<0>(tmp2) + dx[k]][get<1>(tmp2) + dy[k]] &&
          1 <= get<0>(tmp2) + dx[k] && get<0>(tmp2) + dx[k] <= n &&
          1 <= get<1>(tmp2) + dy[k] && get<1>(tmp2) + dy[k] <= m) {
        q2.emplace(get<0>(tmp2) + dx[k], get<1>(tmp2) + dy[k],
                   get<2>(tmp2) + 1);
        vis[get<0>(tmp2) + dx[k]][get<1>(tmp2) + dy[k]] = true;
      }
    }
  }
output:
  cout << ans << endl;
  return 0;
}