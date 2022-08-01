#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n;
ll c[MAXN];
ll ans[MAXN];
ll ft[110];
ll maxc = 0;
inline ll lowbit(ll x) { return x & (-x); }
ll getMin(ll x) {
  ll res = INF;
  for (; x <= maxc; x += lowbit(x)) {
    res = min(res, ft[x]);
  }
  return res;
}
void modify(ll x, ll a) {
  for (; x; x -= lowbit(x)) {
    ft[x] = min(ft[x], a);
  }
}
int main() {
  memset(ft, 0x3f, sizeof(ft));
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", c + i);
    maxc = max(maxc, c[i]);
  }
  for (int i = n; i >= 1; i--) {
    ans[i] = getMin(c[i] + 1);
    if (ans[i] == INF) ans[i] = -1;
    modify(c[i], i);
  }
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  printf("\n");
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}