// https://www.luogu.com.cn/problem/P2627

#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, k;
ll pre[MAXN];
ll effi[MAXN];
ll dp[MAXN];
deque<pair<ll, ll>>dq;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> effi[i];
    pre[i] = pre[i - 1] + effi[i];
  }
  dq.push_back(make_pair(0, 0));
  for (int i = 1; i <= n; i++) {
    while (!dq.empty() && dq.back().first <= dp[i - 1] - pre[i]) {
      dq.pop_back();
    }
    dq.push_back(make_pair(dp[i - 1] - pre[i], i));
    while (!dq.empty() && dq.front().second < i - k) {
      dq.pop_front();
    }
    dp[i] = dq.front().first + pre[i];
  }
  cout << dp[n] << endl;
  return 0;
}
