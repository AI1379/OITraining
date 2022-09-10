#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MAXH = 50010;
ll n = 0, m;
ll a[MAXN], f[MAXN];
ll bit[MAXH];
ll lowbit(ll x) {
  return x & (-x);
}
void modify_greater(ll pos, ll val) {
  for (; pos; pos -= lowbit(pos)) {
    bit[pos] = max(bit[pos], val);
  }
}
ll query_greater(ll pos) {
  ll res = 0;
  for (; pos <= m; pos += lowbit(pos)) {
    res = max(res, bit[pos]);
  }
  return res;
}
void modify_less(ll pos, ll val) {
  for (; pos <= m; pos += lowbit(pos)) {
    bit[pos] = max(bit[pos], val);
  }
}
ll query_less(ll pos) {
  ll res = 0;
  for (; pos ; pos -= lowbit(pos)) {
    res = max(res, bit[pos]);
  }
  return res;
}
int main() {
  ll x;
#ifdef DEBUG
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i] = a[i];
  }
#else
  while (cin >> x) {
    ++n;
    a[n] = f[n] = x;
  }
#endif
  sort(f + 1, f + n + 1);
  m = unique(f + 1, f + n + 1) - f - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(f + 1, f + m + 1, a[i]) - f;
  }
  ll dp = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    dp = query_greater(a[i]) + 1;
    ans = max(ans, dp);
    modify_greater(a[i], dp);
  }
  cout << ans << endl;
  memset(bit, 0, sizeof(bit));
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    dp = query_less(a[i] - 1) + 1;
    ans = max(dp, ans);
    modify_less(a[i], dp);
  }
  cout << ans << endl;
  return 0;
}
