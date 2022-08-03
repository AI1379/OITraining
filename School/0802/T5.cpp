#include <iostream>
using namespace std;
#define ll long long
const ll MOD = 10007;
const ll INV6 = 1668;
ll n;
ll a, b, c;
int main() {
  cin >> n;
  if (n % 2 == 0) {
    a = (n / 2 - 1) * (n / 2) % MOD * (n / 2 + 1) % MOD * INV6 % MOD;
    b = (n / 2) * (n / 2 + 1) % MOD * (n / 2 + 2) % MOD;
    c = (n / 2 + 1) * (n / 2 + 2) % MOD * (n / 2 + 3) % MOD * INV6 % MOD;
    a = (a + b + c) % MOD;
    b = (b + c) % MOD;
    for (int i = 1; i <= n / 2; i++) {
      if (i <= (n / 2 - 2)) {
        cout << a << endl;
      } else if (i == (n / 2 - 1)) {
        cout << b << endl;
      } else {
        cout << c << endl;
      }
    }
  } else {
    b = ((n - 3) / 2 + 1) * ((n - 3) / 2 + 2) % MOD * ((n - 3) / 2 + 3) % MOD *
        INV6 % MOD * 4 % MOD;
    c = ((n - 1) / 2 + 1) * ((n - 1) / 2 + 2) % MOD * ((n - 1) / 2 + 3) % MOD *
        INV6 % MOD * 4 % MOD;
    b = (b + c) % MOD;
    for (int i = 1; i <= n / 2; i++) {
      if (i <= ((n - 3) / 2)) {
        cout << b << endl;
      } else {
        cout << c << endl;
      }
    }
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}