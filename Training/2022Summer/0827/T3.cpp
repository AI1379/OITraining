#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 256;
ll n, minw;
ll w[MAXN], t[MAXN];
ll dp[1010];
ll k;
bool judge(ll x) {
  for (int i = 1; i <= minw; i++)
    dp[i] = -(1ll << (sizeof(ll) * 8 - 2));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = minw; j >= 0; --j) {
      k = min(minw, j + w[i]);
      dp[k] = max(dp[k], dp[j] + t[i] - x * w[i]);
    }
  }
  return dp[minw] >= 0;
}
ll l, r, mid, ans;
int main() {
  cin >> n >> minw;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> t[i];
    t[i] *= 1000;
    r += t[i];
  }
  l = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (judge(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}