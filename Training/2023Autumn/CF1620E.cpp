#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 500010;
ll val[MAXN];
ll cur[MAXN], lst[MAXN];
ll q;
ll opt[MAXN];
pll obj[MAXN];
ll cnt = 0;
int main() {
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> opt[i];
    if (opt[i] == 1) {
      ++cnt;
      cin >> obj[i].first;
      cur[obj[i].first] = obj[i].first;
    } else {
      cin >> obj[i].first >> obj[i].second;
      cur[obj[i].first] = obj[i].first;
      cur[obj[i].second] = obj[i].second;
    }
  }
  for (int i = q, j = cnt; i >= 1; --i) {
    if (opt[i] == 1) {
      val[j--] = cur[obj[i].first];
    } else {
      cur[obj[i].first] = cur[obj[i].second];
    }
  }
  for (int i = 1; i <= cnt; ++i) {
    cout << val[i] << ' ';
  }
  cout << endl;
  return 0;
}