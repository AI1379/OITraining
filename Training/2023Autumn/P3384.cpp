#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)
struct edge {
  int next, to;
} edge[maxn << 1];
struct segment_tree {
  int l, r, dat, tag;
} t[maxn << 2];
int head[maxn], tot = 0, cnt = 0;
void init(int n) {
  for (int i = 1; i <= n; i++) {
    head[i] = -1;
  }
}
void add_edge(int u, int v) {
  edge[cnt].to = v;
  edge[cnt].next = head[u];
  head[u] = cnt++;
}
int w[maxn], n, m, root, mod;
int dep[maxn], fa[maxn], son[maxn], siz[maxn];
int top[maxn], nid[maxn], oid[maxn], nw[maxn];
int tree[maxn << 2], tag[maxn << 2];
void dfs1(int now, int fath) {
  dep[now] = dep[fath] + 1;
  fa[now] = fath;
  siz[now] = 1;
  son[now] = 0;
  for (int i = head[now]; i != -1; i = edge[i].next) {
    if (edge[i].to == fath)
      continue;
    dfs1(edge[i].to, now);
    siz[now] += siz[edge[i].to];
    if (siz[son[now]] < siz[edge[i].to]) {
      son[now] = edge[i].to;
    }
  }
}
void dfs2(int now, int topx) {
  top[now] = topx;
  nid[now] = ++tot;
  nw[tot] = w[now];
  if (son[now])
    dfs2(son[now], topx);
  else
    return;
  for (int i = head[now]; i != -1; i = edge[i].next) {
    if (edge[i].to != fa[now] && edge[i].to != son[now]) {
      dfs2(edge[i].to, edge[i].to);
    }
  }
}
void up(int p) { tree[p] = tree[ls] + tree[rs]; }
void down(int l, int r, int p) {
  tag[ls] += tag[p];
  tag[rs] += tag[p];
  tree[ls] += (mid - l + 1) * tag[p];
  tree[ls] %= mod;
  tree[rs] += (r - mid) * tag[p];
  tree[rs] %= mod;
  tag[p] = 0;
}
void build(int l, int r, int p) {
  if (l == r) {
    tree[p] = nw[l];
    return;
  }
  build(l, mid, ls);
  build(mid + 1, r, rs);
  up(p);
}
void update(int l, int r, int nl, int nr, int p, int k) {
  if (l >= nl && r <= nr) {
    tree[p] += (r - l + 1) * k;
    tree[p] %= mod;
    tag[p] += k;
    return;
  }
  down(l, r, p);
  if (mid >= nl) {
    update(l, mid, nl, nr, ls, k);
  }
  if (nr > mid) {
    update(mid + 1, r, nl, nr, rs, k);
  }
  up(p);
}
long long query(int l, int r, int nl, int nr, int p) {
  if (l >= nl && r <= nr) {
    return tree[p] % mod;
  }
  long long res = 0ll;
  down(l, r, p);
  if (mid >= nl) {
    res += query(l, mid, nl, nr, ls);
  }
  if (nr > mid) {
    res += query(mid + 1, r, nl, nr, rs);
  }
  return res;
}
int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) {
      swap(x, y);
    }
    x = fa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
int q_range(int x, int y) {

  long long ans = 0ll;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) {
      swap(x, y);
    }
    ans = (ans + query(1, n, nid[top[x]], nid[x], 1)) % mod;
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) {
    swap(x, y);
  }
  ans = (ans + query(1, n, nid[x], nid[y], 1)) % mod;
  return ans % mod;
}
int q_tree(int x) { return query(1, n, nid[x], nid[x] + siz[x] - 1, 1) % mod; }
void upd_range(int x, int y, int k) {
  k %= mod;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) {
      swap(x, y);
    }
    update(1, n, nid[top[x]], nid[x], 1, k);
    x = fa[top[x]];
  }
  if (dep[x] > dep[y])
    swap(x, y);
  update(1, n, nid[x], nid[y], 1, k);
}
void upd_tree(int x, int k) { update(1, n, nid[x], nid[x] + siz[x] - 1, 1, k); }
int main() {
  cin >> n >> m >> root >> mod;
  init(n);
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1, l, r; i <= n - 1; i++) {
    cin >> l >> r;
    add_edge(l, r);
    add_edge(r, l);
  }
  dfs1(root, 0);
  dfs2(root, root);
  build(1, n, 1);
  int choice, x, y, k;
  for (int i = 1; i <= m; i++) {
    cin >> choice;
    if (choice == 1) {
      cin >> x >> y >> k;
      upd_range(x, y, k);
    } else if (choice == 2) {
      cin >> x >> y;
      cout << q_range(x, y) % mod << endl;
    } else if (choice == 3) {
      cin >> x >> k;
      upd_tree(x, k);
    } else {
      cin >> x;
      cout << q_tree(x) % mod << endl;
    }
  }
  return 0;
}
/**
5 5 2 24
7 3 7 8 0
1 2
1 5
3 1
4 1
3 4 2
3 2 2
4 5
1 5 1 3
2 1 3

2
21
 **/
