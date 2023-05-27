#include <algorithm>
#include <iostream>
#include <type_traits>

using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
static ll n, m;
static ll val[MAXN];
namespace Splay {
static ll root, tot, nil;
static ll child[MAXN][2];
static ll parent[MAXN];
static ll data[MAXN];
static ll sub_size[MAXN];
static bool tag[MAXN];
} // namespace Splay
bool which(ll x) { return x == Splay::child[Splay::parent[x]][1]; }
ll buildSplay(ll l, ll r, ll pa) {
  using namespace Splay;
  if (l > r) {
    return nil;
  }
  ll mid = (l + r) / 2, cur = ++tot;
  parent[cur] = pa;
  Splay::data[cur] = val[mid];
  child[cur][0] = buildSplay(l, mid - 1, cur);
  child[cur][1] = buildSplay(mid + 1, r, cur);
  sub_size[cur] = sub_size[child[cur][0]] + sub_size[child[cur][1]] + 1;
  return cur;
}
void rotate(ll cur) {
  using namespace Splay;
  ll p = parent[cur], gp = parent[p];
  bool chkc = which(cur), chkp = which(p);
  child[p][chkc] = child[cur][chkc ^ 1];
  if (child[cur][chkc ^ 1])
    parent[child[cur][chkc ^ 1]] = p;
  child[cur][chkc ^ 1] = p;
  parent[p] = cur;
  parent[cur] = gp;
  if (gp)
    child[gp][chkp] = cur;
  sub_size[cur] = sub_size[child[cur][0]] + sub_size[child[cur][1]] + 1;
  sub_size[p] = sub_size[child[p][0]] + sub_size[child[p][1]] + 1;
}
void splay(ll cur, ll des_fa) {
  using namespace Splay;
  for (ll p = parent[cur]; p && p != des_fa; p = parent[cur]) {
    if (parent[p] != des_fa)
      rotate(which(cur) ^ which(p) ? cur : p);
    rotate(cur);
  }
  if (des_fa == nil)
    root = cur;
}
void pushdown(ll cur) {
  using namespace Splay;
  if (tag[cur]) {
    tag[child[cur][0]] ^= 1;
    tag[child[cur][1]] ^= 1;
    swap(child[cur][0], child[cur][1]);
    tag[cur] = 0;
  }
}
ll findByOrder(ll ord) {
  using namespace Splay;
  ll cur = root;
  while (true) {
    pushdown(cur);
    if (ord <= sub_size[child[cur][0]]) {
      cur = child[cur][0];
    } else {
      ord -= (sub_size[child[cur][0]] + 1);
      if (ord == 0)
        return cur;
      cur = child[cur][1];
    }
  }
}
void reverse(ll l, ll r) {
  using namespace Splay;
  ll lptr = findByOrder(l - 1), rptr = findByOrder(r + 1);
  splay(lptr, nil);
  splay(rptr, lptr);
  tag[child[child[root][1]][0]] ^= 1;
}
int main() {
  ll l, r;
  cin >> n >> m;
  val[1] = -INF;
  val[n + 2] = INF;
  for (int i = 1; i <= n; i++) {
    val[i + 1] = i;
  }
  Splay::nil = 0;
  Splay::root = buildSplay(1, n + 2, Splay::nil);
  while (m--) {
    cin >> l >> r;
    reverse(l + 1, r + 1);
  }
  return 0;
}