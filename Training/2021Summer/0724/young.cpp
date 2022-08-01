#include <bits/stdc++.h>
using namespace std;
#define ll long long
int l, n;
int main() {
#ifndef DEBUG
  freopen("young.in", "r", stdin);
  freopen("young.out", "w", stdout);
#endif
  int x;
  cin >> l >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x < 150) {
      cout << "-1" << endl;
      continue;
    }
    x -= 150;
    if (x % (l - 150) != 0) {
      cout << "-1" << endl;
      continue;
    }
    x /= (l - 150);
    if ((x & (x - 1)) != 0) {
      cout << "-1" << endl;
    } else {
      cout << (int)(log2(x)) << endl;
    }
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}