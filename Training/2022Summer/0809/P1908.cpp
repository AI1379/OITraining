#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const ll MAXN = 500010;
ll n, m;
ll a[MAXN], f[MAXN];
ll bit[MAXN];
ll lowbit(ll x) {
  return x & (-x);
}
void modify(ll pos, ll delta) {
  for (; pos <= m; pos += lowbit(pos)) {
    bit[pos] += delta;
  }
}
ll query(ll pos) {
  ll res = 0;
  for (; pos; pos -= lowbit(pos)) {
    res += bit[pos];
  }
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i] = a[i];
  }
  sort(f + 1, f + n + 1);
  m = unique(f + 1, f + n + 1) - f - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(f + 1, f + m + 1, a[i]) - f;
  }
  ll ans = 0;
  for (int i = n; i >= 1; --i) {
    ans += query(a[i] - 1);
    modify(a[i], 1);
  }
  cout << ans << endl;
  return 0;
}
