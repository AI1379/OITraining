#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 4000010;
ll n;
ll a;
ll x, y, ans;
int main() {
  ans = y = -0x3fffffffffffffff;
  x = 0x3fffffffffffffff;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    x = min(x, a - i);
    y = max(y, a + i);
    ans = max(ans, a - i - x - 1);
    ans = max(ans, y - a - i - 1);
  }
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}