#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>

using namespace std;
#define ll long long
const ll MAXN = 100010;
struct Node {
  ll p, t, flag;
};
ll n, m1, m2;
Node in[MAXN * 2], out[MAXN * 2];
bool brid[MAXN];
bool cmp(const Node &lhs, const Node &rhs) { return lhs.t <= rhs.t; }
ll calc(ll p) {
  static ll ans, cur;
  ans = cur = 0;
  memset(brid, false, sizeof(brid));
  for (int i = 1; i <= m1 * 2; i++) {
    if (in[i].flag == 1 && cur < p) {
      ++cur;
      ++ans;
      brid[in[i].p] = true;
    } else if (in[i].flag == -1 && brid[in[i].p]) {
      --cur;
    }
  }
  p = n - p;
  memset(brid, false, sizeof(brid));
  for (int i = 1; i <= m2 * 2; i++) {
    if (out[i].flag == 1 && cur < p) {
      ++cur;
      ++ans;
      brid[out[i].p] = true;
    } else if (out[i].flag == -1 && brid[out[i].p]) {
      --cur;
    }
  }
  return ans;
}
static ll l, r, mid1, mid2, dis, ans;
static ll x;
int main() {
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= m1; i++) {
    cin >> x;
    in[i] = (Node){i, x, 1};
    cin >> x;
    in[i + m1] = (Node{i, x, -1});
  }
  for (int i = 1; i <= m2; i++) {
    cin >> x;
    out[i] = (Node){i, x, 1};
    cin >> x;
    out[i + m2] = (Node{i, x, -1});
  }
  sort(in + 1, in + m1 * 2 + 1, cmp);
  sort(out + 1, out + m2 * 2 + 1, cmp);
  l = 0, r = n;
  ans = max(calc(l), calc(r));
  while (l <= r) {
    dis = (r - l + 1) / 3;
    mid1 = calc(l + dis);
    mid2 = calc(r - dis);
    if (mid1 <= mid2)
      l = l + dis + 1, ans = max(ans, mid2);
    else
      r = r - dis - 1, ans = max(ans, mid1);
  }
  cout << ans << endl;
  return 0;
}
