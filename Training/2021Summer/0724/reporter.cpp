#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
struct node {
  int posx, posy;
  int dis;
  int hp;
};
int n, m, px1, py1, px2, py2;
int mp[1010][1010];
int vis[1010][1010];
queue<node> q;
int main() {
#ifndef DEBUG
  freopen("reporter.in", "r", stdin);
  freopen("reporter.out", "w", stdout);
#endif
  node qhead, tmp;
  int delta;
  cin >> n >> m >> px1 >> py1 >> px2 >> py2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  q.push((node){px1, py1, 0, 5});
  vis[px1][py1] = 5;
  while (!q.empty()) {
    qhead = q.front();
    q.pop();
    if (qhead.hp < 0) {
      continue;
    }
    if (qhead.posx == px2 && qhead.posy == py2) {
      cout << qhead.dis << endl;
#ifdef DEBUG
      system("pause");
#endif
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      tmp = qhead;
      tmp.posx += dx[i];
      tmp.posy += dy[i];
      tmp.dis++;
      if (0 < tmp.posx && tmp.posx <= n && 0 < tmp.posy && tmp.posy <= m) {
        delta = mp[tmp.posx][tmp.posy] - mp[qhead.posx][qhead.posy];
        if (-3 <= delta && delta <= 2 && tmp.hp > vis[tmp.posx][tmp.posy]) {
          q.push(tmp);
        } else if (delta < -3 && tmp.hp - 1 > vis[tmp.posx][tmp.posy]) {
          tmp.hp--;
          q.push(tmp);
        } else {
          continue;
        }
        vis[tmp.posx][tmp.posy] = tmp.hp;
      }
    }
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}