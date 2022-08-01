#include <iostream>
using namespace std;
#define ll long long
ll s, t;
int main() {
  ll a, b;
  cin >> s >> t;
  while (t--) {
    cin >> a >> b;
    cout << ((a * b) - (((a + 1) / 2) * ((b + 1) / 2))) << " 10.000" << endl;
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}