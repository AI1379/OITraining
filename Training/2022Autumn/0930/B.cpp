// https://www.luogu.com.cn/problem/P5124
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10010;
ll n, k;
ll skl[MAXN];
ll dp[MAXN];
int main() {
  ll maxskl = 0;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> skl[i];
  }
  for (int i = 1; i <= n; ++i) {
    maxskl = 0;
    for (int j = 1; j <= k && i + j - 1 <= n; ++j) {
      maxskl = max(maxskl, skl[i + j - 1]);
      dp[i + j - 1] = max(dp[i + j - 1], dp[i - 1] + j * maxskl);
    }
  }
  cout << dp[n] << endl;
  return 0;
}