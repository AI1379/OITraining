#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 5000010;
const ll MOD = 917120411;
const ll BASE = 211;
char str[MAXN];
int k;
ll h[MAXN], p[MAXN];
ll len;
unordered_map<ll, ll> mp;
void init() {
  p[0] = 1;
  for (int i = 1; i <= len; i++) {
    h[i] = (h[i - 1] * BASE % MOD + str[i]) % MOD;
    p[i] = p[i - 1] * BASE % MOD;
  }
}
ll get_hash(int l, int r) {
  ll res;
  res = (h[r] - h[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
  return res;
}
int main() {
  scanf("%s", str + 1);
  scanf("\n");
  scanf("%d", &k);
  len = strlen(str + 1);
  init();
  for (int i = k; i <= len; i++) {
    mp[get_hash(i - k + 1, i)]++;
  }
  ll ans = 0;
  for (auto i : mp) {
    ans = max(ans, i.second);
  }
  printf("%d", ans);
  return 0;
}