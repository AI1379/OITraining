#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n;
ll val[MAXN];
vector<ll> graph[MAXN];
bool vis[MAXN];
ll loopu, loopv;
ll dp[MAXN][2];
bool getLoop(ll u, ll p) {
  vis[u] = true;
  for (auto v : graph[u]) {
    if (v == p)
      continue;
    if (vis[v]) {
      loopv = v;
      loopu = u;
      return true;
    }
    if (getLoop(v, u)) {
      return true;
    }
  }
  return false;
}
void dfs(ll u, ll p) {
  dp[u][1] = val[u];
  dp[u][0] = 0;
  for (auto v : graph[u]) {
    if ((u == loopu && v == loopv) || (u == loopv && v == loopu) || v == p)
      continue;
    dfs(v, u);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
  // cout << u << ' ' << dp[u][0] << ' ' << dp[u][1] << endl;
}
int main() {
  ll v;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> val[i] >> v;
    graph[i].push_back(v);
    graph[v].push_back(i);
  }
  ll ans = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      getLoop(i, 0);
      res = 0;
      dfs(loopu, 0);
      res = dp[loopu][0];
      // cout << loopu << ' ' << loopv << endl;
      // cout << res << endl;
      dfs(loopv, 0);
      res = max(res, dp[loopv][0]);
      // cout << res << endl;
      ans += res;
    }
  }
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}