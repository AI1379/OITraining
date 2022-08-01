#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, d, l, p, q;
int dfs(int dep, int nowg, int noww, int nowf, int delg, int delw) {
  if (dep == t) {
    return nowg * noww * nowf;
  }
  if (nowg < 0 || noww < 0) return 0;
  if (nowg > l) nowg = l;
  int res = 0;
  res = dfs(dep + 1, nowg + delg, noww + delw, nowf, delg, delw);
  // cout << dep << ends << res << endl;
  res = max(res, dfs(dep + 1, nowg + delg - c, noww + delw - d, nowf + 1,
                     delg + a, delw));
  // cout << dep << ends << res << endl;
  res = max(res, dfs(dep + 1, nowg + delg - c, noww + delw - d, nowf + 1, delg,
                     delw + b));
  // cout << dep << ends << res << endl;
  return res;
}
int main() {
#ifndef DEBUG
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
#endif
  cin >> t >> a >> b >> c >> d >> l >> p >> q;
  int ans = dfs(0, p, q, 0, 0, 0);
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}