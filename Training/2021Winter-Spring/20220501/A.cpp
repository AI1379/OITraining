#include <cmath>
#include <iostream>
#include <stack>

using namespace std;
#define ll long long
const ll MAXN = 1010;
const ll MAXM = 210;
ll n, m;
ll a[MAXN];
ll t[MAXM], x[MAXM], y[MAXM];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  for (int i = m; i >= 1; i--) {
    if (t[i] == 1 && x[i] != y[i]) {
      a[x[i]] = a[x[i]] - a[y[i]];
    } else if (t[i] == 2 && x[i] != y[i]) {
      a[x[i]] = a[x[i]] / a[y[i]];
    } else if (t[i] == 1 && x[i] == y[i]) {
      a[x[i]] /= 2;
    } else if (t[i] == 2 && x[i] == y[i]) {
      a[x[i]] = (ll)(sqrt(a[x[i]]));
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}