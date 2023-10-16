#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mp[10000][20];
int lg[10000];
int n, m;
int main() {
  n = 10;
  for (int i = 1; i <= n; ++i) {
    lg[i] = log2(i);
  }
  for (int i = 1; i <= n; ++i) {
    mp[i][0] = n - i + 1;
  }
  for (int k = 1; k <= 20; ++k) {
    for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
      mp[i][k] = max(mp[i][k - 1], mp[i + (1 << (k - 1))][k - 1]);
    }
  }
  int l, r;
  cin >> l >> r;
  cout << max(mp[l][lg[r - l + 1]],
              mp[r - (1 << (lg[r - l + 1])) + 1][lg[r - l + 1]])
       << endl;

  return 0;
}