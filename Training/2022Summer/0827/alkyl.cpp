#include <iostream>
#define ll long long
using namespace std;
const ll MAXN = 50;
ll n, f[MAXN];
ll dfs(ll x) {
  if (!x)
    return 1;
  if (f[x])
    return f[x];
  for (ll i = 0; i <= x - 1; i++)
    for (ll j = i; i + j <= x - 1; j++) {
      ll k = x - 1 - i - j;
      if (k < j)
        continue;
      if (i == k)
        f[x] = (f[x] + dfs(i) * (dfs(i) + 1) * (dfs(i) + 2) / 6);
      else if (i == j)
        f[x] = (f[x] + dfs(i) * (dfs(i) + 1) * dfs(k) / 2);
      else if (j == k)
        f[x] = (f[x] + dfs(j) * (dfs(j) + 1) * dfs(i) / 2);
      else
        f[x] = (f[x] + dfs(i) * dfs(j) * dfs(k));
    }
  return f[x];
}
int main() {
  cin >> n;
  f[0] = 1;
  cout << dfs(n);
  return 0;
}