#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
const ll MOD = 1e9 + 7;
ll n, k;
vector<ll> tree[MAXN];
ll subsiz[MAXN][15];
ll subsizpre[MAXN][15];
ll submul[MAXN][15];
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
void updfs(ll u, ll fa) {
  subsiz[u][0] = 1;
  for (int i = 0; i <= k; ++i)
    submul[u][i] = 1;
  for (auto v : tree[u]) {
    if (v != fa) {
      updfs(v, u);
      for (int i = 1; i <= k; ++i) {
        subsiz[u][i] += subsiz[v][i - 1];
        submul[u][i] = submul[u][i] * submul[v][i - 1] % MOD;
      }
    }
  }
  for (int i = 1; i <= k; ++i)
    subsizpre[u][i] = subsizpre[u][i - 1] + subsiz[u][i];
  for (int i = 1; i <= k; ++i)
    submul[u][i] = submul[u][i] * subsizpre[u][i] % MOD;
}
void downdfs(ll u, ll fa) {
  if (fa != 0) {
    for (int i = k; i >= 2; --i) {
      submul[u][i] = submul[u][i] * submul[fa][i - 1] % MOD *
                     qpow(submul[u][i - 2], MOD - 2) % MOD *
                     qpow(subsizpre[u][i], MOD - 2) % MOD *
                     (subsizpre[fa][i - 1] - subsizpre[u][i - 2]) % MOD *
                     qpow(subsizpre[fa][i - 1], MOD - 2) % MOD;
      subsiz[u][i] += subsiz[fa][i - 1] - subsiz[u][i - 2];
    }
    ++subsiz[u][1];
    submul[u][1] = 1;
    for (int i = 1; i <= k; ++i) {
      subsizpre[u][i] = subsizpre[u][i - 1] + subsiz[u][i];
      submul[u][i] = submul[u][i] * subsizpre[u][i] % MOD;
    }
  }
  for (auto v : tree[u]) {
    if (v != fa) {
      downdfs(v, u);
    }
  }
}
int main() {
  ll u, v;
  cin >> n >> k;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i)
    subsizpre[i][0] = 1;
  updfs(1, 0);
  downdfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    cout << subsizpre[i][k] << ' ';
  }
  cout << endl;
  for (int i = 1; i <= n; ++i)
    cout << submul[i][k] << ' ';
  cout << endl;
  return 0;
}