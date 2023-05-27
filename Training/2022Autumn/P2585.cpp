#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 500010;
ll n;
char str[MAXN];
ll dpmin[MAXN][3][3], dpmax[MAXN][3][3];
ll cur;
void dfs() {
  ll now = cur, l, r;
  if (str[cur] == '2') {
    l = ++cur;
    dfs();
    r = ++cur;
    dfs();
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        dpmin[now][i][j] =
            min(dpmin[l][(i + 1) % 3][j] + dpmin[r][(i + 2) % 3][j],
                dpmin[l][(i + 2) % 3][j] + dpmin[r][(i + 1) % 3][j]);
        dpmax[now][i][j] =
            max(dpmax[l][(i + 1) % 3][j] + dpmax[r][(i + 2) % 3][j],
                dpmax[l][(i + 2) % 3][j] + dpmax[r][(i + 1) % 3][j]);
        if (i == j) {
          ++dpmin[now][i][j];
          ++dpmax[now][i][j];
        }
      }
    }
  } else if (str[cur] == '1') {
    l = ++cur;
    dfs();
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        dpmin[now][i][j] =
            min(dpmin[l][(i + 1) % 3][j], dpmin[l][(i + 2) % 3][j]);
        dpmax[now][i][j] =
            max(dpmax[l][(i + 1) % 3][j], dpmax[l][(i + 2) % 3][j]);
        if (i == j) {
          ++dpmin[now][i][j];
          ++dpmax[now][i][j];
        }
      }
    }
  } else {
    dpmin[now][0][0] = dpmin[now][1][1] = dpmin[now][2][2] = dpmax[now][0][0] =
        dpmax[now][1][1] = dpmax[now][2][2] = 1;
  }
}
int main() {
  scanf("%s", str + 1);
  n = strlen(str + 1);
  cur = 1;
  ll ansmin = (1ll << (sizeof(ll) * 8 - 2)), ansmax = 0;
  dfs();
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ansmin = min(ansmin, dpmin[1][i][j]);
      ansmax = max(ansmax, dpmax[1][i][j]);
    }
  }
  printf("%lld %lld\n", ansmax, ansmin);
  return 0;
}