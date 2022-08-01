#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i = 1; i <= 1000000000; i++) {
    for (int j = 1; j <= 1000000000; j++) {
      for (int k = 1; k <= 1000000000; k++) {
        if ((-i + j - k) == (i ^ j ^ k)) {
          cout << i << ' ' << j << ' ' << k << endl;
          cout << (-i + j - k) << ' ' << (i ^ j ^ k) << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}