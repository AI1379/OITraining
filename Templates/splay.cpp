#include <algorithm>
#include <iostream>

using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
struct Node {
  ll fa, lchild, rchild;
  ll val;
  bool tag;
};
static ll n, m;
static ll val[MAXN];
static Node splay_tree[MAXN];
static ll root, tot = 0;
static ll l, r;
ll buildSplay(ll l, ll r, ll fa) {
  if (l > r)
    return 0;
  ll mid = (l + r) / 2, cur = ++tot;
  splay_tree[cur].fa = fa;
  splay_tree[cur].val = val[mid];
  splay_tree[cur].lchild = buildSplay(l, mid - 1, cur);
  splay_tree[cur].rchild = buildSplay(mid + 1, r, cur);
  splay_tree[cur].tag = false;
  return cur;
}
void leftRotate(ll node_pos) {}
void rightRotate(ll node_pos) {
  
}
void splay(ll node_pos, ll des_pos) {

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  val[1] = -INF;
  val[n + 2] = INF;
  for (int i = 1; i <= n; i++) {
    val[i + 1] = i;
  }
  root = buildSplay(1, n + 2, 0);
  while (m--) {
    cin >> l >> r;
    splay(l - 1, 0);
    splay(r + 1, l - 1);
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}