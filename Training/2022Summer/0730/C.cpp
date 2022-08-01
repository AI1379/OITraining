#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
const ll tot = 10000000;
ll n, m;
ll lower, upper;
ll last = 0, base;
ll ans = 1;
int main() {
  cin >> n >> m;
  if (n == m) {
    cout << n + 1 << endl;
    goto quit;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j >= 0; j--) {
      lower = max(0ll, i - (n - m));
      upper = i - j;
      base = (((2 * i - j) * tot) / (2 * n));
      ans += upper - lower + 1;
      if (base + lower <= last)
        ans -= last - (lower + base) + 1;
      last = base + upper;
    }
  }
  cout << ans << endl;
quit:
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}