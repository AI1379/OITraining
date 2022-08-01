#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 510;
ll t;
ll n;
ll diff[MAXN];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "? 1 " << i << endl;
    cin >> diff[i];
  }
  return;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}