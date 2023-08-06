#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, q;
vector<ll> a;
int main() {
  ll v;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> v;
      a.emplace_back(v);
    }
  }
  sort(a.begin(), a.end());
  while (q--) {
    cin >> v;
    cout << min(n, (ll)(a.end() - lower_bound(a.begin(), a.end(), v))) << endl;
  }
  return 0;
}