#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
stringstream ss;
string s;
ll coef, powe[26], ans[26];
ll lcm;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
#ifndef DEBUG
  freopen("least.in", "r", stdin);
  freopen("least.out", "w", stdout);
#endif
  ll idx = 0, k = -1;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    coef = idx = 0;
    lcm = 1;
    k = -1;
    while ('0' <= s[idx] && s[idx] <= '9') {
      coef = coef * 10 + s[idx] - '0';
      ++idx;
    }
    if (coef == 0) coef = 1;
    while (idx < (ll)s.size()) {
      if ('a' <= s[idx] && s[idx] <= 'z') {
        if (k != -1 && powe[k] == 0) {
          powe[k] = 1;
        }
        k = s[idx] - 'a';
      } else if ('0' <= s[idx] && s[idx] <= '9') {
        powe[k] = powe[k] * 10 + s[idx] - '0';
      }
      ++idx;
    }
    if (k != -1 && powe[k] == 0) powe[k] = 1;
    lcm = lcm * coef / gcd(max(lcm, coef), min(lcm, coef));
    for (int i = 0; i < 26; ++i) {
      ans[i] = max(ans[i], powe[i]);
      powe[i] = 0;
    }
  }
  cout << lcm;
  for (int i = 0; i < 26; ++i) {
    if (ans[i] != 0) {
      cout << (char)('a' + i) << ans[i];
    }
  }
  cout << endl;
  return 0;
}