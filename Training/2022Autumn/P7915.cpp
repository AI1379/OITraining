#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 500010;
ll t;
ll n;
ll a[MAXN];
char ans[MAXN];
void solve() {
  static ll l, r, s, t, beg, end;
  memset(ans, 0, sizeof(ans));
  cin >> n;
  n *= 2;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (a[1] == a[n]) {
    for (int i = 1; i <= n / 2; ++i)
      if (a[i] != a[n - i + 1]) goto noans;
    for (int i = 1; i <= n; ++i) cout << 'L';
    cout << endl;
    return;
  }
  l = 2;
  r = n - 1;
  while (a[l] != a[1]) ++l;
  r = l + 1;
  beg = s = 1;
  end = t = n;
  while (s <= l && r <= t) {
    if (a[s] == a[l] && s != l) {
      ans[beg++] = 'L';
      ans[end--] = 'L';
      ++s, --l;
    } else if (a[s] == a[r] && s != r) {
      ans[beg++] = 'L';
      ans[end--] = 'R';
      ++s, ++r;
    } else if (a[t] == a[l] && t != l) {
      ans[beg++] = 'R';
      ans[end--] = 'L';
      --t, --l;
    } else if (a[t] == a[r] && t != r) {
      ans[beg++] = 'R';
      ans[end--] = 'R';
      --t, ++r;
    } else {
      goto next;
    }
  }
  while (s <= l) {
    if (a[s] != a[l]) goto next;
    ans[beg++] = 'L';
    ans[end--] = 'L';
    ++s, --l;
  }
  while (r <= t) {
    if (a[r] != a[t]) goto next;
    ans[beg++] = 'R';
    ans[end--] = 'R';
    ++r, --t;
  }
  ans[n] = 'L';
  cout << string(ans + 1) << endl;
  return;
next:
  l = 2;
  r = n - 1;
  while (a[r] != a[n]) --r;
  l = r - 1;
  beg = s = 1;
  end = t = n;
  if (a[t] == a[l] && t != l) {
    ans[beg++] = 'R';
    ans[end--] = 'L';
    --t, --l;
  } else if (a[t] == a[r] && t != r) {
    ans[beg++] = 'R';
    ans[end--] = 'R';
    --t, ++r;
  } else {
    goto noans;
  }
  while (s <= l && r <= t) {
    if (a[s] == a[l] && s != l) {
      ans[beg++] = 'L';
      ans[end--] = 'L';
      ++s, --l;
    } else if (a[s] == a[r] && s != r) {
      ans[beg++] = 'L';
      ans[end--] = 'R';
      ++s, ++r;
    } else if (a[t] == a[l] && t != l) {
      ans[beg++] = 'R';
      ans[end--] = 'L';
      --t, --l;
    } else if (a[t] == a[r] && t != r) {
      ans[beg++] = 'R';
      ans[end--] = 'R';
      --t, ++r;
    } else {
      goto noans;
    }
  }
  while (s <= l) {
    if (a[s] != a[l]) goto noans;
    ans[beg++] = 'L';
    ans[end--] = 'L';
    ++s, --l;
  }
  while (r <= t) {
    if (a[r] != a[t]) goto noans;
    ans[beg++] = 'R';
    ans[end--] = 'R';
    ++r, --t;
  }
  ans[n] = 'L';
  cout << string(ans + 1) << endl;
  return;
noans:
  cout << -1 << endl;
  return;
}
int main() {
  cin >> t;
  while (t--) solve();
  return 0;
}