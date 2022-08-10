#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll cartesian[MAXN][2], fa[MAXN];
ll n, q, rt;
ll a[MAXN];
ll stk[MAXN], top = 0;
void build() {
  for (int i = 1; i <= n; i++) {
    while (top && a[stk[top]] < a[i]) cartesian[i][0] = stk[top--];
    cartesian[stk[top]][1] = i;
    stk[++top] = i;
  }
  rt = stk[1];
  return;
}
ll query(ll l, ll r) {
  ll x = rt;
  while (x < l || x > r) {
    if (x < l)
      x = cartesian[x][1];
    else
      x = cartesian[x][0];
  }
  return x;
}
int main() {
  ll l, r, res;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build();
  while (q--) {
    cin >> l >> r;
    if (l > r) swap(l, r);
    res = query(l, r);
    cout << a[res] << endl;
  }
  return 0;
}
