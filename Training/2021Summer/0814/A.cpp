#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  getline(cin, str);
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ')
      cout << '#';
    else if (str[i] == '.')
      continue;
    else
      cout << (int)(str[i]) - (int)('a') + 1;
  }
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}