#include <bits/stdc++.h>
#include <cstddef>
#include <random>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
class Treap {
  struct Node {
    ll lson, rson, val, tag, sum, size, pri;
  };
  Node treap[MAXN];
  ll tot = 0, rt, size;
  void pushup(ll p) {
    treap[p].size = treap[treap[p].lson].size + treap[treap[p].rson].size + 1;
    treap[p].sum =
        treap[treap[p].lson].sum + treap[treap[p].rson].sum + treap[p].val;
  }
  void pushdown(ll p) {
    if (treap[p].tag) {
      treap[treap[p].lson].sum += treap[treap[p].lson].size * treap[p].tag;
      treap[treap[p].rson].sum += treap[treap[p].rson].size * treap[p].tag;
      treap[treap[p].lson].val += treap[p].tag;
      treap[treap[p].rson].val += treap[p].tag;
      treap[treap[p].lson].tag += treap[p].tag;
      treap[treap[p].rson].tag += treap[p].tag;
      treap[p].tag = 0;
    }
  }
  pll split(ll cur, ll rk) {
    if (cur == 0)
      return {0, 0};
    if (treap[treap[cur].lson].size + 1 <= rk) {
      pushdown(cur);
      auto tmp = split(treap[cur].rson, rk - treap[treap[cur].lson].size - 1);
      treap[cur].rson = tmp.first;
      pushup(cur);
      return {cur, tmp.second};
    } else {
      pushdown(cur);
      auto tmp = split(treap[cur].lson, rk);
      treap[cur].lson = tmp.second;
      pushup(cur);
      return {tmp.first, cur};
    }
  }
  ll merge(ll u, ll v) {
    if (u == 0 || v == 0)
      return u ^ v;
    if (treap[u].pri < treap[v].pri) {
      pushdown(v);
      treap[v].lson = merge(u, treap[v].lson);
      pushup(v);
      return v;
    } else {
      pushdown(u);
      treap[u].rson = merge(treap[u].rson, v);
      pushup(u);
      return u;
    }
  }
  ll build(const array<ll, MAXN> &orig, ll p) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    static std::uniform_int_distribution<ll> dist(1, MAXN);
    if (p > size)
      return 0;
    ll cur = ++tot;
    treap[cur].pri = dist(rng);
    treap[cur].val = orig[p];
    pushup(cur);
    return merge(cur, build(orig, p + 1));
  }

public:
  void build(ll x, const array<ll, MAXN> &orig) {
    size = x;
    rt = build(orig, 1);
  }
  void modify(ll l, ll r, ll diff) {
    auto tmp = split(rt, r);
    auto tmpl = split(tmp.first, l - 1);
    treap[tmpl.second].sum += treap[tmpl.second].size * diff;
    treap[tmpl.second].val += diff;
    treap[tmpl.second].tag += diff;
    rt = merge(merge(tmpl.first, tmpl.second), tmp.second);
  }
  ll query(ll l, ll r) {
    auto tmp = split(rt, r);
    auto tmpl = split(tmp.first, l - 1);
    auto res = treap[tmpl.second].sum;
    rt = merge(merge(tmpl.first, tmpl.second), tmp.second);
    return res;
  }
};
ll n, q;
array<ll, MAXN> orig;
Treap splay;
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
/**

5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4

11
8
20

**/