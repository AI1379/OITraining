#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = (1ll << 20) + 10;
ll n, q;
ll num[MAXN];
ll query[110];
ll ans[MAXN];
ll bit[MAXN];
ll lowbit(ll x) { return x & (-x); }
ll bitq(ll p) {
  ll res = 0;
  for (; p; p -= lowbit(p))
    res += bit[p];
  return res;
}
void modify(ll p) {
  for (; p <= n; p += lowbit(p))
    ++bit[p];
}
void build(ll l, ll r, ll dep) {
  if (l == r) {
    ans[l] = min(ans[l], dep);
    return;
  }
  ll mid = (l + r) / 2;
  if (bitq(mid) - bitq(l - 1) != 0)
    build(l, mid, dep + 1);
  if (bitq(r) - bitq(mid) != 0)
    build(mid + 1, r, dep + 1);
  if (mid == (l + r + 1) / 2) {
    if (bitq(mid - 1) - bitq(l - 1) != 0)
      build(l, mid - 1, dep + 1);
    if (bitq(mid) - bitq(r - 1) != 0)
      build(mid, r, dep + 1);
  }
}
void init() { build(1, n, 0); }
int main() {
  ll x;
  memset(ans, 0x3f, sizeof(ans));
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  if (lowbit(n) == n) {
    x = log2(n);
    cin >> q;
    for (int i = 1; i <= q; i++) {
      cout << x << endl;
    }
    return 0;
  }
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> x;
    query[i] = lower_bound(num + 1, num + n + 1, x) - num;
    modify(query[i]);
  }
  init();
  for (int i = 1; i <= q; ++i) {
    cout << ans[query[i]] << endl;
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}