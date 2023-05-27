#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
static constexpr const ll MAXN = 120010;
static constexpr const ll INF = 1ll << (sizeof(ll) * 8 - 2);
struct Node {
  ll lson, rson;
  ll size, data, pri;
  ll maxa, mina;
  ll maxa2, mina2;
  bool tag;
};
static ll n;
static ll root;
static Node treap[MAXN];
void pushup(ll p) {
  treap[p].size = treap[treap[p].lson].size + treap[treap[p].rson].size + 1;
  treap[p].maxa = max(treap[treap[p].lson].maxa, treap[treap[p].rson].maxa);
  treap[p].mina = min(treap[treap[p].lson].mina, treap[treap[p].rson].mina);
  treap[p].tag = treap[treap[p].lson].tag || treap[treap[p].rson].tag;
  if(!treap[p].tag){}
}
pll split(ll p, ll rk) {
  pll tmp;
  if (p == 0)
    return make_pair(0, 0);
  if (rk <= treap[treap[p].lson].size) {
    tmp = split(treap[p].lson, rk);
    treap[p].lson = tmp.second;
    pushup(p);
    return make_pair(tmp.first, p);
  } else if (rk == treap[treap[p].lson].size + 1) {
    tmp = make_pair(treap[p].lson, p);
    treap[p].lson = 0;
    pushup(p);
    return tmp;
  } else {
    tmp = split(treap[p].rson, rk - treap[treap[p].lson].size - 1);
    treap[p].rson = tmp.first;
    pushup(p);
    return make_pair(p, tmp.second);
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
static ll stk[MAXN], top;
void init(ll p) {
  if (!p)
    return;
  treap[p].maxa = treap[p].mina = treap[p].data;
  init(treap[p].lson);
  init(treap[p].rson);
  pushup(p);
}
void build() {
  for (int i = 1; i <= n; ++i) {
    while (top && treap[stk[top]].pri > treap[i].pri)
      treap[i].lson = stk[top--];
    if (top)
      treap[stk[top]].rson = i;
    stk[++top] = i;
  }
  root = stk[1];
  init(root);
}
static ll q;
static ll l, k, r;
void modify(ll l, ll r, ll k) {
  pll tmp;
  ll a, b, c;
  tmp = split(root, l);
  a = tmp.first;
  tmp = split(tmp.second, r + 1);
  c = tmp.second;
  tmp = split(tmp.first, r - l - k + 2);
  b = merge(tmp.second, tmp.first);
  a = merge(a, b);
  root = merge(a, c);
}
void query() {
  cin >> l >> r >> k;

  if (treap[root].tag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
void middfs(ll u) {
  if (treap[u].lson)
    middfs(treap[u].lson);
  cout << treap[u].data << ' ';
  if (treap[u].rson)
    middfs(treap[u].rson);
}
void predfs(ll u) {
  cout << treap[u].data << ' ';
  if (treap[u].lson)
    predfs(treap[u].lson);
  if (treap[u].rson)
    predfs(treap[u].rson);
}
int main() {
  static random_device rd;
  static mt19937_64 mt(rd());
  static uniform_int_distribution<ll> dist(1ll, MAXN);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> treap[i].data;
    treap[i].pri = dist(mt);
    treap[i].size = 1;
  }
  build();
  cin >> q;
  while (q--)
    query();
  return 0;
}
/*
7
7 5 6 3 4 2 1
5
4 5 1
2 5 2
2 6 3
2 7 3
1 7 4
*/