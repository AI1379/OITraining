#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i++) {
      cout << 1 << ' ';
    }
    cout << endl;
    return 0;
  } else {
    for (int i = 1; i <= n - 3; i++) {
      cout << 1 << ' ';
    }
    cout << 1 << ' ' << 3 << ' ' << 2 << endl;
    return 0;
  }
  return 0;
}