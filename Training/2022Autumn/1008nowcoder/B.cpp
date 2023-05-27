#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200010;
const ll INF = (1ll << (sizeof(ll) * 8 - 2));
ll t;
ll n;
ll a[MAXN];
bool vis[MAXN];
ll mex, mina, minp, rem;
void solve() {
  memset(a, 0, sizeof(a));
  memset(vis, false, sizeof(vis));
  bool flag = false;
  mina = INF;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    vis[a[i]] = true;
    flag |= (a[i] != 0);
    if (a[i] != 0 && mina > a[i]) {
      minp = i;
      mina = a[i];
    }
  }
  if (!flag) {
    for (int i = 1; i <= n - 1; ++i) cout << i << ' ';
    cout << endl;
    return;
  }
  if (a[1] == 0) {
    rem = minp;
    vis[mina] = false;
    goto output;
  }
  mex = 1;
  while (vis[mex]) ++mex;
  int i;
  for (i = 1; i <= n; ++i) {
    if (a[i + 1] == 0) break;
    if (a[i] > a[i + 1]) {
      rem = i;
      vis[a[i]] = false;
      goto output;
    }
  }
  mina = 0;
  for (i = 1; a[i] != 0; ++i) {
    if (a[i] > mina) {
      mina = a[i];
      minp = i;
    }
  }
  if (mina > mex) {
    rem = minp;
    vis[mina] = false;
    goto output;
  }
  mina = INF;
  for (; i <= n; ++i) {
    if (a[i] < mina && a[i] != 0) {
      mina = a[i];
      minp = i;
    }
  }
  if (mina < mex) {
    rem = minp;
    vis[mina] = false;
    goto output;
  }
  rem = i;
output:
  for (int i = 1, j = 1; i <= n; ++i) {
    if (i == rem) continue;
    if (a[i] == 0) {
      while (vis[j]) ++j;
      cout << j << ' ';
      vis[j] = true;
    } else {
      cout << a[i] << ' ';
    }
  }
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}