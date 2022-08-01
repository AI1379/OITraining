#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, m[2];
pair<int, int> fli[2][MAXN];
int arr[2][MAXN], leave[2][MAXN];
int grp[2][MAXN];
int num[2][MAXN];
int maxed[2][MAXN];
int now[2][2], tmp[2][2];
int dp[MAXN][2];
int main() {
  cin >> n;
  cin >> m[0] >> m[1];
  int grpn;
  for (int k = 0; k <= 1; k++) {
    grpn = 0;
    for (int i = 1; i <= m[k]; i++) {
      cin >> fli[k][i].first >> fli[k][i].second;
    }
    sort(fli[k] + 1, fli[k] + m[k] + 1);
    for (int i = 1; i <= m[k]; i++) {
      for (int j = 1; j <= grpn; j++) {
        if (maxed[k][j] < fli[k][i].first) {
          grp[k][i] = j;
          break;
        }
      }
      if (!grp[k][i]) {
        grp[k][i] = ++grpn;
      }
      num[k][grp[k][i]]++;
      maxed[k][grp[k][i]] = max(maxed[k][grp[k][i]], fli[k][i].second);
    }
  }
  int x, y;
  for (int i = 1; i <= n; i++) {
    tmp[0][0] = now[0][0], tmp[0][1] = now[0][1];
    tmp[1][0] = now[1][0], tmp[1][1] = now[1][1];
    for (int j = 0; j <= 1; j++) {
      x = dp[i - 1][0] + num[j][now[0][j] + 1];
      y = dp[i - 1][1] + num[j][now[1][j] + 1];
      dp[i][j] = max(x, y);
      tmp[j][j] = now[x <= y][j] + 1;
      tmp[j][(j + 1) % 2] = now[x <= y][(j + 1) % 2];
#ifdef DEBUG
      cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << x << ' ' << y << endl;
#endif
    }
    now[0][0] = tmp[0][0], now[0][1] = tmp[0][1];
    now[1][0] = tmp[1][0], now[1][1] = tmp[1][1];
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}