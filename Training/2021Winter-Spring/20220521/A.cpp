#include <iostream>
using namespace std;
#define ll long long
ll a, b, x, y;
ll ans;
int main() {
  cin >> a >> b >> x >> y;
  ans = abs(a - b);
  ans = min(ans, abs(a - x) + abs(b - y));
  ans = min(ans, abs(a - y) + abs(b - x));
  cout << ans << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}