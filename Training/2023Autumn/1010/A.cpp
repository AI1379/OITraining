#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 300010;
ll n;
ll ans = 0, sum = 0;
int main() {
  ll u, v;
  cin >> n;
  ans = n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; ++i) {
    cin >> u >> v;
    sum += u * v;
  }
  ans = ans - sum / 2;
  cout << ans << endl;
  return 0;
}