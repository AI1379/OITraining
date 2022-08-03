// https://loj.ac/p/10180

#include <deque>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
#define ll long long
const ll MAXN = 200010;
ll n, m;
ll cost[MAXN];
ll dp[MAXN];
deque<pair<ll, ll>> dq;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> cost[i];
  }
  dq.push_back(make_pair(0, 0));
  for (int i = 1; i <= n; ++i) {
    while (!dq.empty() && i - dq.front().second > m) {
      dq.pop_front();
    }
    dp[i] = dq.front().first + cost[i];
    while (!dq.empty() && dq.back().first >= dp[i]) {
      dq.pop_back();
    }
    dq.push_back(make_pair(dp[i], i));
  }
  ll ans = (1 << 30);
  for (int i = n - m + 1; i <= n; ++i) {
    ans = min(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
