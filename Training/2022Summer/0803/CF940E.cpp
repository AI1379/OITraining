// https://codeforces.com/problemset/problem/940/E
// https://www.luogu.com.cn/problem/CF940E
#include <iostream>
#include <deque>
#include <utility>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, c;
ll a[MAXN];
ll pre[MAXN];
ll mina[MAXN];
ll dp[MAXN];
deque<pair<ll, ll>>dq;
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  dq.push_back(make_pair(0, 0));
  for (int i = 1; i <= n; i++) {
    while (!dq.empty() && dq.front().second < i - c + 1) {
      dq.pop_front();
    }
    while (!dq.empty() && dq.back().first >= a[i]) {
      dq.pop_back();
    }
    dq.push_back(make_pair(a[i], i));
    mina[i] = dq.front().first;
  }
  for (int i = 1; i < c; i++) {
    dp[i] = dp[i - 1] + a[i];
  }
  for (int i = c; i <= n; i++) {
    dp[i] = min(dp[i - c] + pre[i] - pre[i - c] - mina[i], dp[i - 1] + a[i]);
  }
  cout << dp[n] << endl;
  return 0;
}
