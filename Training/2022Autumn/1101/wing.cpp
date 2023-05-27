#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 200010;
ll n, m, c;
ll p[MAXN], w[MAXN];
ll pre[MAXN], suf[MAXN];
pll tmp[MAXN];
bool judge(ll pos) {
  if (pre[pos - 1] + suf[pos + 1] + w[pos] <= c)
    return true;
  else
    return false;
}
priority_queue<ll> q;
int main() {
#ifndef DEBUG
  freopen("wing.in", "r", stdin);
  freopen("wing.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
  cin >> n >> m >> c;
  for (int i = 1; i <= n; ++i) cin >> tmp[i].first;
  for (int i = 1; i <= n; ++i) cin >> tmp[i].second;
  sort(tmp + 1, tmp + n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = tmp[i].first;
    w[i] = tmp[i].second;
  }
  for (int i = 1; i <= m / 2; ++i) {
    q.push(w[i]);
    pre[m / 2] += w[i];
  }
  for (int i = m / 2 + 1; i <= n; ++i) {
    pre[i] = min(pre[i - 1], pre[i - 1] - q.top() + w[i]);
    if (pre[i] < pre[i - 1]) {
      q.pop();
      q.push(w[i]);
    }
  }
  q = decltype(q)();
  for (int i = n; i >= n - m / 2 + 1; --i) {
    q.push(w[i]);
    suf[n - m / 2 + 1] += w[i];
  }
  for (int i = n - m / 2; i >= 1; --i) {
    suf[i] = min(suf[i + 1], suf[i + 1] - q.top() + w[i]);
    if (suf[i] < suf[i + 1]) {
      q.pop();
      q.push(w[i]);
    }
  }
  ll l = m / 2 + 1, r = n - m / 2, ans = -1, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (judge(mid)) {
      l = mid + 1;
      ans = p[mid];
    } else {
      r = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}