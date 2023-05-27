#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 300010;
ll n;
ll maxr = 0;
ll ans = 0;
ll rg[MAXN * 2];
ll bit[MAXN];
ll lowbit(ll p) { return p & (-p); }
ll query(ll p) {
  ll res = 0;
  for (; p; p -= lowbit(p))
    res += bit[p];
  return res;
}
void modify(ll p, ll delta) {
  for (; p <= maxr; p += lowbit(p))
    bit[p] += delta;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> rg[i] >> rg[i + n];
    rg[i + n]++;
    maxr = max(maxr, rg[i + n]);
  }
  for (int i = 1; i <= n; i++) {
    modify(rg[i], 1);
    modify(rg[i + n], -1);
  }
  sort(rg + 1, rg + 2 * n + 1);
  ll tmp = unique(rg + 1, rg + 2 * n + 1) - rg;
  for (int i = 1; i <= tmp; i++) {
    ans = max(ans, query(rg[i]) * (rg[i + 1] - rg[i] - 1));
    // cout << ans << ' ';
  }
  cout << ans << endl;
  return 0;
}