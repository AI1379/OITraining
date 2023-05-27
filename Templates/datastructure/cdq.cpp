#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Query {
  ll diff, val, pos, id;
};
const ll MAXN = 100010;
const ll MAXM = 50010;
ll n, m;
ll a[MAXN], pos[MAXN];
ll bit[MAXN];
ll ans[MAXM];
Query querys[MAXN + MAXM];
ll tot;
ll lowbit(ll x) { return x & (-x); }
ll queryBit(ll p) {
  ll res = 0;
  for (; p; p -= lowbit(p))
    res += bit[p];
  return res;
}
void modifyBit(ll p, ll diff) {
  for (; p <= n; p += lowbit(p))
    bit[p] += diff;
}
bool cmp(const Query &lhs, const Query &rhs) { return lhs.pos < rhs.pos; }
void cdq(ll l, ll r) {
  if (l == r)
    return;
  ll mid = (l + r) >> 1, idx = l;
  cdq(l, mid);
  cdq(mid + 1, r);
  sort(querys + l, querys + mid + 1, cmp);
  sort(querys + mid + 1, querys + r + 1, cmp);
  for (int i = mid + 1; i <= r; ++i) {
  }
}
int main() {
  ll x;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
    querys[++tot] = (Query){1, a[i], i, 0};
  }
  for (int i = 1; i <= m; ++i) {
    cin >> x;
    querys[++tot] = (Query){-1, x, pos[x], i};
  }
  cdq(1, tot);
  return 0;
}