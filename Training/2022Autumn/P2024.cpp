#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 50010;
ll n, k;
ll opt, x, y;
ll ans;
ll fa[MAXN * 3];
ll djfind(ll u) { return fa[u] == u ? u : fa[u] = djfind(fa[u]); }
ll fx, fy;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> opt >> x >> y;
    if (x > n || y > n) {
      ++ans;
      continue;
    } else if (opt == 1) {
    } else {
    }
  }
  return 0;
}