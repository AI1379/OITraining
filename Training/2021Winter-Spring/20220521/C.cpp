#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 127;
ll n;
ll a[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (a[1] != -1 && a[1] != 0) {
    cout << -1 << endl;
#ifdef VSCODE
    system("pause");
#endif
    return 0;
  }
  a[1] = 0;
  a[n + 1] = -1;
  for (int i = n; i >= 1; i--) {
    if (a[i + 1] != -1) {
      if (a[i] != a[i + 1] - 1 && a[i] != -1 && a[i + 1] != 0) {
        cout << -1 << endl;
#ifdef VSCODE
        system("pause");
#endif
        return 0;
      }
      if (a[i + 1] != 0)
        a[i] = a[i + 1] - 1;
    }
  }
  ll x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0)
      x++;
    if (a[i] == -1)
      y++;
  }
  cout << x << ' ' << x + y << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}