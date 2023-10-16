#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 2000010;
ll n;
ll val[MAXN];
ll le[MAXN], re[MAXN];
ll st[31][MAXN];
ll lg2[MAXN];
int main() {
  lg2[0] = -1;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
    st[0][i] = val[i];
    lg2[i] = lg2[i / 2] + 1;
  }
  deque<pll> dq;
  for (int i = 1; i <= n; ++i) {
    while (!dq.empty() && dq.back().first > val[i]) {
      re[dq.back().second] = i - 1;
      dq.pop_back();
    }
    dq.emplace_back(val[i], i);
  }
  while (!dq.empty()) {
    re[dq.back().second] = n;
    dq.pop_back();
  }
  for (int i = n; i >= 1; --i) {
    while (!dq.empty() && dq.back().first > val[i]) {
      le[dq.back().second] = i + 1;
      dq.pop_back();
    }
    dq.emplace_back(val[i], i);
  }
  while (!dq.empty()) {
    le[dq.back().second] = 1;
    dq.pop_back();
  }
  for (int i = 1; (1 << i) <= n; ++i) {
    for (int j = 1; j + (1 << i) <= n; ++j) {
      st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  ll ans = 0, tmp = 0, len;
  for (int i = 1; i <= n; ++i) {
    len = re[i] - le[i] + 1;
    tmp = max(st[lg2[len]][le[i]], st[lg2[len]][re[i] - (1 << lg2[len]) + 1]);
    ans = max(ans, tmp * len * val[i]);
  }
  cout << ans << endl;
  return 0;
}

/**
9
5 11 15 17 19 3 19 9 4
**/
