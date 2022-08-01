#include <iostream>
using namespace std;
#define ll long long
ll n;
ll a, b, c;
int main() {
  cin >> n >> a >> b >> c;
  if (c < n) {
    cout << n * 2 - 1 << endl;
  } else {
    cout << min(n * 2 + b - a, 2 * c + 1) << endl;
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}