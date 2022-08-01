#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
string s;
ll tab[26];
ll ans = 0;
int main() {
  cin >> n >> s;
  for (auto c : s) tab[c - 'A']++;
  sort(tab, tab + 26);
  for (int i = 0; i < 26; i++) {
    if (tab[i] > n) break;
    n -= tab[i];
    ans++;
  }
  cout << (26 - ans) << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}