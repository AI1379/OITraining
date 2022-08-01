#include <bits/stdc++.h>
using namespace std;
int n, m, r, c;
int num[1010][1010];
int pre[1010][1010];
inline int sum(int a, int b) {
  return pre[a + r - 1][b + c - 1] - pre[a - 1][b + c - 1] -
         pre[a + r - 1][b - 1] + pre[a - 1][b - 1];
}
int main() {
  cin >> n >> m >> r >> c;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> num[i][j];
      pre[i][j] = num[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    }
  }
  int ans = 0;
  for (int i = 1; i + r <= n; i++) {
    for (int j = 1; j + c <= m; j++) {
      ans = max(ans, sum(i, j));
    }
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}