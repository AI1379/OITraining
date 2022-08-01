#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10000010;
const ll MOD = 1e9 + 7;
bool is_prime[MAXN];
ll n, m;
ll prime[MAXN], phi[MAXN];
void init() {
  memset(is_prime, true, sizeof(is_prime));
  int cnt = 0;
  is_prime[1] = false;
  phi[1] = 1;
  for (int i = 2; i <= max(n, m); i++) {
    if (is_prime[i]) {
      prime[++cnt] = i;
      phi[i] = (i - 1) % MOD;
    }
    for (int j = 1; j <= cnt && i * prime[j] <= max(n, m); j++) {
      is_prime[i * prime[j]] = false;
      if (i % prime[j])
        phi[i * prime[j]] = phi[i] * phi[prime[j]] % MOD;
      else {
        phi[i * prime[j]] = phi[i] * prime[j] % MOD;
        break;
      }
    }
  }
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll ans = 0;
int main() {
  cin >> n >> m;
  init();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans = (ans + phi[gcd(i, j)]) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}