#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 5010;
const ll MOD = 998244353;
ll n;
ll a[MAXN], b[MAXN];
ll pi[MAXN];
void exgcd(ll b, ll p, ll &a, ll &k) {
  if (p == 0) {
    a = 1;
    k = 0;
    return;
  }
  exgcd(p, b % p, k, a);
  k -= b / p * a;
  return;
}
ll inv(ll b, ll p) {
  ll a, k;
  exgcd(b, p, a, k);
  if (a < 0)
    a += p;
  return a;
}
ll fact = 1, f, ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    pi[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    fact = fact * i % MOD;
  }
  fact = inv(fact, MOD);
  do {
    f = 1;
    for (int i = 1; i <= n; i++) {
      f = f * min(a[i], b[pi[i]]) % MOD;
    }
    ans = (ans + f) % MOD;
  } while (next_permutation(pi + 1, pi + n + 1));
  ans = ans * fact % MOD;
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}