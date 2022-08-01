#include <bits/stdc++.h>
using namespace std;
int t;
int n;
map<pair<int, int>, int> mp;
void solve() {
  mp = map<pair<int, int>, int>();
  stringstream ss;
  string str;
  int x, y, gcd;
  while (getline(cin, str)) {
    if (str.length() == 0) break;
    ss.clear();
    ss.str(str);
    ss >> x >> y;
    gcd = __gcd(x, y);
    x = x / gcd;
    y = y / gcd;
    if (x > y) swap(x, y);
    mp[make_pair(x, y)]++;
  }
  int ans = 0;
  for (auto x : mp) {
    ans = max(ans, x.second);
  }
  cout << ans << endl;
  return;
}
int main() {
  cin >> t;
  string s;
  getline(cin, s);
  while (t--) solve();
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}