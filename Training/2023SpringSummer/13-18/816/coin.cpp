#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, t;
const ll mp[] = {1, 1, 4, 5, 1, 4};
map<ll, ll> m;
void dfs(ll cur, ll pos, ll state) {
  if (pos == 6) {
    if (cur < 0)
      return;
    if (!m[cur])
      m[cur] = state;
    else
      m[cur] = min(m[cur], state);
    return;
  }
  dfs((cur + mp[pos]), pos + 1, (state << 1));
  dfs((cur - mp[pos]), pos + 1, (state << 1) | 1);
}
int main() {
#ifndef DEBUG
  freopen("coin.in", "r", stdin);
  freopen("coin.out", "w", stdout);
#endif
  cin >> t;
  dfs(0, 0, 0);
  while (t--) {
    cin >> n;
    if (m[n % 16] == 0 && n % 16 != 0) {
      cout << -1 << endl;
    } else {
      if (n % 16 == 0) {
        for (int i = 1; i < n / 16; ++i) {
          cout << "1+1+4+5+1+4+";
        }
        cout << "1+1+4+5+1+4" << endl;
        continue;
      } else {
        for (int i = 1; i < n / 16; ++i) {
          cout << "1+1+4+5+1+4+";
        }
        if (n > 16)
          cout << "1+1+4+5+1+4";
        for (int i = 5; i >= 0; --i) {
          if (!(i == 5 && n < 16)) {
            if ((m[n % 16] >> i) & 1)
              cout << '-';
            else
              cout << '+';
          }
          cout << mp[5 - i];
        }
        cout << endl;
      }
    }
  }
  return 0;
}