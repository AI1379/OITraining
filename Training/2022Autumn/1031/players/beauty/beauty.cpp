#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10010;
const ll MAXM = 15;
ll m, n;
ll beauty[MAXM][MAXN];
ll ans, x;
int main() {
#ifndef DEBUG
  freopen("beauty.in", "r", stdin);
  freopen("beauty.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> m >> n;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> beauty[i][j];
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      x = 0;
      for (int k = 1; k <= n; ++k) {
        if (beauty[i][k] == beauty[j][k]) {
          ++x;
        }
      }
      if (x % 2 == 0)
        --ans;
      else
        ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}