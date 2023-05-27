#include <bits/stdc++.h>

#include <cinttypes>
using namespace std;
#define ll long long
const ll MAXN = 1ll << 21;
ll q, n;
char str[MAXN];
ll bit[MAXN];
ll z[MAXN], subf[MAXN], sf;
bool cur[31];
ll ans;
ll lowbit(ll x) { return x & (-x); }
ll query(ll p) {
  ll res = 0;
  for (; p; p -= lowbit(p)) res += bit[p];
  return res;
}
void modify(ll p) {
  for (; p <= n; p += lowbit(p)) ++bit[p];
}
void solve() {
  ll l = 0, r = 0;
  ans = 0;
  scanf("%s", str);
  n = strlen(str);
  memset(bit, 0, sizeof(bit));
  memset(z, 0, sizeof(z));
  memset(cur, false, sizeof(cur));
  z[0] = n;
  // printf("%lld ", n);
  for (int i = 1; i < n; ++i) {
    if (i <= r && i + z[i - l] - 1 < r) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0ll, r - i + 1);
      while (i + z[i] < n && str[i + z[i]] == str[z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
    // printf("%lld ", z[i]);
  }
  // printf("\n");
  subf[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    cur[str[i] - 'a'] ^= 1;
    if (cur[str[i] - 'a'])
      subf[i] = subf[i + 1] + 1;
    else
      subf[i] = subf[i + 1] - 1;
  }
  // for (int i = 0; i < n; ++i) {
  // printf("%lld ", subf[i] - 1);
  // }
  // printf("\n");
  sf = subf[0];
  // printf("%lld\n", sf - 1);
  ll t = 0, now = 1;
  memset(cur, false, sizeof(cur));
  for (int i = 0; i < n; ++i) {
    if (i >= 1) {
      t = z[i + 1] / (i + 1) + 1;
      if (t * (i + 1) == n) --t;
      l = t / 2;        // even
      r = (t + 1) / 2;  // odd
      ans += l * query(sf);
      ans += r * query(subf[i + 1]);
    }
    cur[str[i] - 'a'] ^= true;
    if (cur[str[i] - 'a'])
      ++now;
    else
      --now;
    modify(now);
    // printf("%lld %d %lld %lld\n", t, i, now - 1, ans);
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%lld", &q);
  while (q--) solve();
  return 0;
}