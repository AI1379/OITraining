#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10000100;
ll t, n;
bool vis[MAXN];
vector<ll> pri;
void init(int m) {
  pri.reserve(log(m));
  for (ll i = 2; i <= m; ++i) {
    if (!vis[i]) {
      pri.emplace_back(i);
    }
    for (ll &j : pri) {
      if (i * j > m)
        break;
      vis[i * j] = true;
      if (i % j == 0)
        break;
    }
  }
}
int main() {
  ll x, p;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  init(10000050);
  while (t--) {
    cin >> x;
    if (x == 2) {
      cout << 2 << '\n';
      continue;
    }
    p = lower_bound(pri.begin(), pri.end(), x) - pri.begin() - 1;
    if (x - pri[p] >= pri[p + 1] - x)
      cout << pri[p + 1] << '\n';
    else
      cout << pri[p] << '\n';
  }
  return 0;
}