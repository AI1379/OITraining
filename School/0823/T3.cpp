#include <bits/stdc++.h>
using namespace std;
#define ll long long
static ll x, y;
static ll ans;
static ll num, s, t, curr, res, ori;
ll calc(ll x) {
  num = 1, curr = 1, res = 0, ori = x;
  while (x * x > ori) {
    s = ori % x;
    t = ori % (ori / curr + 1);
    num = x - ori / curr;
    res += (s + t) * num / 2;
    x = ori / curr;
    ++curr;
  }
  while (x) {
    res += ori % x;
    --x;
  }
  return ori * ori - res;
}
int main() {
  cin >> x >> y;
  ans = calc(y) - calc(x - 1);
  cout << ans << endl;
  return 0;
}