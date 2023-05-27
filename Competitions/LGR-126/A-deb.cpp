#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll t, btag;
ll n;
ll a[MAXN], b[MAXN];
ll idx[MAXN];
ll bit[MAXN], tag[MAXN];
ll sum[MAXN], pre[MAXN];
fstream ifs;
ll lowbit(ll x) { return x & (-x); }
void modifyBit(ll p) {
  for (; p <= n; p += lowbit(p)) {
    if (tag[p] != btag)
      bit[p] = 0;
    ++bit[p];
    tag[p] = btag;
  }
}
ll queryBit(ll p) {
  static ll res;
  res = 0;
  for (; p; p -= lowbit(p)) {
    if (tag[p] == btag)
      res += bit[p];
  }
  return res;
}
ll query(ll *x, ll *y) {
  static ll res, l, r, m;
  res = 4;
  ++btag;
  memset(sum, 0, sizeof(sum));
  sort(idx + 1, idx + n + 1, [x, y](const ll &lhs, const ll &rhs) {
    if (x[lhs] == x[rhs])
      return y[lhs] < y[rhs];
    return x[lhs] > x[rhs];
  });
  l = 1ll << (sizeof(ll) * 8 - 2);
  r = 0;
  for (int i = 1; i <= n; ++i) {
    modifyBit(y[idx[i]]);
    l = min(l, y[idx[i]]);
    r = max(r, y[idx[i]]);
    if (x[idx[i]] != x[idx[i + 1]] && i >= n / 2) {
      while (l <= r) {
        m = (l + r) / 2;
        if (queryBit(m) < n / 2) {
          l = m + 1;
        } else if (queryBit(m) == n / 2) {
          res = 3;
          goto next;
        } else {
          r = m - 1;
        }
      }
      l = 1ll << (sizeof(ll) * 8 - 2);
      r = 0;
    }
  }
next:
  for (int i = 1; i <= n; ++i)
    ++sum[y[i]];
  for (int i = 1; i <= n; ++i)
    pre[i] = pre[i - 1] + sum[i];
  m = *lower_bound(pre + 1, pre + n + 1, n / 2);
  if (m == n / 2)
    res = 2;
  return res;
}
ll ans;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    idx[i] = i;
  }
  ans = min(query(a, b), query(b, a));
  cout << ans << endl;
  ll k;
  ifs >> k;
  if (ans != k) {
    cerr << n << endl;
    for (int i = 1; i <= n; ++i) {
      cerr << a[i] << ' ' << b[i] << endl;
    }
    exit(0);
  }
  return;
}
int main() {
  ifs = fstream("ex_line2.out");
  freopen("ex_line2.in", "r", stdin);
  freopen("line.o", "w", stdout);
  cin >> t;
  while (t--)
    solve();
  return 0;
}