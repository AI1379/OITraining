#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, x, opt, tmp;
int main() {
  cin >> t;
  while (t--) {
    cin >> opt >> n >> x;
    if (x < n - 1) {
      cout << -1 << endl;
    } else if (opt == 1) {
      tmp = x - n + 2;
      cout << tmp << ' ';
      for (int i = 0; i < n - 1; ++i) {
        cout << tmp + i << ' ';
      }
      cout << endl;
    } else {
      tmp = x - n + 2;
      cout << tmp << ' ';
      for (int i = 0; i < n - 1; ++i) {
        cout << 1 << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
/**
5
1 5 4
2 3 8
1 5 10
2 6 34
1 3 1
**/