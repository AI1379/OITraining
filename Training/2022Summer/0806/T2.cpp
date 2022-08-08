#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 100010;
ll n, d;
ll x[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  sort(x + 1, x + n + 1);
  ll tot = 1, last = x[1];
  for (int i = 2; i <= n; i++) {
    if (x[i + 1] - last > d) {
      last = x[i];
      ++tot;
    }
  }
  if (last != x[n])++tot;
  cout << n - tot << endl;
  return 0;
}
