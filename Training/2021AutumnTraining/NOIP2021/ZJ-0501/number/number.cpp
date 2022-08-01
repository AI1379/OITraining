#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10000010;
const ll MAXT = 200010;
const ll MAXS = 800000;
ll t;
bool abl[MAXN];
ll lst[MAXS];
ll tot = 0;
bool check(ll x) {
  while (x) {
    if (x % 10 == 7) return true;
    x /= 10;
  }
  return false;
}
void init() {
  memset(abl, true, sizeof(abl));
  for (int i = 1; i < MAXN; i++) {
    if (!abl[i]) continue;
    if (i % 7 == 0) {
      abl[i] = false;
    } else if (check(i)) {
      for (int j = 1; 1ll * j * i < MAXN; j++) abl[1ll * j * i] = false;
    } else if (abl[i]) {
      lst[++tot] = i;
    }
  }
}
void solve() {
  ll x;
  scanf("%lld", &x);
  if (!abl[x]) {
    printf("-1\n");
    return;
  }
  ll ans = *lower_bound(lst + 1, lst + tot + 1, x + 1);
  printf("%lld\n", ans);
  return;
}
int main() {
#ifndef DEBUG
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
#endif
  scanf("%lld", &t);
  init();
  while (t--) solve();
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}