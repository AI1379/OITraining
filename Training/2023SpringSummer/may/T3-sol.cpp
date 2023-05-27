#include <bits/stdc++.h>
using namespace std;
long long n;
long long h[310];
long long ans, p, q;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  sort(h, h + n + 1);
  q = 0;
  p = n;
  while (q < p) {
    ans += (h[q] - h[p]) * (h[q] - h[p]);
    q++;
    ans += (h[q] - h[p]) * (h[q] - h[p]);
    p--;
  }
  cout << ans << endl;
  return 0;
}