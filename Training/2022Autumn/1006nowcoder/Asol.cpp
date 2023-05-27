#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
const ll MAXM = 100010;
ll read() {
  static char c;
  static ll res;
  res = 0;
  do
    c = getchar();
  while (c < '0' || '9' < c);
  do {
    res = res * 10 + c - '0';
    c = getchar();
  } while ('0' <= c && c <= '9');
  return res;
}
ll readw() {
  static char c;
  static ll res, k;
  res = 0;
  k = 1;
  do
    c = getchar();
  while (c < '0' || '9' < c);
  do {
    res += k * (c - '0');
    k *= 10;
    c = getchar();
  } while ('0' <= c && c <= '9');
  return res;
}
static ll n, m;
static ll s[MAXN], mk[MAXN];
vector<pll> tree[MAXN];
static ll ans = 0;
void dfs(ll u, ll f) {
  for (auto obj : tree[u]) {
    if (obj.first != f) {
      dfs(obj.first, u);
      ans += obj.second * abs(mk[obj.first] - s[obj.first]);
      mk[u] += mk[obj.first];
      s[u] += s[obj.first];
    }
  }
}
int main() {
  static ll i, u, v, w;
  n = read();
  m = read();
  for (i = 1; i <= m; ++i)
    ++s[read()];
  for (i = 1; i <= m; ++i)
    ++mk[read()];
  for (i = 1; i <= n - 1; ++i) {
    u = read(), v = read(), w = readw();
    tree[u].push_back(make_pair(v, w));
    tree[v].push_back(make_pair(u, w));
  }
  dfs(1, 0);
  printf("%lld\n", ans);
  return 0;
}