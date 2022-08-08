// https://ac.nowcoder.com/acm/problem/202475

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll MAXN = 100010;
ll n;
ll val[MAXN];
vector<ll> tree[MAXN];
ll maxdep = 0, maxpos;
// WARNING: 
// 两次DFS只能在全为正权的树中成立
// 牛客会有一个点WA
void dfs(ll root, ll dep, ll par) {
  if (dep > maxdep) {
    maxdep = dep;
    maxpos = root;
  }
  for (auto v : tree[root]) {
    if (v != par) {
      dfs(v, dep + val[v], root);
    }
  }
}
int main() {
  ll u, v;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  dfs(1, val[1], 0);
  maxdep = 0;
  dfs(maxpos, val[maxpos], 0);
  cout << maxdep << endl;
  return 0;
}
