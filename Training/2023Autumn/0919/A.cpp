#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
vector<ll> pos;
int main() {
#ifndef DEBUG
  freopen("find.in", "r", stdin);
  freopen("find.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin >> s;
  for (unsigned i = 0; i < s.length() - 1; ++i) {
    if (tolower(s[i]) == 'g' && tolower(s[i + 1]) == 'g') {
      ++i;
      pos.emplace_back(i);
    }
  }
  cout << pos.size() << endl;
  for (auto &x : pos)
    cout << x << ' ';
  cout << endl;
  return 0;
}