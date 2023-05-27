#include <iostream>
using namespace std;
#define ll int
const ll MAXN = 1000010;
const ll MAXM = 1000010;
const ll MAXMLOGN = 30 * MAXM;
struct Node {
  ll lchild, rchild, val;
  ll l, r;
};
Node segt[MAXMLOGN];
ll n, m;
ll val[MAXN];
ll roots[MAXM];
ll tot;
ll build(ll l, ll r) {
  ll pos = ++tot;
  segt[pos].l = l;
  segt[pos].r = r;
  if (l == r) {
    segt[pos].val = val[l];
    return pos;
  }
  ll mid = (l + r) / 2;
  segt[pos].lchild = build(l, mid);
  segt[pos].rchild = build(mid + 1, r);
  return pos;
}
ll query(ll p, ll cur) {
  if (segt[cur].l == p && segt[cur].r == p) {
    return segt[cur].val;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (p <= mid) {
    return query(p, segt[cur].lchild);
  } else {
    return query(p, segt[cur].rchild);
  }
}
void modify(ll p, ll val, ll pre, ll cur) {
  segt[cur].l = segt[pre].l;
  segt[cur].r = segt[pre].r;
  if (segt[cur].l == p && segt[cur].r == p) {
    segt[cur].val = val;
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (p <= mid) {
    segt[cur].lchild = ++tot;
    segt[cur].rchild = segt[pre].rchild;
    modify(p, val, segt[pre].lchild, segt[cur].lchild);
  } else {
    segt[cur].rchild = ++tot;
    segt[cur].lchild = segt[pre].lchild;
    modify(p, val, segt[pre].rchild, segt[cur].rchild);
  }
}
ll v, k, s, t, x;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  roots[0] = build(1, n);
  for (int i = 1; i <= m; i++) {
    cin >> v >> k;
    if (k == 1) {
      cin >> s >> t;
      roots[i] = ++tot;
      modify(s, t, roots[v], roots[i]);
    } else {
      cin >> x;
      roots[i] = ++tot;
      segt[roots[i]] = segt[roots[v]];
      cout << query(x, roots[i]) << endl;
    }
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}