#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
int main() {
  ll u, cur, ans, pre;
  cin >> t;
  while (t--) {
    cur = pre = 1;
    ans = 0;
    cin >> u;
    for (int k = 1000; k > 0; k /= 10) {
      cur = (u / k % 10 == 0 ? 10 : u / k % 10);
      ans += abs(cur - pre) + 1;
      pre = cur;
    }
    cout << ans << endl;
  }
  return 0;
}