#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MOD = 1000000007;
ll n;
ll a[MAXN];
ll tpow[MAXN];
vector<ll> tree[MAXN];
void add(ll x, ll *cnt) {
  static ll k;
  for (k = 0; x; ++k, x >>= 1)
    if (x & 1)
      ++cnt[k];
}
void dfs(ll u) {
  ll cnt[31], tot = 1;
  memset(cnt, 0, sizeof(cnt));
  add(a[u], cnt);
  for (auto v : tree[u]) {
    dfs(v);
    add(v, cnt);
    ++tot;
  }
  if (tot == 1)
    return;
  
}
int main() {
  ll u, v;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 2; i <= n; ++i) {
    cin >> v;
    tree[i].push_back(v);
  }
  tpow[0] = 1;
  for (int i = 1; i <= n; ++i)
    tpow[i] = tpow[i - 1] * 2ll % MOD;

  return 0;
}