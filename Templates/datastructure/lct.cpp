#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
constexpr const ll MAXN = 100010;
namespace LCT {
enum SplayField {
  lson = 0,
  rson = 1,
  data = 2,
  fa = 3,
  size = 4,
  flip = 5,
};
constexpr const ll kSplayFields = 6;
constexpr const ll kStdFlipTag = 0;
ll splayt[MAXN][kSplayFields];
ll getType(ll p) { return p == splayt[splayt[p][fa]][lson]; }
bool isroot(ll p) {
  return splayt[splayt[p][fa]][lson] != p && splayt[splayt[p][fa]][rson] != p;
}
void pushdown(ll p) {
  if (splayt[p][flip] != kStdFlipTag) {
    splayt[p][flip] = kStdFlipTag;
  }
}
void pushup(ll p) {
  splayt[p][size] =
      splayt[splayt[p][lson]][size] + splayt[splayt[p][rson]][size];
}
void rotate(ll x) {
  int y = splayt[x][fa], z = splayt[y][fa], k = getType(x);
  if (!isroot(y))
    splayt[z][splayt[z][rson] == y] = x;
  splayt[y][k] = splayt[x][!k];
  splayt[splayt[x][!k]][fa] = y;
  splayt[x][!k] = y;
  splayt[y][fa] = x, splayt[x][fa] = z;
  pushup(y);
  pushup(x);
}
void update(ll p) {
  if (!isroot(p))
    update(splayt[p][fa]);
  pushdown(p);
}
void splay(ll p) {
  static ll f;
  update(p);
  for (f = splayt[p][fa]; f = splayt[p][fa], !isroot(p); rotate(p)) {
    if (!isroot(f))
      rotate(getType(f) == getType(p) ? f : p);
  }
}
ll access(ll x) {
  static ll p;
  for (p = 0; x; p = x, x = splayt[x][fa]) {
    splay(x);
    splayt[x][rson] = p;
    pushup(x);
  }
  return p;
}
void makeroot(ll p) {
  p = access(p);
  swap(splayt[p][lson], splayt[p][rson]);
  splayt[p][flip] ^= 1;
}
void link(ll x, ll p) {
  makeroot(x);
  splay(x);
  splayt[x][fa] = p;
}
ll findRoot(ll x) {
  access(x);
  splay(x);
  pushdown(x);
  while (splayt[x][lson]) {
    x = splayt[x][lson];
    pushdown(x);
  }
  splay(x);
  return x;
}
} // namespace LCT
int main() { return 0; }
