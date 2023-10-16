#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll tab[] = {0, 15, 20, 25, 30, 35, 40, 45, 50};
ll n;
int main() {
#ifndef DEBUG
  freopen("star.in", "r", stdin);
  freopen("star.out", "w", stdout);
#endif
  cin >> n;
  if (n <= 8) {
    cout << tab[n] << endl;
  } else {
    cout << (50 + 10 * (n - 8)) << endl;
  }
  return 0;
}