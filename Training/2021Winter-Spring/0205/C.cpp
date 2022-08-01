#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 30;
const ll MAXM = 30;
ll n, m, p;
bool mp[MAXN][MAXM];
bool vis[MAXN][MAXM];
struct node {
  ll px, py, dis;
};
queue<node> q;
int main() {
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  q.push((node){n, m, 0});
  node h;
  ll mdis = 0x3fffffffffffffff, num = 0;
  vis[n][m] = true;
  while (!q.empty()) {
    h = q.front();
    q.pop();
    if (h.px == 1 && h.py == 1) {
      if (h.dis > mdis) break;
      mdis = h.dis;
      num++;
    }
    for (int i = max(1ll, h.px - p); i <= min(h.px + p, n); i++) {
      for (int j = max(1ll, h.py - p + abs(i - h.px));
           j <= min(h.py + p - abs(i - h.px), m); j++) {
        if (!mp[i][j] && !vis[i][j]) {
#ifdef DEBUG
          cout << h.px << ' ' << h.py << ' ' << i << ' ' << j << ' ' << h.dis
               << endl;
#endif
          q.push((node){i, j, h.dis + 1});
          vis[i][j] = true;
        }
      }
    }
  }
  cout << mdis << ' ' << num << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}