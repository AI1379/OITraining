#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  srand(time(NULL));
  n = 1000;
  m = 1000;
  cout << m << ' ' << n << endl;
  cout << rand() % n + 1 << ' ' << rand() % m + 1 << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << rand() % 1000 + 1 << ' ';
    }
    cout << endl;
  }
  return 0;
}