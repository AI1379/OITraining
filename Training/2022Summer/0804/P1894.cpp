#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
const ll MAXN = 510;
const ll MAXM = 510;
ll n, m;
vector<ll>graph[MAXN];
ll ans = 0;
bool vis[MAXM];
ll match[MAXM];
bool matched(ll u) {
  for (auto v : graph[u]) {
    if (!vis[v]) {
      vis[v] = true;
      if (!match[v] || matched(match[v])) {
        match[v] = u;
        return true;
      }
    }
  }
  return false;
}
int main() {
  ll s, x;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    while (s--) {
      cin >> x;
      graph[i].push_back(x);
    }
  }
  for (int i = 1; i <= n; i++) {
    memset(vis, false, sizeof(vis));
    if (matched(i)) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
