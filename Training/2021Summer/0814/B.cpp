#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string str;
  cin >> n >> str;
  if (str[0] == str[1] || str[0] == str[2] || str[1] == str[2]) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 3; i < str.length(); i++) {
    if (str[i] != str[i % 3]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}