#include <bits/stdc++.h>
using namespace std;
int q;
int n, m;
string a, b;
int l1, r1, l2, r2;
int main() {
  cin >> n >> m;
  cin >> a >> b;
  cin >> q;
  while (q--) {
    cin >> l1 >> r1 >> l2 >> r2;
    bool ans = 0;
    for (int i = 0; i <= r1 - l1; i++) {
      if (a[i + l1 - 1] != b[i + l2 - 1]) {
        ans = (!ans);
      }
    }
    cout << (ans ? 1 : 0) << endl;
  }
#ifdef DEBUG
  system("pause");
#endif
}