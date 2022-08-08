#include<bits/stdc++.h>
using namespace std;
int main() {
  string s, ans;
  unsigned int b, e, i, j;
  cin >> s;
  cin >> b >> e;
  for (j = s.length() - b; j < s.length(); j++) {
    ans.push_back(s[j]);
  }
  for (i = e; i < s.length() - b; i++) {
    ans.push_back(s[i]);
  }
  for (i = 0; i < e; i++) {
    ans.push_back(s[i]);
  }
  long long tmp = 0;
  vector<long long> vec;
  for (i = 0; i < ans.length(); i++) {
    if ('0' <= ans[i] && ans[i] <= '9') {
      tmp = tmp * 10 + ans[i] - '0';
      if (i == s.length() - 1 || !('0' <= ans[i + 1] && ans[i + 1] <= '9')) {
        vec.push_back(tmp);
        tmp = 0;
      }
    }
  }
  stringstream ss;
  int now = 0;
  for (i = 0; i < ans.length(); i++) {
    if (!('0' <= ans[i] && ans[i] <= '9')) {
      ss << ans[i];
    } else {
      ss << (vec[now++] / 2);
      while (i + 1 < ans.length() && '0' <= ans[i + 1] && ans[i + 1] <= '9') {
        i++;
      }
    }
  }
  cout << (ss.str()) << endl;
  return 0;
}
