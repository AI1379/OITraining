#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2000010;
const ll BASE = 223;
const ll MOD = 998244353;
ll n;
char s[MAXN];
ll powbase[MAXN];
ll cur;
char stk[MAXN];
ll top = 0;
map<ll, ll> tab;
ll ans = 0;
int main() {
  scanf("%lld", &n);
  scanf("%s", s + 1);
  powbase[0] = 1;
  for (int i = 1; i <= n; ++i)
    powbase[i] = powbase[i - 1] * BASE % MOD;
  ++tab[0];
  for (int i = 1; i <= n; ++i) {
    if (top && stk[top] == s[i]) {
      cur = (cur - stk[top] * powbase[top - 1] % MOD + MOD) % MOD;
      --top;
    } else {
      stk[++top] = s[i];
      cur = (cur + stk[top] * powbase[top - 1] % MOD) % MOD;
    }
    ans += tab[cur];
    ++tab[cur];
    // printf("%lld %lld %s\n", cur, top, stk + 1);
  }
  printf("%lld\n", ans);
  return 0;
}