#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n;
int a[MAXN];
int stmax[MAXN][20], stmin[MAXN][20];
int log2n[MAXN];
int main() {
  cin >> n;
  memset(stmin, 0x3f, sizeof(stmin));
  log2n[0] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    stmax[i][0] = stmin[i][0] = a[i];
    log2n[i] = log2n[i / 2] + 1;
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
      stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
    }
  }
  int ans, x, y;
  for (int len = 1; len <= n; len++) {
    ans = 0;
    for (int l = 1, r = l + len - 1; r <= n; l++, r++) {
      x = min(stmin[l][log2n[len]],
              stmin[r - (1 << log2n[len]) + 1][log2n[len]]);
      y = max(stmax[l][log2n[len]],
              stmax[r - (1 << log2n[len]) + 1][log2n[len]]);
      ans += (x * y);
    }
    cout << ans << ' ';
  }
  return 0;
}
