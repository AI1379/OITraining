#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, tot;
ll val[MAXN], f[MAXN];
ll bit[MAXN];
ll lowbit(ll x) { return x & (-x); }
void modify(ll x, ll d) {
  for (; x <= tot; x += lowbit(x))
    bit[x] = max(bit[x], d);
}
ll query(ll x) {
  ll res = 0;
  for (; x; x -= lowbit(x))
    res = max(bit[x], res);
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
    f[i] = val[i];
  }
  sort(f + 1, f + n + 1);
  tot = unique(f + 1, f + n + 1) - f - 1;
  for (int i = 1; i <= n; ++i) {
    val[i] = lower_bound(f + 1, f + tot + 1, val[i]) - f;
  }
  ll dp = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    dp = query(val[i] - 1) + 1;
    ans = max(dp, ans);
    modify(val[i], dp);
  }
  cout << ans << endl;
  return 0;
}