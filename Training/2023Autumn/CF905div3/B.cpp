#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
string s;
ll cnt[26];
void solve() {
  cin >> n >> k >> s;
  if (k >= (ll)s.length()) {
    cout << "NO" << endl;
    return;
  }
  for (int i = 0; i < 26; ++i)
    cnt[i] = 0;
  for (auto c : s) {
    ++cnt[c - 'a'];
  }
  ll odd = 0;
  for (int i = 0; i < 26; ++i) {
    odd += cnt[i] % 2;
  }
  if (odd > k + 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
ll t;
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
/**
14
1 0
a
2 0
ab
2 1
ba
3 1
abb
3 2
abc
6 2
bacacd
6 2
fagbza
6 2
zwaafa
7 2
taagaak
14 3
ttrraakkttoorr
5 3
debdb
5 4
ecadc
5 3
debca
5 3
abaac
YES
NO
YES
YES
YES
YES
NO
NO
YES
YES
YES
YES
NO
YES
**/