#include <algorithm>
#include <iostream>
// TODO: Splay
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll MAXN = 100010;
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
struct Node {
  Node *fa, *son[2];
  ll val, size;
  bool tag;
};
static ll n, m;
static ll val[MAXN];
static Node splay_tree[MAXN];
static Node *root;
static ll tot = 0;
static ll l, r;
Node *buildSplay(ll l, ll r, Node *fa) {
  if (l > r)
    return 0;
  ll mid = (l + r) / 2, cur = ++tot;
  splay_tree[cur].fa = fa;
  splay_tree[cur].val = val[mid];
  splay_tree[cur].son[0] = buildSplay(l, mid - 1, &splay_tree[cur]);
  splay_tree[cur].son[1] = buildSplay(mid + 1, r, &splay_tree[cur]);
  splay_tree[cur].size =
      (splay_tree[cur].son[0]->size) + (splay_tree[cur].son[1]->size);
  splay_tree[cur].tag = false;
  return &splay_tree[cur];
}
void rotate(Node *node) {
  Node *fa = node->fa, *gfa = fa->fa;
  bool tp = (node == fa->son[1]);
  fa->son[tp] = node->son[tp ^ 1];
  if (node->son[tp ^ 1] != nullptr) {
    node->son[tp ^ 1]->fa = fa;
  }
  node->son[tp ^ 1] = fa;
  fa->fa = node;
  node->fa = gfa;
  if (gfa != nullptr) {
    gfa->son[fa == gfa->son[1]] = node;
  }
  fa->size = fa->son[0]->size + fa->son[1]->size;
  node->size = node->son[0]->size + node->son[1]->size;
  return;
}
void splay(Node *node, Node *des_fa) {
  for (Node *f = node->fa; f = node->fa, f != nullptr && f != des_fa;
       rotate(node)) {
    if (f->fa != nullptr) {
      rotate(((node == node->fa->son[1]) ^ (f == f->fa->son[1])) ? f : node);
    }
  }
  if (des_fa == nullptr) {
    root = node;
  }
  return;
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
  root = buildSplay(1, n + 2, nullptr);
  while (m--) {
    cin >> l >> r;
  }
#ifdef VSCODE
  system("pause");
#endif
  return 0;
}