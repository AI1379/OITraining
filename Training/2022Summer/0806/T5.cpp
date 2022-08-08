#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr const ll MAXN = 2000010;
ll t, n;
ll g[MAXN], phi[MAXN];
bool isNotPrime[MAXN];
ll pre[MAXN], prime[MAXN], tot = 0;
constexpr void init() {
  isNotPrime[1] = true;
  g[1] = 1;
  phi[1] = 1;
  for (ll i = 2; i < MAXN; i++) {
    if (!isNotPrime[i]) {
      g[i] = i * 2 - 1;
      phi[i] = i - 1;
      prime[++tot] = i;
    }
    for (ll j = 1; j <= tot && i * prime[j] < MAXN; j++) {
      isNotPrime[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        g[i * prime[j]] = g[i] * prime[j] + i - prime[j];
        break;
      } else {
        phi[i * prime[j]] = phi[i] * phi[prime[j]];
        g[i * prime[j]] = g[i] * g[prime[j]];
      }
    }
  }
  for (ll i = 1; i < MAXN; i++) {
    pre[i] = pre[i - 1] + g[i];
  }
}
int main() {
  init();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n;
    cout << (pre[n] * 2 - n * (n + 1) / 2) << endl;
    for (int i = 1; i <= n; i++) {
      cout << g[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
