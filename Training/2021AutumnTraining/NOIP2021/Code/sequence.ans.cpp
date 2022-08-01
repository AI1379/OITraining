#include <bits/stdc++.h>
using namespace std;

const int NR = 35, MR = 105, MOD = 998244353;
int N, M, K;
int v[MR], powv[MR][NR], dp[NR][NR][NR][NR][MR], f[NR][NR][NR][MR];
int fac[NR], inv[NR];

inline int qpow(int x, int k) {
  if (k == 0) return 1;
  int tmp = qpow(x, k >> 1);
  tmp = 1ll * tmp * tmp % MOD;
  if (k & 1) tmp = 1ll * tmp * x % MOD;
  return tmp;
}

inline void init() {  //预处理组合数
  fac[0] = 1;
  for (int i = 1; i <= N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
  inv[N] = qpow(fac[N], MOD - 2);
  for (int i = N - 1; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}

inline int C(int n, int m) {  // n中选m
  return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

inline int popcnt(int x) {
  int ret = 0;
  while (x) {
    if (x & 1) ret++;
    x >>= 1;
  }
  return ret;
}

int main() {
  cin >> N >> M >> K;
  init();
  for (int i = 0; i <= M; i++) {
    cin >> v[i];
    powv[i][0] = 1;
    for (int j = 1; j <= N; j++) powv[i][j] = 1ll * powv[i][j - 1] * v[i] % MOD;
  }
  f[0][0][0][0] = 1;
  for (int p = 0; p <= M; p++) {
    for (int i = 0; i <= N; i++) {
      for (int j = 0; j <= N - i; j++) {  //选择总数的限制
        for (int k = 0; k <= N; k++) {
          for (int num = 0; num <= K; num++) {
            if (num - (i + k) % 2 < 0) continue;
            dp[i][j][k][num][p] = 1ll * f[j][k][num - (i + k) % 2][p] *
                                  powv[p][i] % MOD * C(N - j, i) % MOD;
            f[i + j][(i + k) / 2][num][p + 1] += dp[i][j][k][num][p];
            f[i + j][(i + k) / 2][num][p + 1] %= MOD;
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= N; i++) {
    for (int k = 0; k <= N; k++) {
      for (int num = 0; num <= K; num++) {
        if (num + popcnt((i + k) / 2) <= K)
          ans = (ans + dp[i][N - i][k][num][M]) % MOD;
      }
    }
  }
  cout << ans << '\n';
  system("pause");
  return 0;
}