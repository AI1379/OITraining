// #include <bits/stdc++.h>
#include <bitset>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 1010;
bitset<MAXN> a[MAXN];
ll t, n;
void solve() {
  ll p, q;
  cin >> n;
  for (int i = 0; i < MAXN; i++)
    a[i] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> q;
    for (int j = 1; j <= q; j++) {
      cin >> p;
      a[i][p] = true;
    }
  }
  ll x = -1, y = -1;
  bool flag = false;
  bitset<MAXN> tmp;
  for (int i = 1; i <= n; i++) {
    if (flag)
      break;
    for (int j = i + 1; j <= n; j++) {
      tmp = a[i] & a[j];
      if (tmp.count() > 0 && (a[i] ^ tmp).count() > 0 &&
          (a[j] ^ tmp).count() > 0) {
        flag = true;
        x = i;
        y = j;
      }
    }
  }
  if (flag) {
    cout << "YES" << endl << x << ' ' << y << endl;
  } else {
    cout << "NO" << endl;
  }
  return;
}
int main() {
#ifndef DEBUG
  freopen("discuss.in", "r", stdin);
  freopen("discuss.out", "w", stdout);
#endif
  cin >> t;
  while (t--)
    solve();
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}