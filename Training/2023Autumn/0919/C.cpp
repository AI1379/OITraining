#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
static ll pre[MAXN], minfac[MAXN];
static ll pri[MAXN], cnt;
static bool notpri[MAXN];
static ll sum[MAXN];
void init(ll m) {
  for (int i = 2; i <= m; ++i) {
    if (!notpri[i]) {
      pri[++cnt] = i;
      pre[i] = minfac[i] = i;
    }
    for (int j = 1; j <= cnt; ++j) {
      if (1ll * i * pri[j] > m)
        break;
      notpri[i * pri[j]] = true;
      if (i % pri[j] == 0) {
        minfac[i * pri[j]] = minfac[i] * pri[j];
        pre[i * pri[j]] = pre[i] + minfac[i] * (pri[j] - 1);
        break;
      } else {
        minfac[i * pri[j]] = pri[j];
        pre[i * pri[j]] = pre[i] + pri[j];
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    sum[i] = sum[i - 1] + pre[i];
  }
}
ll t, l, r;
int main() {
#ifndef DEBUG
  freopen("stupid.in", "r", stdin);
  freopen("stupid.out", "w", stdout);
#endif
  init(1000000);
  cin >> t;
  while (t--) {
    cin >> l >> r;
    cout << (sum[r] - sum[l - 1]) << endl;
  }
  return 0;
}