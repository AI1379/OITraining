#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll t;
ll n;
ll a[MAXN], b[MAXN];
ll idx[MAXN];
ll bit[MAXN];
ll sum[MAXN], pre[MAXN];
ll lowbit(ll x) { return x & (-x); }
void modifyBit(ll p) {
  for (; p <= n; p += lowbit(p))
    ++bit[p];
}
ll queryBit(ll p) {
  static ll res;
  res = 0;
  for (; p; p -= lowbit(p))
    res += bit[p];
  return res;
}
ll query(ll *x, ll *y) {
  static ll res;
  res = 4;
  memset(bit, 0, sizeof(bit));
  memset(sum, 0, sizeof(sum));
  sort(idx + 1, idx + n + 1, [x, y](const ll &lhs, const ll &rhs) {
    if (x[lhs] == x[rhs])
      return y[lhs] < y[rhs];
    return x[lhs] > x[rhs];
  });
  for (int i = 1; i <= n; ++i) {
    modifyBit(y[idx[i]]);
    cout << x[idx[i]] << ' ' << y[idx[i]] << ' ' << queryBit(y[idx[i]]) << endl;
    if (queryBit(y[idx[i]]) == n / 2) {
      res = 3;
      break;
    }
  }
  for (int i = 1; i <= n; ++i)
    ++sum[y[i]];
  for (int i = 1; i <= n; ++i)
    pre[i] = pre[i - 1] + sum[i];
  ll m = lower_bound(pre + 1, pre + n + 1, n / 2) - pre;
  if (pre[m] == n / 2)
    res = 2;
  return res;
}
ll ans;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    idx[i] = i;
  }
  ans = min(query(a, b), query(b, a));
  cout << ans << endl;
  return;
}
int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}