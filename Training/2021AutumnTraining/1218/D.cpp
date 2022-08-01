#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 5010;
const ll MAXM = 5010;
ll n, m;
ll fa[MAXN];
ll d[MAXN];
ll fd(ll x) {
  if (fa[x] == x) return fa[x];
  ll rt = fd(fa[x]);
  d[x] += d[fa[x]];
  return fa[x] = rt;
}
void un(ll x, ll y, ll w) {
  ll fax = fd(x), fay = fd(y);
  if (fax == fay) return;
  fa[fax] = fay;
  d[fax] = w + d[y] - d[x];
  return;
}
ll ans = 0;
int main() {
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    d[i] = 0;
  }
  ll opt, x, y;
  while (m--) {
    scanf("%lld%lld%lld", &opt, &x, &y);
    if (opt & 1) {
      un(x, y, 0);
    } else {
      un(x, y, opt - 3);
    }
  }
  ll mind = 0;
  for (int i = 1; i <= n; i++) {
    fd(i);
    ans += d[i];
    mind = min(mind, d[i]);
#ifdef DEBUG
    printf("%lld %lld \n", i, d[i] + 1 - mind);
#endif
  }
  ans += n * (1 - mind);
  printf("%lld\n", ans);
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}