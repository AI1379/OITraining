#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 30010;
ll t;
const ll n = 30000;
ll fa[MAXN];
ll w[MAXN];
ll len[MAXN];
ll find(ll p) {
  if (fa[p] == p)
    return p;
  auto fu = find(fa[p]);
  w[p] += w[fa[p]];
  fa[p] = fu;
  return fa[p];
}
void merge(ll u, ll v) {
  auto fu = find(u), fv = find(v);
  fa[fu] = fv;
  w[fu] += len[fv];
  len[fv] += len[fu];
}
int main() {
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    len[i] = 1;
  }
  char opt;
  ll x, y;
  cin >> t;
  while (t--) {
    cin >> opt >> x >> y;
    if (opt == 'M') {
      merge(x, y);
    } else {
      auto fx = find(x), fy = find(y);
      if (fx != fy) {
        cout << "-1" << endl;
      } else {
        cout << abs(w[x] - w[y]) - 1 << endl;
      }
    }
  }
  return 0;
}