#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, k;
ll v[MAXN];
int main() {
#ifndef DEBUG
  freopen("T1.in", "r", stdin);
  freopen("T1.out", "w", stdout);
#endif
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> v[i];
  for (int i = 1; i <= n; ++i)
    cin >> v[i];
  sort(v + 1, v + n + 1, greater<ll>());
  ll ans = 0;
  for (int i = 1; i <= k; ++i)
    ans += v[i];
  cout << ans << endl;
  return 0;
}