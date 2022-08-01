#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int n, a;
bool win;
void solve() {
  win = false;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    win = win && (a != 1);
  }
  cout << (win ? "rabbit" : "hamster") << endl;
  return;
}
int main() {
  cin >> t;
  while (t--) solve();
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}