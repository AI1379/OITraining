#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1e5 + 5;
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
ll a[MAXN], lis[MAXN];
ll n, pos, p = 1, ans = 0;
int main() {
  cin >> n >> pos;
  for (ll i = 1; i <= n; i++) cin >> a[i];
  lis[1] = a[1];
  for (ll i = 2; i < pos; i++) {
    if (a[i] >= lis[p])
      lis[++p] = a[i];
    else
      *lower_bound(lis + 1, lis + p + 1, a[i]) = a[i];
  }
  if (a[pos] >= lis[p])
    p++;
  else
    a[pos] = INF;
  ans = pos - p;
  p = 1;
  lis[1] = a[pos];
  for (ll i = pos + 1; i <= n; i++) {
    if (a[i] <= lis[p])
      lis[++p] = a[i];
    else
      *lower_bound(lis + 1, lis + p + 1, a[i], greater<ll>()) = a[i];
  }
  ans += (n - pos + 1) - p;
  cout << ans << endl;
  return 0;
}