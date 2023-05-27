#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 110;
const ll MAXA = 25010;
ll t;
ll n;
ll a[MAXN];
bool dp[MAXA], vis[MAXA];
bool dfs(ll num, ll k) {
  if (vis[num]) return dp[num];
  for (int i = 1; i <= k; ++i) {
    if (num % a[i] == 0 && !dfs(a[i], k)) {
      return dp[num] = true;
    }
  }
  vis[num] = true;
  for (int i = 1; i <= num; ++i) {
    if (dfs(i, k) && dfs(num - i, k)) {
      return dp[num] = true;
    }
  }
  return dp[num] = false;
}
void solve() {
  // memset(a, 0, sizeof(a));
  // memset(dp, false, sizeof(dp));
  memset(vis, false, sizeof(vis));
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!dfs(a[i], i - 1)) {
      dp[a[i]] = true;
      ++ans;
      // cout << a[i] << endl;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) solve();
  return 0;
}