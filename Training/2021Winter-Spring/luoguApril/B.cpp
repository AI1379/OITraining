#include <cstring>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 100010;
ll t, n;
ll p[MAXN], s[MAXN];
void solve() {
  ll x = -1;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  if (p[n] != -1)
    x = p[n];
  if (s[1] != -1)
    x = s[1];
  if (x == -1) {
    for (int i = 1; i <= n - 1; i++) {
      if (p[i] != -1 && s[i + 1] != -1) {
        x = p[i] ^ s[i + 1];
      }
    }
  }
  p[n] = x;
  for (int i = 1; i <= n - 1; i++) {
    if (s[i + 1] != -1)
      p[i] = x ^ s[i + 1];
  }
  ll now = 0;
  for (int i = 1; i <= n; i++) {
    if (p[i] == -1) {
      cout << "0 ";
    } else {
      cout << (p[i] ^ now) << ' ';
      now = p[i];
    }
  }
}
int main() {
  cin >> t;
  while (t--)
    solve();
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}