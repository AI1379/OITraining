#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const ll MAXN = 100010;
ll n;
vector<ll> origt[MAXN];
ll val[MAXN];
ll splayt[MAXN][2], splayfa[MAXN], splayrt;
ll splaysum[MAXN], splayval[MAXN], splaysize[MAXN], splaytag[MAXN];
ll fa[MAXN], btm[MAXN];
ll getType(ll p) { return splayt[splayfa[p]][1] == p; }
void pushup(ll p) {
  splaysize[p] = splaysize[splayt[p][0]] + splaysize[splayt[p][1]] + 1;
  splaysum[p] = splaysum[splayt[p][0]] + splaysum[splayt[p][1]] + splayval[p];
}
void pushdown(ll p) {
  if (splaytag[p]) {
    splaytag[splayt[p][0]] += splaytag[p];
    splaytag[splayt[p][1]] += splaytag[p];
    splayval[splayt[p][0]] += splaytag[p];
    splayval[splayt[p][1]] += splaytag[p];
    splaysum[splayt[p][0]] += splaytag[p] * splaysize[splayt[p][0]];
    splaysum[splayt[p][1]] += splaytag[p] * splaysize[splayt[p][1]];
    splaytag[p] = 0;
  }
}
void rotate(ll x) {
  ll y = splayfa[x], z = splayfa[y], k = getType(x);
  pushdown(z), pushdown(y);
  if (splayfa[y])
    splayt[z][splayt[z][1] == y] = x;
  splayt[y][k] = splayt[x][!k];
  splayfa[splayt[x][!k]] = y;
  splayt[x][!k] = y;
  splayfa[y] = x, splayfa[x] = z;
  pushup(y), pushup(x);
}
void splay(ll p, ll desf) {
  static ll f;
  for (f = splayfa[p]; f = splayfa[p], f != desf && f; rotate(p))
    if (splayfa[f] != desf)
      rotate(getType(f) == getType(p) ? f : p);
  if (desf == 0)
    splayrt = p;
}
ll prevNode(ll p) {
  static ll cur;
  if (!splayt[p][0]) {
    cur = p;
    while (splayt[splayfa[cur]][0] == cur)
      cur = splayfa[cur];
    return splayfa[cur];
  }
  cur = splayt[p][0];
  while (splayt[cur][1])
    cur = splayt[cur][1];
  return cur;
}
ll nextNode(ll p) {
  static ll cur;
  if (!splayt[p][1]) {
    cur = p;
    while (splayt[splayfa[cur]][1] == cur)
      cur = splayfa[cur];
    return splayfa[cur];
  }
  cur = splayt[p][1];
  while (splayt[cur][0])
    cur = splayt[cur][0];
  return cur;
}
// 拆掉当前根节点的右子以及它的左子树
ll split() {
  static ll p, ps;
  p = splayt[splayrt][1], ps = splayt[p][1];
  pushdown(splayrt), pushdown(p);
  splayt[splayrt][1] = ps;
  splayfa[ps] = splayrt;
  splayfa[p] = splayt[p][1] = 0;
  pushup(splayrt), pushup(p);
  return p;
}
// 把这个节点插入作为根节点的右子
void merge(ll p) {
  static ll ps;
  pushdown(splayrt);
  ps = splayt[p][1];
  splayt[splayrt][1] = p;
  splayfa[p] = splayrt;
  splayt[p][1] = ps;
  splayfa[ps] = p;
  pushup(p), pushup(splayrt);
}
void init() {
  for (int i = 1; i <= n; ++i) {
    fa[i] = btm[i] = i;
  }
}
void makeRoot(ll p, ll f) {
  static ll x, y;
  while (fa[p] != f) {
    x = prevNode(p), y = prevNode(fa[p]);
    splay(y, 0), splay(x, y);
    x = split();
    splay(btm[p], 0);
    merge(x);
    btm[p] = btm[fa[p]];
    fa[p] = fa[fa[p]];
    fa[fa[p]] = p;
  }
}
void changeFa(ll p, ll f) {
  static ll x, y;
  x = prevNode(p), y = btm[p];
  if (btm[fa[p]] == btm[p])
    btm[fa[p]] = x;
  splay(x, 0), splay(y, x);
  x = split();
  splay(btm[f], 0);
  merge(x);
  btm[f] = btm[p];
}
ll query(ll p) {
  splay(prevNode(p), 0);
  splay(nextNode(btm[p]), splayrt);
  return splaysum[splayt[splayt[splayrt][1]][0]];
}
void modify(ll p, ll delta) {
  static ll cur;
  splay(prevNode(p), 0);
  splay(nextNode(btm[p]), splayrt);
  cur = splayt[splayt[splayrt][1]][0];
  splaysum[cur] += splaysum[cur] * delta;
  splaytag[cur] += delta;
  splayval[cur] += delta;
}
ll queryNode(ll p) {
  splay(p, 0);
  return splayval[p];
}
void modifyNode(ll p, ll delta) {
  splay(p, 0);
  splayval[p] += delta;
  splaysum[p] += delta;
}
int main() { return 0; }
