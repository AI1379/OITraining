#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 20010;
ll n, m;
ll tree[MAXN][2];
ll val[MAXN];
ll cnt, w[MAXN], s[MAXN];
namespace case1 {
void update(ll u) {
  if (u == 0) {
    return;
  } else if (u == 1) {
    val[u] = abs(val[u] - val[tree[u][0]]);
  } else {
    val[u] = abs(val[tree[u][0]] - val[tree[u][1]]);
  }
  update(tree[u][0]);
  update(tree[u][1]);
}
} // namespace case1
namespace case2 {
bool check() {
  for (int i = 1; i <= n; ++i) {
    if (tree[i][1] != 0)
      return false;
  }
  return true;
}
ll v[MAXN], cnt = 0;
void init() {
  ll u = 1;
  while (u) {
    v[++cnt] = val[u];
    u = tree[u][0];
    cout << v[cnt] << endl;
  }
}
ll solve() {
  for (int i = 2; i <= cnt; ++i) {
    v[1] = abs(v[1] - v[i]);
  }
  return v[1];
}
} // namespace case2
namespace case3 {
ll dep = 0;
void dfs(ll u, ll d) {
  if (!u)
    return;
  dep = max(dep, d);
  dfs(tree[u][0], d + 1);
  dfs(tree[u][1], d + 1);
}
ll solve() {
  dfs(1, 1);
  for (int i = 1; i <= dep; ++i) {
    case1::update(1);
  }
  return val[1];
}
} // namespace case3
int main() {
#ifndef DEBUG
  freopen("end.in", "r", stdin);
  freopen("end.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> tree[i][0] >> tree[i][1];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    val[u] = v;
  }
  if (case2::check()) {
    case2::init();
    cout << case2::solve() << endl;
  } else {
    cout << case3::solve() << endl;
  }
  return 0;
}
/**
6 5
2 0
3 4
5 6
0 0
0 0
0 0
1 3
3 6
4 2
5 2
6 4


8 4
2 0
3 4
5 6
0 8
0 0
0 7
0 0
0 0
2 6
6 7
8 5
7 1
**/