#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll n, m;
ll val[MAXN];
ll pre[MAXN];
map<ll, ll> tab;
ll mx, mn = MAXN * MAXN, odd, xsm;
int main() {
  ll p, x, cur = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
    pre[i] = pre[i - 1] ^ val[i];
    ++tab[pre[i]];
  }
  for (auto p : tab) {
    cur += p.second * (p.second - 1) / 2;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> p >> x;
  }
  return 0;
}