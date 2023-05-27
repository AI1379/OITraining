#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 31;
ll n;
ll val[MAXN];
ll dp[MAXN][MAXN];
ll p[MAXN][MAXN];
void dfs(ll l, ll r) {
  if (l > r) dp[l][r] = 1;
  if (l == r) return;
  for (int i = l; i <= r; ++i) {
    dfs(l, i - 1);
    dfs(i + 1, r);
    if (dp[l][r] < dp[l][i - 1] * dp[i + 1][r] + val[i]) {
      p[l][r] = i;
      dp[l][r] = dp[l][i - 1] * dp[i + 1][r] + val[i];
    }
  }
}
void print(ll l, ll r) {
  if (l > r) return;
  cout << p[l][r] << ' ';
  print(l, p[l][r] - 1);
  print(p[l][r] + 1, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
    dp[i][i] = val[i];
    p[i][i] = i;
  }
  dfs(1, n);
  cout << dp[1][n] << endl;
  print(1, n);
  return 0;
}