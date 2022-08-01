#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mp[26];
string str;
int n;
int main() {
#ifndef DEBUG
  freopen("speech.in", "r", stdin);
  freopen("speech.out", "w", stdout);
#endif
  char x;
  ll y;
  cin >> str;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    mp[x - 'A'] = y;
  }
  for (int i = 0; i < str.size(); i++) {
    cout << mp[str[i] - 'A'];
  }
  cout << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}