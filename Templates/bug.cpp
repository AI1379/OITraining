#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  int n;
  while (tt--) {
    char a[4];
    int b[4];
    for (int i = 1; i <= 4; i++) {
      cin >> a[i];
      if (a[i] == '0')
        b[i] = 10;
      else
        b[i] = a[i] - '0';
    }
    int pos = 1;
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
      // if(pos==10) pos=0;
      ans += abs(b[i] - pos) + 1;
      pos = b[i];
    }
    // cout<<tt<<endl;
    cout << ans << endl;
  }
}
/**
10
1111
1236
1010
1920
9273
0000
7492
8543
0294
8361

4
9
31
27
28
13
25
16
33
24

**/