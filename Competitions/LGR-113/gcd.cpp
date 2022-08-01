#include <iostream>
using namespace std;
#define ll long long
ll t, l, r, x;
int main() {
  cin >> t;
  while (t--) {
    cin >> l >> r >> x;
    if (l / x == r / x) {
      cout << l / x << endl;
    } else {
      cout << 1 << endl;
    }
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}