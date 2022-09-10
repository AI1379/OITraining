#include<bits/stdc++.h>
using namespace std;

vector<int> G[3444]; //基环树

int fa[3444];        //dfs时的父亲
int dfn[3444], idx;  //访问的时间
int loop[3444], cnt; //环
int n, m;
void get_loop(int u) {
  dfn[u] = ++ idx;
  for (auto v : G[u]) {
    if (v == fa[u]) continue ;
    if (dfn[v]) {
      if (dfn[v] < dfn[u]) continue ;
      loop[++ cnt] = v;
      for ( ; v != u; v = fa[v])
        loop[++ cnt] = fa[v];
    } else fa[v] = u, get_loop(v);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
//    G[y].push_back(x);
  }
  get_loop(1);
  for (int i = 1; i <= cnt; i++)
    cout << loop[i] << endl;
  return 0;
}
