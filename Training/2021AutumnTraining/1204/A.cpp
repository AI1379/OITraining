#include <bits/stdc++.h>
using namespace std;
int n;
long double ans = 0.00;
int main() {
  int a, b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    ans = ans + a * (long double)(b) / 10.00;
  }
  cout << fixed << setprecision(2) << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}