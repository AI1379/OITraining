#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1010;
const ll MOD = 998244353;
static ll n, m, s, q;
static ll mat[2][MAXN][MAXN];
static ll ans[2][MAXN][MAXN];
void multiply(ll res[MAXN][MAXN], ll a[MAXN][MAXN], ll b[MAXN][MAXN]) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      res[i][j] = 0;
      for (int k = 1; k <= n; ++k) {
        res[i][j] = (res[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
      }
    }
  }
}
int main() {
  ll u, v, w;
  ll flag1 = 0, flag2 = 0;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> s >> q;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v >> w;
    mat[0][u][v] = mat[1][u][v] = w;
    ans[0][i][i] = ans[1][i][i] = 1;
  }
  while (s) {
    if (s & 1) {
      multiply(ans[flag1 ^ 1], ans[flag1], mat[flag2]);
      flag1 ^= 1;
    }
    multiply(mat[flag2 ^ 1], mat[flag2], mat[flag2]);
    flag2 ^= 1;
    s >>= 1;
  }
  while (q--) {
    cin >> u >> v;
    cout << ans[flag1][u][v] << endl;
  }
  return 0;
}