#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll MAXN = 100010;
const ll kPrimPara = 25;
ll n;
pll mp[MAXN];
ll dis[MAXN];
bool vis[MAXN];
ll ans = 0;
ll getDis(ll x, ll y) {
  return ((mp[x].first - mp[y].first)
          * (mp[x].first - mp[y].first)
          + (mp[x].second - mp[y].second)
          * (mp[x].second - mp[y].second));
}
void prim() {
  memset(vis, false, sizeof(vis));
  memset(dis, 0x3f, sizeof(dis));
  dis[1] = 0;
  priority_queue<pll, vector<pll>, greater<pll>>q;
  q.push(make_pair(0, 1));
  pll t;
  while (!q.empty()) {
    t = q.top();
    q.pop();
    vis[t.second] = true;
    for (int i = max(1ll, t.second - kPrimPara); i <= min(n, t.second + kPrimPara); i++) {
      if (!vis[i]) {
        dis[i] = min(dis[i], getDis(t.second, i));
        q.push(make_pair(dis[i], i));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += dis[i];
  }
}
int main() {
#ifndef DEBUG
  freopen("network.in", "r", stdin);
  freopen("network.out", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> mp[i].first >> mp[i].second;
  }
  sort(mp + 1, mp + n + 1);
  prim();
  cout << ans << endl;
  return 0;
}
