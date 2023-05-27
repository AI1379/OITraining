#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll t;
int main() {
  ll x1, y1, x2, y2, x3, y3, r;
  ll l1sq, l2sq;
  ll a, b, c;
  ld ans1, ans2;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3, &r);
    l1sq = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
    l2sq = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
    a = y2 - y1;
    b = x1 - x2;
    c = y1 * (x2 - x1) - x1 * (y2 - y1);
    ans1 = sqrt(max(l1sq, l2sq)) + r;
    ans2 = (ld)(abs(a * x3 + b * y3 + c)) / sqrt(abs(a * a + b * b)) - r;
    printf("%.2Lf %.2Lf\n", ans2, ans1);
  }
  return 0;
}