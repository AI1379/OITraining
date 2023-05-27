#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, m;
ll a[MAXN];
ll cur[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cur[0] = i;
    for (int j = 1; j <= m; ++j) {
      if (cur[j] == (cur[j - 1] + a[j] - 1) / a[j] * a[j]) break;
      cur[j] = (cur[j - 1] + a[j] - 1) / a[j] * a[j];
    }
    // for (int j = 1; j <= m; ++j) cout << cur[j] << ' ';
    // cout << endl;
    cout << cur[m] << ' ';
  }
  return 0;
}