#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll MAXN = 15010;
const ll MAXX = 32010;
ll n, m;
pll stars[MAXN];
ll bit[MAXX];
ll lowbit(ll x) {
  return x & (-x);
}
ll query(ll pos) {
  ll res = 0;
  for (; pos; pos -= lowbit(pos)) {
    res += bit[pos];
  }
  return res;
}
void modify(ll pos, ll delta) {
  for (; pos <= m; pos += lowbit(pos)) {
    bit[pos] += delta;
  }
}
ll ans[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> stars[i].first >> stars[i].second;
    m = max(m, stars[i].first);
  }
  ll x;
  for (int i = 1; i <= n; i++) {
    x = query(stars[i].first);
    ++ans[x];
    modify(stars[i].first, 1);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
