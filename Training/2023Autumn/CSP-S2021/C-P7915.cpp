#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll T;
ll n;
ll val[MAXN];
char ans[MAXN];
bool work(ll l, ll r, ll s, ll t) {
  ll beg = 1, end = n - 2;
  while (l <= r && s <= t) {
    if (val[l] == val[r] && l != r) {
      ans[beg++] = 'L';
      ans[end--] = 'L';
      ++l, --r;
    } else if (val[l] == val[s]) {
      ans[beg++] = 'L';
      ans[end--] = 'R';
      ++l, ++s;
    } else if (val[r] == val[t]) {
      ans[beg++] = 'R';
      ans[end--] = 'L';
      --r, --t;
    } else if (val[s] == val[t] && s != t) {
      ans[beg++] = 'R';
      ans[end--] = 'R';
      ++s, --t;
    } else {
      return false;
    }
  }
  while (l <= r) {
    if (val[l] != val[r]) {
      return false;
    }
    ans[beg++] = 'L';
    ans[end--] = 'L';
    ++l, --r;
  }
  while (s <= t) {
    if (val[s] != val[t]) {
      return false;
    }
    ans[beg++] = 'R';
    ans[end--] = 'R';
    ++s, --t;
  }
  return true;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= 2 * n; ++i) {
    cin >> val[i];
  }
  n *= 2;
  ll x = 0, y = 0;
  for (int i = 1; i <= n; ++i)
    if (val[1] == val[i])
      x = i;
  for (int i = n; i >= 1; --i)
    if (val[n] == val[i])
      y = i;
  if (work(2, x - 1, x + 1, n)) {
    cout << 'L' << (ans + 1) << 'L' << endl;
  } else if (work(1, y - 1, y + 1, n - 1)) {
    cout << 'R' << (ans + 1) << 'L' << endl;
  } else {
    cout << "-1" << endl;
  }
}
int main() {
  cin >> T;
  while (T--)
    solve();
  return 0;
}
/**
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

1
5
3 4 1 5 3 4 2 1 2 5
LLRRLRRLRL

LRRLLRRRRL
-1
**/