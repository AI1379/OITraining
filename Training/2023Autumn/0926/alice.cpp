#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll tab[] = {100, 50, 20, 10, 5, 1};
ll n;
ll ans[6];
int main() {
#ifndef DEBUG
  freopen("alice.in", "r", stdin);
  freopen("alice.out", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < 6; ++i) {
    ans[i] = (n / tab[i]);
    n = n % tab[i];
  }
  for (int i = 5; i >= 0; --i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}