#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXSQRTN = 100010;
ll m, n;
ll k;
ll x, y, mid, ans;
int main() {
  cin >> m >> n;
  k = m * n;
  x = 1;
  y = sqrt(k);
  while (k % y != 0)
    --y;
  cout << abs(k / y - y) << endl;
  return 0;
}