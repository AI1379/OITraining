#include <iostream>
using namespace std;
#define ll long long
#undef DEBUG
const ll MAXN = 100000;
ll n, m;
ll seq[MAXN];
ll segt[MAXN * 4], tag[MAXN * 4];
void build(ll l, ll r, ll rt) {
  if (l == r) {
    segt[rt] = seq[l];
    return;
  }
  ll mid = (l + r) / 2;
  build(l, mid, rt * 2);
  build(mid + 1, r, rt * 2 + 1);
  segt[rt] = segt[rt * 2] + segt[rt * 2 + 1];
}
void pushdown(ll s, ll e, ll m, ll rt) {
#ifdef DEBUG
  cout << rt << endl;
#endif
  if (tag[rt]) {
    segt[rt * 2] += tag[rt] * (m - s + 1);
    segt[rt * 2 + 1] += tag[rt] * (e - m);
    tag[rt * 2] += tag[rt];
    tag[rt * 2 + 1] += tag[rt];
    tag[rt] = 0;
  }
}
ll query(ll l, ll r, ll s, ll e, ll rt) {
  if (s <= l && r <= e)
    return segt[rt];
  ll res = 0, mid = (l + r) / 2;
  pushdown(l, r, mid, rt);
  if (s <= mid)
    res += query(l, mid, s, e, rt * 2);
  if (mid + 1 <= e)
    res += query(mid + 1, r, s, e, rt * 2 + 1);
  return res;
}
void update(ll l, ll r, ll s, ll e, ll d, ll rt) {
  if (s <= l && r <= e) {
    segt[rt] += (r - l + 1) * d;
    tag[rt] += d;
    return;
  }
  ll mid = (l + r) / 2;
  if (l != r)
    pushdown(l, r, mid, rt);
  if (s <= mid)
    update(l, mid, s, e, d, rt * 2);
  if (mid + 1 <= e)
    update(mid + 1, r, s, e, d, rt * 2 + 1);
  segt[rt] = segt[rt * 2] + segt[rt * 2 + 1];
  return;
}
int main() {
  ll x, y, opt, k, out;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> seq[i];
  }
  build(1, n, 1);
  for (int i = 0; i < m; i++) {
    cin >> opt;
    if (opt == 1) {
      cin >> x >> y >> k;
      update(1, n, x, y, k, 1);
    } else if (opt == 2) {
      cin >> x >> y;
      out = query(1, n, x, y, 1);
      cout << out << endl;
    }
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}