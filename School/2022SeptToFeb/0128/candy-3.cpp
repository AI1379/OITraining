#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define pos(i) ((((i)-1) % n + n) % n + 1)
const ll MAXN = 100010;
ll n;
ll a[MAXN];
pll p[MAXN];
ll ans[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i] = make_pair(a[i], i);
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (a[pos(p[i].second - 1)] == a[p[i].second] &&
        a[p[i].second] == a[pos(p[i].second + 1)])
      ans[p[i].second] = 1;
    else if (a[pos(p[i].second - 1)] == a[p[i].second])
      ans[p[i].second] = ans[pos(p[i].second + 1)] + 1;
    else if (a[pos(p[i].second + 1)] == a[p[i].second])
      ans[p[i].second] = ans[pos(p[i].second - 1)] + 1;
    else
      ans[p[i].second] =
          max(ans[pos(p[i].second - 1)], ans[pos(p[i].second + 1)]) + 1;
  }
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += ans[i];
  }
  cout << sum << endl;
  return 0;
}