#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n, m;
ll bit[MAXN];
ll add[MAXN];
ll lowbit(ll x) { return x & (-x); }
void modify(ll x, ll p) {
  for (; p <= n; p += lowbit(p))
    bit[p] += x;
}
ll query(ll p) {
  ll res = 0;
  for (; p; p -= lowbit(p))
    res += bit[p];
  return res;
}
int main() {
  ll opt, u, v, res;
  cin >> n >> m;
  // 最坏复杂度 O(m*sqrt(n))
  // 如果不加特判 opt==1 的时候修改最坏复杂度是 O(n)
  // 总的最坏复杂度 O(m*n)
  while (m--) {
    cin >> opt >> u >> v;
    if (opt == 1) {
      if (u * u <= n) {
        // O(1)
        add[u] += v;
      } else {
        // O(sqrt(n))
        for (int i = u; i <= n; i += u)
          modify(v, i);
      }
    } else {
      res = query(v) - query(u - 1);
      // O(sqrt(n))
      for (int i = 1; i * i <= n; ++i) {
        res += add[i] * (v / i - (u - 1) / i);
      }
      cout << res << endl;
    }
  }
  return 0;
}