#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
ll n, m;
string str;
ll pre = 0, sub = 0;
ll stk = 0;
ll dp[2010][2010];
ll solve() {
  ll res = 0;
  n -= m;
  dp[0][0] = 1;
  for (ll i = 1; i <= n; i++)
    for (ll j = 0; j <= i; j++)
      dp[i][j] = ((j != 0 ? dp[i - 1][j - 1] : 0) + dp[i - 1][j + 1]) % MOD;
  for (int i = pre; i <= n - sub; i++)
    for (int j = 0; pre + j <= i && sub + j <= n - i; j++)
      res = (res + dp[i][pre + j] * dp[n - i][sub + j] % MOD) % MOD;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  cin >> str;
  for (auto c : str) {
    if (c == '(') {
      stk++;
    } else {
      if (stk == 0) {
        pre++;
      } else {
        stk--;
      }
    }
  }
  sub = stk;
  cout << solve() << endl;
  return 0;
}