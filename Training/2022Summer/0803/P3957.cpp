// https://www.luogu.com.cn/problem/P3957

#include <iostream>
#include <algorithm>
#include <deque>
#include <utility>
#include <cstring>
using namespace std;
#define ll long long
const ll MAXN = 500010;
const ll MAXD = 2010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll NEG_INF = 0x8080808080808080;
ll n, d, k;
pair<ll, ll> mp[MAXN];
ll dp[MAXN];
ll idx[MAXD];
void buildIdx(ll x) {
  ll curr = 0;
  for (int i = 1; i <= n; ++i) {
    while (mp[i].first >= mp[curr + 1].first + x) {
      ++curr;
    }
    idx[i] = curr;
  }
}
bool judge(ll g) {
  ll ans = NEG_INF;
  ll curr = 0;
  memset(dp, 0x80, sizeof(dp));
  ll x, y;
  deque<pair<ll, ll>>dq;
  x = max(d - g, 1ll);
  y = d + g;
  buildIdx(x);
  dq.push_back(make_pair(0, 0));
  for (int i = 1; i <= n; i++) {
    while (!dq.empty() && mp[dq.front().second].first < mp[i].first - y) {
      dq.pop_front();
    }
    while (curr <= idx[i]) {
      while (!dq.empty() && dq.back().first <= dp[curr]) {
        dq.pop_back();
      }
      dq.push_back(make_pair(dp[curr], curr));
      ++curr;
    }
    dp[i] = dq.front().first + mp[i].second;
    ans = max(ans, dp[i]);
  }
  return ans >= k;
}
int main() {
  ll l = 0, r = 0, sum = 0, mid;
  cin >> n >> d >> k;
  for (int i = 1; i <= n; i++) {
    cin >> mp[i].first >> mp[i].second;
    if (mp[i].second > 0) {
      sum += mp[i].second;
    }
    l = max(l, mp[i].first - mp[i - 1].first);
  }
  if (sum < k) {
    cout << "-1" << endl;
    return 0;
  }
  judge(2);
  l = max(0ll, l - d);
  r = max(mp[n].first, d);
  while (l < r) {
    mid = (l + r) / 2;
    if (judge(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (judge(r)) {
    cout << r << endl;
  } else {
    cout << "-1" << endl;
  }

  return 0;
}
