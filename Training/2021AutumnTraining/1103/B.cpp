#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200010;
const ll MOD = 1e9 + 7;
ll n, k, m;
ll a[MAXN];
ll tmp[MAXN];
ll pre[MAXN],sub[MAXN];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tmp[i] = a[i];
  }
  sort(tmp + 1, tmp + n + 1);
  m = unique(tmp + 1, tmp + n + 1) - tmp - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(tmp + 1, tmp + m + 1, a[i]) - tmp;
    if (k != 1) a[i + n] = a[i];
  }
  memset(tmp, 0, sizeof(tmp));
  for (int i = 1; i <= n; i++) {
    pre[i] = tmp[a[i]];
    sub[tmp[a[i]]] = i;
    tmp[a[i]] = i;
  }
  #ifdef DEBUG
  system("pause");
  #endif
  return 0;
}