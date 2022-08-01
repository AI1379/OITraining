#include <bits/stdc++.h>
using namespace std;
int m, n;
long long f[50][50];
int main() {
  cin >> m >> n;
  for (int i = m; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      f[i][j] = f[i + 1][j] + f[i][j + 1] + 1;
    }
  }
  cout << f[1][1] + 1 << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}