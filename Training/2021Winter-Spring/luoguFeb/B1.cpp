#include <iostream>
using namespace std;
#define ll long long
const ll MAXN = 1010;
ll t;
ll n;
ll a[MAXN], b[MAXN], p[MAXN];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> p[i];
  }
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