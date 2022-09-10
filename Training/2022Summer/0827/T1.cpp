#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n;
ll a[MAXN], b[MAXN];
ll bit[MAXN];
ll lowbit(ll x) { return x & (-x); }
ll query(ll pos) {
  ll res = 0;
  for (; pos <= n; pos += lowbit(pos))
    res += bit[pos];
  return res;
}
void update(ll pos) {
  for (; pos; pos -= lowbit(pos))
    ++bit[pos];
}
ll ans = 1;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
  }
  for (int i = 1; i <= n; i++) {
    ans = max(query(i), ans);
    update(a[i]);
  }
  cout << ans << '\n';
  return 0;
}