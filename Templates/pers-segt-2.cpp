// https://www.luogu.com.cn/problem/P3834
// static range kth element
#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
const ll MAXN = 200010;
const ll MAXMLOGN = 20 * MAXN;
struct Node {
  ll l, r;
  ll lchild, rchild;
  ll val;
};
static Node segt[MAXMLOGN];
static ll tot;
static ll n, m, num;
static ll val[MAXN], f[MAXN];
static ll roots[MAXN];
#define lc segt[cur].lchild
#define rc segt[cur].rchild
void insert(ll v, ll cur, ll pre) {
  segt[cur].val = segt[pre].val;
  segt[cur].lchild = segt[pre].lchild;
  segt[cur].rchild = segt[pre].rchild;
  if (segt[cur].l == v && segt[cur].r == v) {
    ++segt[cur].val;
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (v <= mid) {
    segt[cur].lchild = ++tot;
    segt[lc].l = segt[cur].l;
    segt[lc].r = mid;
    insert(v, lc, segt[pre].lchild);
  } else {
    segt[cur].rchild = ++tot;
    segt[rc].l = mid + 1;
    segt[rc].r = segt[cur].r;
    insert(v, rc, segt[pre].rchild);
  }
  segt[cur].val = segt[lc].val + segt[rc].val;
}
ll query(ll k, ll lcur, ll rcur) {
  if (segt[lcur].l == segt[lcur].r && segt[rcur].l == segt[rcur].r &&
      segt[rcur].val - segt[lcur].val >= k) {
    return segt[lcur].l == 0 ? segt[rcur].l : segt[lcur].l;
  }
  ll delta = segt[segt[rcur].lchild].val - segt[segt[lcur].lchild].val;
  if (delta >= k) {
    return query(k, segt[lcur].lchild, segt[rcur].lchild);
  } else {
    return query(k - delta, segt[lcur].rchild, segt[rcur].rchild);
  }
}
int main() {
  ll l, r, k;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
    f[i] = val[i];
  }
  sort(f + 1, f + n + 1);
  num = unique(f + 1, f + n + 1) - f - 1;
  for (int i = 1; i <= n; i++) {
    val[i] = lower_bound(f + 1, f + num + 1, val[i]) - f;
  }
  roots[0] = ++tot;
  segt[roots[0]] = Node{1, num, 0, 0, 0};
  for (int i = 1; i <= n; i++) {
    roots[i] = ++tot;
    segt[roots[i]] = segt[roots[i - 1]];
    insert(val[i], roots[i], roots[i - 1]);
  }
  for (int i = 1; i <= m; i++) {
    cin >> l >> r >> k;
    cout << f[query(k, roots[l - 1], roots[r])] << endl;
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}