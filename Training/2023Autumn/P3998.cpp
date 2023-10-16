#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 200010;
const ll MAXM = 500010;
ll n, m;
char opt[MAXM];
pll obj[MAXM];
ll beg[MAXN], cur[MAXN], ans[MAXN];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> opt[i];
    if (opt[i] == '!')
      cin >> obj[i].first;
    else
      cin >> obj[i].first >> obj[i].second;
  }
  for (int i = m; i >= 1; --i) {
    if (opt[i] == '!') {
      ++cur[obj[i].first];
    } else if (opt[i] == '+') {
      ans[obj[i].first] += cur[obj[i].second];
      ans[obj[i].second] += cur[obj[i].first];
    } else {
      ans[obj[i].first] -= cur[obj[i].second];
      ans[obj[i].second] -= cur[obj[i].first];
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}