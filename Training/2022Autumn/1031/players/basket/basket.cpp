#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 5010;
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
ll n;
pll basket[MAXN];
ll pre[MAXN][MAXN];
ll h[MAXN];
ll ans = 0;
int main() {
#ifndef DEBUG
  freopen("basket.in", "r", stdin);
  freopen("basket.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> basket[i].first;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> basket[i].second;
  }
  sort(basket + 1, basket + n + 1);
  for (int i = 1; i <= n; ++i) {
    h[i] = basket[i].second;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j >= 1; --j) {
      if (h[j] < h[j - 1])
        swap(h[j], h[j - 1]);
      else
        break;
    }
    for (int j = 1; j <= n; ++j)
      pre[i][j] = pre[i][j - 1] + h[j];
  }
  for (int i = 1; i <= n; ++i) {
    ans = INF;
    for (int j = i; j <= n; ++j)
      ans = min(ans, pre[j][i] + basket[j].first * 2);
    cout << ans << endl;
  }
  return 0;
}