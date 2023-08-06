#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
struct Node {
  ll l, r, tag;
};
ll n, m, p, q, curp, curq;
Node segt[MAXN * 4];
ll pos[MAXN];
void build(ll cur, ll l, ll r) {
  ll mid = (l + r) / 2;
  segt[cur].l = l;
  segt[cur].r = r;
  if (l != r) {
    build(cur * 2, l, mid);
    build(cur * 2 + 1, mid + 1, r);
  } else {
    pos[l] = cur;
  }
}
void modify(ll cur, ll l, ll r, ll t) {
  if (l <= segt[cur].l && segt[cur].r <= r) {
    segt[cur].tag = max(segt[cur].tag, t);
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (l <= mid && t > segt[cur * 2].tag)
    modify(cur * 2, l, r, t);
  if (mid + 1 <= r && t > segt[cur * 2 + 1].tag)
    modify(cur * 2 + 1, l, r, t);
}
void pushdown(ll cur) {
  if (segt[cur].l == segt[cur].r)
    return;
  segt[cur * 2].tag = max(segt[cur * 2].tag, segt[cur].tag);
  segt[cur * 2 + 1].tag = max(segt[cur * 2 + 1].tag, segt[cur].tag);
  pushdown(cur * 2);
  pushdown(cur * 2 + 1);
}
int main() {
  // ll x, y;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> p >> q;
  if (p != q) {
    build(1, 1, n);
    p %= n;
    q %= n;
    for (int i = m; i >= 1; --i) {
      curp = min((i * p + q) % n, (i * q + p) % n) + 1;
      curq = max((i * p + q) % n, (i * q + p) % n) + 1;
      modify(1, curp, curq, i);
    }
    pushdown(1);
    for (int i = 1; i <= n; ++i) {
      cout << segt[pos[i]].tag << ' ';
    }
    cout << endl;
  } else {
    for (int i = 1; i <= m; ++i)
      pos[(i + 1) * p % n + 1] = i;
    for (int i = 1; i <= n; ++i)
      cout << pos[i] << ' ';
    cout << endl;
  }
  return 0;
}