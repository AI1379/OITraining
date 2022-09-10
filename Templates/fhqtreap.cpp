#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
static constexpr const ll MAXN = 100010;
static constexpr const ll INF = 1ll << (sizeof(ll) * 8 - 2);
struct Node {
  ll lson, rson;
  ll size, data, pri, count;
};
static ll n;
static ll root, endt;
static Node treap[MAXN];
void pushup(ll p) {
  treap[p].size =
      treap[treap[p].lson].size + treap[treap[p].rson].size + treap[p].count;
}
pll split(ll p, ll val) {
  pll tmp;
  if (p == 0)
    return {0, 0};
  if (treap[p].data <= val) {
    tmp = split(treap[p].rson, val);
    treap[p].rson = tmp.first;
    pushup(p);
    return {p, tmp.second};
  } else {
    tmp = split(treap[p].lson, val);
    treap[p].lson = tmp.second;
    pushup(p);
    return {tmp.first, p};
  }
}
ll merge(ll u, ll v) {
  if (u == 0 || v == 0)
    return u ^ v;
  if (treap[u].pri <= treap[v].pri) {
    treap[u].rson = merge(treap[u].rson, v);
    pushup(u);
    return u;
  } else {
    treap[v].lson = merge(u, treap[v].lson);
    pushup(v);
    return v;
  }
}
void ins(ll val) {
  static random_device rd;
  static mt19937_64 mt(rd());
  static uniform_int_distribution<ll> dist(1ll, MAXN);
  static pll tmp, tmpl;
  tmp = split(root, val);
  tmpl = split(tmp.first, val - 1);
  if (tmpl.second == 0) {
    treap[++endt].data = val;
    treap[endt].count = 1;
    treap[endt].size = 1;
    treap[endt].pri = dist(mt);
    tmpl.second = endt;
  } else {
    ++treap[tmpl.second].size;
    ++treap[tmpl.second].count;
  }
  root = merge(merge(tmpl.first, tmpl.second), tmp.second);
}
void del(ll val) {
  static pll tmp, tmpl;
  tmp = split(root, val);
  tmpl = split(tmp.first, val - 1);
  if (treap[tmpl.second].count > 1) {
    --treap[tmpl.second].count;
    --treap[tmpl.second].size;
    tmpl.first = merge(tmpl.first, tmpl.second);
  }
  root = merge(tmpl.first, tmp.second);
}
ll getRank(ll p, ll val) {
  if (treap[p].data == val)
    return treap[treap[p].lson].size + 1;
  return treap[p].data > val ? getRank(treap[p].lson, val)
                             : getRank(treap[p].rson, val) +
                                   treap[treap[p].lson].size + treap[p].count;
}
ll getKth(ll p, ll rk) {
  if (treap[treap[p].lson].size >= rk)
    return getKth(treap[p].lson, rk);
  if (treap[treap[p].lson].size + treap[p].count >= rk)
    return treap[p].data;
  return getKth(treap[p].rson, rk - treap[treap[p].lson].size - treap[p].count);
}
ll getPrev(ll val) {
  static ll p, res;
  p = root;
  res = -INF;
  while (p) {
    if (treap[p].data == val) {
      p = treap[p].lson;
      if (p) {
        while (treap[p].rson)
          p = treap[p].rson;
        res = treap[p].data;
      }
      break;
    }
    if (treap[p].data < val)
      res = max(res, treap[p].data);
    p = treap[p].data < val ? treap[p].rson : treap[p].lson;
  }
  return res;
}
ll getNext(ll val) {
  static ll p, res;
  p = root;
  res = INF;
  while (p) {
    if (treap[p].data == val) {
      p = treap[p].rson;
      if (p) {
        while (treap[p].lson)
          p = treap[p].lson;
        res = treap[p].data;
      }
      break;
    }
    if (treap[p].data > val)
      res = min(res, treap[p].data);
    p = treap[p].data < val ? treap[p].rson : treap[p].lson;
  }
  return res;
}
static ll opt, x;
#define pushcase(x, y)                                                         \
  case x: {                                                                    \
    y;                                                                         \
    break;                                                                     \
  }
int main() {
  cin >> n;
  while (n--) {
    cin >> opt >> x;
    switch (opt) {
      pushcase(1, ins(x));
      pushcase(2, del(x));
      pushcase(3, cout << getRank(root, x) << endl);
      pushcase(4, cout << getKth(root, x) << endl);
      pushcase(5, cout << getPrev(x) << endl);
      pushcase(6, cout << getNext(x) << endl);
    }
  }
  return 0;
}
