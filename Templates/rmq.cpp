#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 200010;
ll n, m;
ll st[MAXN][20];
ll logn[MAXN];
ll l, r, s;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> st[i][0];
  }
  logn[1] = 0;
  logn[2] = 1;
  for (int i = 3; i <= n; i++) {
    logn[i] = logn[i / 2] + 1;
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  while (m--) {
    cin >> l >> r;
    s = logn[r - l + 1];
    cout << max(st[l][s], st[r - (1 << s) + 1][s]) << endl;
  }
  return 0;
}
