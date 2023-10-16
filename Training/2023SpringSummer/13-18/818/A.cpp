#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, t, k;
map<string, ll> cnt;
map<string, bool> alive;
string s, v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> t;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    cnt[s] = 0;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> s;
    alive[s] = true;
  }
  for (int i = 1; i <= t; ++i) {
    cin >> k;
    for (int j = 1; j <= k; ++j) {
      cin >> s >> v;
      alive[v] = false;
      ++cnt[s];
    }
    for (auto tmp : cnt) {
      if (tmp.second) {
        cout << tmp.first << ' ' << tmp.second << endl;
        cnt[tmp.first] = 0;
      }
    }
    for (auto tmp : alive) {
      if (tmp.second) {
        cout << tmp.first << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}