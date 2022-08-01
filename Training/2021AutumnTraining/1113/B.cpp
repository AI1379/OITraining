#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, maxx, minx, ans;
int main() {
  cin >> n >> minx >> maxx;
  if (n == 1 && minx != maxx)
    cout << 0 << endl;
  else
    cout << (n - 2) * (maxx - minx) + 1 << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}