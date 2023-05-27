#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MAXK = 200010;
struct Point {
  ll a, b, c, cnt, ans;
};
bool operator!=(const Point &lhs, const Point &rhs) {
  return lhs.a != rhs.a || lhs.b != rhs.b || lhs.c != rhs.c;
}
ll n, k, tot;
ll tag[MAXK], curtag = 1, bit[MAXK];
ll ans[MAXK];
Point val[MAXN], unival[MAXN];
ll lowbit(ll x) { return x & (-x); }
ll query(ll p) {
  ll res = 0;
  for (; p; p -= lowbit(p)) {
    if (tag[p] == curtag)
      res += bit[p];
  }
  return res;
}
void modify(ll p, ll d) {
  for (; p <= k; p += lowbit(p)) {
    if (tag[p] != curtag)
      bit[p] = 0;
    tag[p] = curtag;
    bit[p] += d;
  }
}
void solve(ll l, ll r) {
  if (l == r)
    return;
  ll mid = (l + r) / 2;
  solve(l, mid);
  solve(mid + 1, r);
  auto cmp = [](const Point &lhs, const Point &rhs) {
    if (lhs.b == rhs.b)
      return lhs.c < rhs.c;
    return lhs.b < rhs.b;
  };
  sort(unival + l, unival + mid + 1, cmp);
  sort(unival + mid + 1, unival + r + 1, cmp);
  ll i = l, j = mid + 1;
  while (j <= r) {
    while (i <= mid && unival[i].b <= unival[j].b) {
      modify(unival[i].c, unival[i].cnt);
      ++i;
    }
    unival[j].ans += query(unival[j].c);
    ++j;
  }
  ++curtag;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i].a >> val[i].b >> val[i].c;
  }
  sort(val + 1, val + n + 1, [](const Point &lhs, const Point &rhs) {
    if (lhs.a != rhs.a)
      return lhs.a < rhs.a;
    if (lhs.b != rhs.b)
      return lhs.b < rhs.b;
    return lhs.c < rhs.c;
  });
  ll cur = 0;
  for (int i = 1; i <= n; ++i) {
    ++cur;
    if (val[i] != val[i + 1]) {
      unival[++tot] = val[i];
      unival[tot].cnt = cur;
      cur = 0;
    }
  }
  solve(1, tot);
  for (int i = 1; i <= tot; ++i)
    ans[unival[i].ans + unival[i].cnt] += unival[i].cnt;
  for (int i = 1; i <= n; ++i)
    cout << ans[i] << endl;
  return 0;
}