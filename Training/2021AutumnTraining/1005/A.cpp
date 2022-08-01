#include <bits/stdc++.h>
using namespace std;
int n;
string str[200010];
int num[200010];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> str[i];
  for (int i = 1; i <= n; i++) cin >> num[i];
  sort(str + 1, str + n + 1);
  sort(num + 1, num + n + 1);
  for (int i = 1; i <= n; i++) cout << str[i] << ' ' << num[i] << endl;
  return 0;
}