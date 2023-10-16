#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 127;
ll t;
ll n, m;
array<ll, MAXN> mat[MAXN];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mat[i][j];
    }
  }
  sort(mat + 1, mat + n + 1,
       [](const array<ll, MAXN> &lhs, const array<ll, MAXN> &rhs) {
         for (int i = 1; i <= m; ++i) {
           if (lhs[i] != rhs[i])
             return lhs[i] < rhs[i];
         }
         return true;
       });
  for (int i = m; i >= 1; --i) {
    for (int j = 2; j <= n; ++j) {
      if (mat[j][i] < mat[j - 1][i]) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}