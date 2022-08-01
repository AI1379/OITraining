#include <bits/stdc++.h>
using namespace std;
#define ll long long
string str;
ll ans = 0;
int n = 0;
int seq[2000010];
ll calc(int l, int r) {
  ll res = 0, cnt = 0;
  for (int i = r; i >= l; i--) {
    if (seq[i] == 1) {
      cnt++;
      res += (r - cnt + 1 - i);
    }
  }
  return res;
}
int main() {
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'A') {
      seq[++n] = 1;
    } else if (str[i] == 'B' && str[i + 1] == 'C') {
      seq[++n] = 2;
      i++;
    } else {
      seq[++n] = 0;
    }
  }
#ifdef DEBUG
  for (int i = 1; i <= n; i++) {
    cout << seq[i];
  }
  cout << endl;
#endif
  int pre;
  for (int i = 1; i <= n; i++) {
    if (!seq[i]) continue;
    if (!seq[i - 1])
      pre = i;
    else if (!seq[i + 1])
      ans += calc(pre, i);
  }
  cout << ans << endl;
#ifdef DEBUG
  system("pause");
#endif
  return 0;
}