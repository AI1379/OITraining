#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
constexpr const ll MAXN = 100010;
namespace LCT {
  enum SplayField {
    lson = 0,
    rson = 1,
    data = 2,
    fa = 3,
    size = 4,
    tag = 5,
  };
  constexpr const ll kSplayFields = 6;
  ll splayt[MAXN][kSplayFields];
  ll getType(ll p) {
    return p == splayt[splayt[p][fa]][lson];
  }
  bool isroot(ll p) {
    return splayt[splayt[p][fa]][lson] != p && splayt[splayt[p][fa]][rson] != p;
  }
  void pushdown(ll p) {
  }
  void pushup(ll p) {
    splayt[p][size] = splayt[splayt[p][lson]][size] + splayt[splayt[p][rson]][size];
  }
  void rotate(ll x) {
    int y = splayt[x][fa], z = splayt[y][fa], k = getType(x);
    if (!isroot(y)) splayt[z][splayt[z][rson] == y] = x;
    splayt[y][k] = splayt[x][!k];
    splayt[splayt[x][!k]][fa] = y;
    splayt[x][!k] = y;
    splayt[y][fa] = x, splayt[x][fa] = z;
    pushup(y);
    pushup(x);
  }
  void splay(ll p, ll desf) {
    static ll f;
    for (f = splayt[p][fa]; f = splayt[p][fa], f != desf && !isroot(p); rotate(p))
      if (splayt[f][fa] != desf)
        rotate(getType(f) == getType(p) ? f : p);
  }
}
int main() {
  return 0;
}
