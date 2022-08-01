// https://www.luogu.com.cn/problem/P8177
#include <iostream>
using namespace std;
#define ll long long
ll n, a, d;
ll t;
void solve() {
  cin >> n >> a >> d;
  ll x = 1;
  while (d % 2 == 0 && d > 0) {
    x <<= 1;
    d >>= 1;
  }
  cout << (x - 1) * (n - 1) << endl;
  return;
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