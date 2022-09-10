#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int vis[MAXN], visx[MAXN];
int flag, flagx;
vector<int>g[MAXN];
vector<pair<int, int>>e;
void dfs(int x) {
  if ( vis[x] == 1 ) {
    flag = x;    //flag为循环点，回溯时用来加边
    return;
  }
  if ( visx[x] == 1 ) return;
  visx[x] = 1;
  vis[x] = 1;
  for (int i = 0; i < g[x].size(); i++) {
    int t = g[x][i];
    dfs(t);
    if ( flagx ) {
      vis[x] = 0;
      return;
    }
    if ( flag ) {
      e.push_back(make_pair(x, t));  //存环上的边
      if ( x == flag ) flagx = 1;
      vis[x] = 0;
      return;
    }
  }
  vis[x] = 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n ;
  m = n;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    flag = 0, flagx = 0;
    if ( visx[i] == 0 ) dfs(i);
    if ( flag ) break;
  }
  for (auto obj : e) {
    cout << obj.first << ' ' << obj.second << endl;;
  }
  return 0;
}
