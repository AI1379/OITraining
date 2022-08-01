#include <bits/stdc++.h>
using namespace std;
struct node {
  int b, e, w, v;
};
node evs[1010];
int n, m, t;
vector<node> grp[1010];
int num;
int dp[1010][1010][2];
bool cmp(node a, node b) {
  if (a.e == b.e) return a.b < b.b;
  return a.e < b.e;
}
int main() {
  int b, e, w, v;
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    cin >> b >> e >> w >> v;
    evs[i] = (node){b, e, w, v};
  }
  sort(evs + 1, evs + n + 1, cmp);
  int maxe = evs[1].e;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (evs[i].b > evs[i - 1].e) {
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
        dp[i][j][1] =
            max(dp[i - 1][j - evs[i].w][0], dp[i - 1][j - evs[i].w][1]) +
            evs[i].v;
      } else {
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
        dp[i][j][1] = dp[i - 1][j - evs[i].w][0] + evs[i].v;
      }
    }
  }
  cout << dp[n][m][0] << dp[n][m][1] << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}