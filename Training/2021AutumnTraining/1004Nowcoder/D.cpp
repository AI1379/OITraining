#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1510][1510];
int solve(int x, int y) {
  int f[1510][1510];
  map<pair<int, int>, bool> vis[100];
  int z = min(n - x + 1, m - y + 1);
  int res = 0;
  for (int i = x; i <= x + z - 1; i++) {
    for (int j = y; j <= y + z - 1; j++) {
      if (vis[a[j]][make_pair(i - 1, j)] || vis[a[j]][make_pair(i, j - 1)]) {
        f[i][j] = f[i][j - 1];
      } else {
        f[i][j] = f[i][j - 1] + 1;
      }
      vis[a[j]][make_pair(i, j)] = true;
      if (f[i][j] == k) res++;
    }
  }
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans += solve(i, j);
    }
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}