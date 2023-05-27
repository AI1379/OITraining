// https://www.luogu.com.cn/problem/P8548
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 511;
const ll MAXQ = 1000010;
const ll kk = 16;
static ll n, q;
static ll co[MAXN], fr[MAXN], be[MAXN];
static ll dp[MAXN][MAXN * kk];
static ll c[MAXQ], f[MAXQ];
static ll mc, mf;
ll read() {
  ll x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * w;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);
  // cin >> n >> q;
  n = read(), q = read();
  for (int i = 1; i <= n; i++) {
    co[i] = read(), fr[i] = read(), be[i] = read();
    // cin >> co[i] >> fr[i] >> be[i];
    mc = max(mc, co[i]);
    mf = max(mf, co[i]);
  }
  for (int i = 1; i <= q; i++) {
    c[i] = read(), f[i] = read();
    // cin >> c[i] >> f[i];
    mc = max(mc, c[i]);
    mf = max(mf, f[i]);
  }
  mf *= min(n, kk);
  for (int j = 0; j <= mc; j++) {
    for (int k = 1; k <= mf; k++) {
      dp[j][k] = -(1ll << (sizeof(ll) * 8 - 2));
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = mc; j >= co[i]; j--) {
      for (int k = mf; k >= fr[i]; k--) {
        dp[j][k] = max(dp[j][k], dp[j - co[i]][k - fr[i]] + be[i]);
      }
    }
  }
  for (int j = 0; j <= mc; j++) {
    for (int k = mf; k >= 0; k--) {
      dp[j][k] = max(dp[j][k], dp[j][k + 1]);
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << dp[c[i]][f[i]] << '\n';
  }
  return 0;
}