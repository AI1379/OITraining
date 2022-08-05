#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define ll long long
ll count[26];
int main() {
#ifndef DEBUG
  freopen("herdle.in", "r", stdin);
  freopen("herdle.out", "w", stdout);
#endif
  string a, b, c, ans, guess;
  stringstream ssans, ssguess;
  cin >> a >> b >> c;
  ssans << a << b << c;
  cin >> a >> b >> c;
  ssguess << a << b << c;
  ans = ssans.str();
  guess = ssguess.str();
  for (auto ch : ans) {
    ++count[ch - 'A'];
  }
  ll res1 = 0, res2 = 0;
  for (int i = 0; i < 9; i++) {
    if (ans[i] == guess[i]) {
      --count[ans[i] - 'A'];
      ++res1;
    }
  }
  for (int i = 0; i < 9; i++) {
    if (ans[i] == guess[i]) {
      continue;
    }
    if (count[guess[i] - 'A']) {
      --count[guess[i] - 'A'];
      ++res2;
    }
  }
  cout << res1 << endl << res2 << endl;
  return 0;
}
