#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
class Splay {
  struct Node {
    ll son[2], par, val, sum, size, tag;
  };
  array<Node, MAXN> splay;
  ll rt, tot = 0, size;
  bool which(ll x) { return x == splay[splay[x].par].son[1]; }
#define lson splay[p].son[0]
#define rson splay[p].son[1]
  void pushup(ll p) {
    if (!p)
      return;
    splay[p].size = splay[lson].size + splay[rson].size + 1;
    splay[p].sum = splay[lson].sum + splay[rson].sum + splay[p].val;
  }
  void modifynode(ll p, ll d) {
    if (!p)
      return;
    splay[p].sum += splay[p].size * d;
    splay[p].val += d;
    splay[p].tag += d;
  }
  void pushdown(ll p) {
    if (p && splay[p].tag) {
      modifynode(lson, splay[p].tag);
      modifynode(rson, splay[p].tag);
      splay[p].tag = 0;
    }
  }
  void rotate(ll cur) {
    auto p = splay[cur].par, gp = splay[p].par;
    bool chkc = which(cur), chkp = which(p);
    pushdown(gp);
    pushdown(p);
    pushdown(cur);
    splay[p].son[chkc] = splay[cur].son[chkc ^ 1];
    if (splay[cur].son[chkc ^ 1])
      splay[splay[cur].son[chkc ^ 1]].par = p;
    splay[cur].son[chkc ^ 1] = p;
    if (p)
      splay[p].par = cur;
    splay[cur].par = gp;
    if (gp)
      splay[gp].son[chkp] = cur;
    pushup(p);
    pushup(cur);
    pushup(gp);
  }
  void spl(ll cur, ll fa) {
    for (auto p = splay[cur].par; p && p != fa; p = splay[cur].par) {
      if (splay[p].par != fa)
        rotate(which(cur) ^ which(p) ? cur : p);
      rotate(cur);
    }
    if (fa == 0)
      rt = cur;
  }
  ll getbyrank(ll rk) {
    ll p = rt;
    while (true) {
      pushdown(p);
      if (rk <= splay[lson].size) {
        p = lson;
      } else {
        rk -= (splay[lson].size + 1);
        if (rk == 0)
          return p;
        p = rson;
      }
    }
  }
  ll buildimpl(const array<ll, MAXN> &orig, ll l, ll r, ll pa) {
    if (l > r)
      return 0;
    ll mid = (l + r) / 2, p = ++tot;
    splay[p].par = pa;
    splay[p].val = orig[mid];
    lson = buildimpl(orig, l, mid - 1, p);
    rson = buildimpl(orig, mid + 1, r, p);
    pushup(p);
    return p;
  }

public:
  void build(ll x, const array<ll, MAXN> &orig) {
    size = x;
    rt = buildimpl(orig, 1, x, 0);
  }
  void modify(ll l, ll r, ll diff) {
    if (l != 1 && r != size) {
      auto lptr = getbyrank(l - 1), rptr = getbyrank(r + 1);
      spl(lptr, 0);
      spl(rptr, lptr);
      modifynode(splay[splay[rt].son[1]].son[0], diff);
    } else if (l == 1 && r == size) {
      modifynode(rt, diff);
    } else if (l == 1) {
      auto ptr = getbyrank(r + 1);
      spl(ptr, 0);
      modifynode(splay[rt].son[0], diff);
    } else {
      auto ptr = getbyrank(l - 1);
      spl(ptr, 0);
      modifynode(splay[rt].son[1], diff);
    }
  }
  ll query(ll l, ll r) {
    if (l != 1 && r != size) {
      auto lptr = getbyrank(l - 1), rptr = getbyrank(r + 1);
      spl(lptr, 0);
      spl(rptr, lptr);
      return splay[splay[splay[rt].son[1]].son[0]].sum;
    } else if (l == 1 && r == size) {
      return splay[rt].sum;
    } else if (l == 1) {
      auto ptr = getbyrank(r + 1);
      spl(ptr, 0);
      return splay[splay[rt].son[0]].sum;
    } else {
      auto ptr = getbyrank(l - 1);
      spl(ptr, 0);
      return splay[splay[rt].son[1]].sum;
    }
  }
#undef lson
#undef rson
};
ll n, q;
array<ll, MAXN> orig;
Splay splay;
int main() {
  ll opt, u, v, w;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> orig[i];
  }
  splay.build(n, orig);
  while (q--) {
    cin >> opt;
    if (opt == 1) {
      cin >> u >> v >> w;
      splay.modify(u, v, w);
    } else {
      cin >> u >> v;
      cout << splay.query(u, v) << endl;
    }
  }
  return 0;
}