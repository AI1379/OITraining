#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1010;
ll rest[MAXN], d;
ll pos[MAXN], speed[MAXN];
ll n, m, ans = 0;
bool vis[MAXN], can[MAXN][MAXN];
int main() {
  cin >> n >> m >> d;
  for (int i = 1; i <= n; i++) cin >> rest[i];
  sort(rest + 1, rest + 1 + n);
  for (int i = 1; i <= m; i++) cin >> pos[i] >> speed[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (pos[j] <= d) can[i][j] = true;
    for (int j = 1; j <= m; j++) pos[j] += rest[i] * speed[j];
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++)
      if (!vis[j] && can[i][j]) {
        vis[j] = true;
        ans++;
        break;
      }
  }
  cout << ans << endl;
  return 0;
}