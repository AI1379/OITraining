#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n;
ll v[MAXN], f[MAXN], d[MAXN];
ll find(ll x) {
  ll l = 1, r = n;
  ll mid, ans = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (d[mid] < x) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  memset(d, 0x3f, sizeof(d));
  d[1] = 0;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] = find(v[i]);
    ans = max(ans, f[i]);
    d[f[i] + 1] = v[i];
  }
  cout << ans << endl;
  return 0;
}

/*
8
1 2 4 7 4 5 6 8

1 2 3 4 4 5 6 7
*/