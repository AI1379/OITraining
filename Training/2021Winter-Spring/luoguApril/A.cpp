#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, t;
void solve() {
  ll now = 0, s, idx = 0, x, lst = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    if (s != -1) {
      x = (s - now) / (idx + 1);
      for (int j = 1; j <= idx; j++) {
        cout << x << ' ';
      }
      cout << (s - idx * x - now) << ' ';
      now = s;
      idx = 0;
      lst = i;
    } else {
      idx++;
    }
  }
  for (lst++; lst <= n; lst++)
    cout << "1 ";
  cout << endl;
}
int main() {
  cin >> t;
  while (t--)
    solve();
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}