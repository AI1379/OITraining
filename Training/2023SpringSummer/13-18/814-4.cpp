#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 400010;
ll n;
ll h[MAXN], w[MAXN];
ll r[MAXN], l[MAXN];
deque<ll> dq;
int main() {
  ll cur = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
    cur += w[i];
  }
  for (int i = 1; i <= n; ++i) {
    l[i] = 0;
    r[i] = cur;
  }
  for (int i = n; i >= 0; --i) {
    while (!dq.empty() && h[dq.back()] > h[i]) {
      l[dq.back()] = cur;
      dq.pop_back();
    }
    cur -= w[i];
    dq.emplace_back(i);
  }
  dq.clear();
  for (int i = 1; i <= n; ++i) {
    while (!dq.empty() && h[dq.back()] > h[i]) {
      r[dq.back()] = cur;
      dq.pop_back();
    }
    cur += w[i];
    dq.emplace_back(i);
  }
  cur = 0;
  for (int i = 1; i <= n; ++i) {
    cur = max(cur, h[i] * (r[i] - l[i]));
  }
  cout << cur << endl;
  return 0;
}