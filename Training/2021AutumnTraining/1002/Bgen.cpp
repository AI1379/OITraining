#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("B.in", "w", stdout);
  srand(time(NULL));
  cout << rand() % 45000 + 1 << '\n';
  int h = 45000;
  // int h = rand() % 45000 + 1;
  cout << h << '\n';
  for (int i = 1; i <= h; i++) {
    cout << rand() << ' ' << rand() << '\n';
  }
  return 0;
}