#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
const ll MAXN = 500010;
const ll MAXLOGN = 20;
ll n, m, s;
ll logn[MAXN];
vector<ll>tree[MAXN];
ll dep[MAXN];
ll par[MAXN][MAXLOGN];
void dfs(ll u, ll p) {
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  for (int i = 1; i <= logn[n]; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto v : tree[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}
ll lca(ll x, ll y) {
  if (dep[x] > dep[y]) {
    swap(x, y);
  }

  while (dep[x] != dep[y]) {
    y = par[y][logn[dep[y] - dep[x]]];
  }
  if (x == y) {
    return x;
  }
  for (int j = logn[n]; j >= 0 && x != y; j--) {
    if (par[x][j] != par[y][j]) {
      x = par[x][j];
      y = par[y][j];
    }
  }
  return par[x][0];
}
int main() {
  ll u, v;
  cin >> n >> m >> s;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  logn[1] = 0;
  logn[2] = 1;
  for (int i = 3; i <= n; i++) {
    logn[i] = logn[i / 2] + 1;
  }
  dfs(s, 0);
  while (m--) {
    cin >> u >> v;
    cout << lca(u, v) << endl;
  }
  return 0;
}
