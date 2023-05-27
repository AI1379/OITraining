// https://www.luogu.com.cn/problem/P5157
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, m;
ll deg[MAXN];
bool unavail[MAXN];
ll ans[MAXN];
vector<ll> dag[MAXN];
vector<ll> tree[MAXN];
ll getOneSol() {
  ll x, cnt = 0;
  queue<ll> q;
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 1)
      q.push(i);
  while (!q.empty()) {
    x = q.front();
    q.pop();
    ++cnt;
    if (deg[x] < 1)
      return x;
    if (deg[x] > 1) {
      for (int i = 1; i <= n; ++i)
        cout << "0\n";
      return -1;
    }
    for (ll y : tree[x]) {
      --deg[y];
      ++cnt;
      if (deg[y] == 1)
        q.push(y);
    }
    for (ll y : dag[x]) {
      --deg[y];
      ++cnt;
      if (deg[y] == 1)
        q.push(y);
    }
  }
  if (cnt != n) {
    for (int i = 1; i <= n; ++i)
      cout << "0\n";
    return -1;
  }
  return -1;
}
void dfs(ll u, ll fa) {
  ans[u] = 1;
  for (ll v : tree[u])
    if (v != fa && !unavail[v])
      dfs(v, u);
}
int main() {
  ll x, y;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
    ++deg[x];
    ++deg[y];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y;
    dag[x].push_back(y);
    ++deg[y];
    unavail[x] = true;
  }
  ll rt = getOneSol();
  if (rt == -1)
    return 0;
  dfs(rt, 0);
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}