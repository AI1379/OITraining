#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 500010;
ll n, q, m;
ll a[MAXN], b[MAXN], c[MAXN];
ll cur;
ll val[MAXN];
ll bas[MAXN];
ll lg2[MAXN];
ll st[31][MAXN];
ll query(ll l, ll r) {
  if (r < l)
    return 0;
  ll lglen = lg2[r - l];
  return min(st[lglen][l], st[lglen][r - (1 << lglen) + 1]);
}
void solve() {
  ll ans = 0, cur = 0;
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> val[i];
    cur -= b[val[i]];
  }
  val[m + 1] = n + 1;
  // v[i] = bas[i] + sigma(<=i, c[val[i]]) - sigma(>i, b[val[i]])
  ans = query(0, val[1] - 1) + cur;
  for (int i = 1; i <= m; ++i) {
    cur = cur + b[val[i]] + c[val[i]];
    ans = min(ans, query(val[i], val[i + 1] - 1) + cur);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    bas[0] += b[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  st[0][0] = bas[0];
  lg2[0] = -1;
  for (int i = 1; i <= n; ++i) {
    bas[i] = bas[i - 1] - a[i - 1] - b[i] + a[i];
    st[0][i] = bas[i];
    lg2[i] = lg2[i / 2] + 1;
  }
  lg2[0] = 0;
  for (int k = 1; (1 << k) <= n + 1; ++k) {
    for (int i = 0; i + (1 << (k - 1)) <= n; ++i) {
      st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
      // cout << k << ' ' << i << ' ' << st[k][i] << endl;
    }
  }
  cin >> q;
  while (q--) {
    solve();
  }
  // cout << query(0, n) << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << bas[i] << ' ';
  // }
  cout << endl;
  return 0;
}
/**
5
1 13 6 0 6
2 4 1 0 5
3 4 1 2 1
7
1 4
2 1 5
1 4
2 2 3
5 1 2 3 4 5
1 5
2 3 4

7
3
7
6
0
0
8

10
6 10 7 2 8 4 6 4 8 7
4 0 6 7 8 4 8 2 10 5
4 10 6 1 4 7 5 3 8 7
1
0

7
10 1 6 9 4 2 4
0 5 2 3 0 1 4
4 1 4 1 5 3 5
6
3 1 3 6
2 2 6
4 3 4 5 7
1 4
2 3 7
3 3 5 6

12
8
2
5
5
8

**/