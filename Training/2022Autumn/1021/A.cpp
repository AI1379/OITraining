#include <bits/stdc++.h>
using namespace std;
string s;
char tolower(char c) {
  if ('A' <= c && c <= 'Z') return 'a' + (c - 'A');
  return c;
}
bool check(int x) {
  return (tolower(s[x]) == 'n' && tolower(s[x + 1]) == 'o' &&
          tolower(s[x + 2]) == 'i' && tolower(s[x + 3]) == 'p');
}
int main() {
  cin >> s;
  for (int i = 0; (unsigned)i < s.length(); ++i) {
    if (check(i)) {
      cout << "CSP";
      i += 3;
      continue;
    }
    cout << s[i];
  }
  return 0;
}