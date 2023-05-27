#include <iostream>
#include <string>
using namespace std;
int main() {
  int t;
  string a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a.length() % b.length() != 0)
      goto no;
    for (int i = 0; i < a.length(); ++i)
      if (a[i] != b[i % b.length()])
        goto no;
    cout << "YES" << endl;
    continue;
  no:
    cout << "NO" << endl;
  }
  return 0;
}