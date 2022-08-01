#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 300010;
ll n, k;
ll a[MAXN];
ll sum[MAXN];
ll st[MAXN][20];
ll query(ll l, ll r) {
  ll x = log2(r - l + 1);
  return max(st[l][x], st[r - (1 << x) + 1][x]);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    st[i][0] = a[i];
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  ll ans = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l + 1; r <= n; r++) {
      if ((sum[r] - sum[l - 1] - query(l, r)) % k == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}