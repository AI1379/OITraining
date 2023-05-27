#include <iostream>
#include <queue>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define pos(i) ((((i)-1) % n + n) % n + 1)
const ll MAXN = 100010;
ll n;
ll a[MAXN];
ll ans[MAXN];
ll sum = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  queue<pll> q;
  for (int i = 1; i <= n; ++i) {
    if (a[pos(i - 1)] >= a[i] && a[i] <= a[pos(i + 1)]) {
      q.emplace(i, 1);
    }
  }
  while (!q.empty()) {
    auto [p, v] = q.front();
    q.pop();
    ans[p] = v;
    if (a[pos(p - 1)] > a[p]) {
      if (a[pos(p - 2)] >= a[pos(p - 1)] || ans[pos(p - 2)]) {
        if (ans[pos(p - 1)] == 0) {
          q.emplace(pos(p - 1), v + 1);
        }
      }
    }
    if (a[pos(p + 1)] > a[p]) {
      if (a[pos(p + 2)] >= a[pos(p + 1)] || ans[pos(p + 2)]) {
        if (ans[pos(p + 1)] == 0) {
          q.emplace(pos(p + 1), v + 1);
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    sum += ans[i];
  cout << sum << endl;
  return 0;
}