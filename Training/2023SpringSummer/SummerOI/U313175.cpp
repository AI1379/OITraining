/**
# 状态树上最大值 - 徐佑

## 题目背景

有一颗树，需要求出在状态限制下的树上最大值

~~本题应该给足了部分分~~

## 题目描述

给定一棵有 $n$ 个节点的有根树，树的根为 $1$，树上每个节点有点权
$w_i$。每个节点初始状态$s_i$，有状态 $s_i\in\{0,1\}$。

现在有 $m$ 次操作。每次操作会选择节点 $x$，接着：

- 若 $x$ 的状态为 $0$，则将 $x$ 的状态置为 $1$；
- 将 $x$ 的状态为 $1$，则将 $x$ 的状态置为 $0$，同时将**所有 $\bm x$
节点的儿子节点**的状态置为 $1$。

在第一次操作之前，以及每次操作之后，输出 ```所有状态为 1
的节点，权值的最大值```。**特别地**，若此时没有状态为 $1$ 的节点，请输出 $-1$。

## 输入格式

第一行有两个整数 $n,m$，分别表示这棵树的节点个数以及操作个数。

接下来 $n-1$ 行，每行两个整数 $u,v$，表示树的一条边。

接下来一行有 $n$ 个整数，第 $i$ 个整数给出 $w_i$ 的值。

接下来一行有 $n$ 个整数，第 $i$ 个整数给出 $s_i$ 的初始值。

接下来 $m$ 行，每行有一个整数 $x$，描述这次操作的节点。

## 输出格式

输出共 $m+1$ 行，表示每次询问的结果。

## 样例 #1

### 样例输入 #1

```
11 5
1 2
1 8
1 9
2 3
2 4
9 10
9 11
4 5
4 6
4 7
7 4 5 2 3 3 6 5 3 4 1
1 0 0 0 0 1 0 0 1 0 1
1
8
2
4
1
```

### 样例输出 #1

```
7
5
4
5
6
7
```

## 提示

对于 $40\%$ 的数据 $1 \le n,m \le 5\times 10^3$

对于另外 $20\%$ 的数据 $保证这棵树是一条链$

对于另外 $20\%$ 的数据 $保证这棵树是一个菊花图$

对于 $100\%$ 的数据 $1 \le n,m \le 2\times 10^5, 1\le w_i\le 10^9$
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200010;
struct Node {
  ll l, r, val, tag, max;
};
ll n, m;
vector<ll> tr[MAXN];
ll sta[MAXN], val[MAXN], bfn[MAXN], node[MAXN], tot;
ll top[MAXN], bot[MAXN], fa[MAXN];
Node segt[MAXN * 4];
void pushup(ll cur) {
  segt[cur].val = max(segt[cur * 2].val, segt[cur * 2 + 1].val);
  segt[cur].max = max(segt[cur * 2].max, segt[cur * 2 + 1].max);
}
void pushdown(ll cur) {
  if (segt[cur].tag) {
    segt[cur].tag = 0;
    segt[cur * 2].val = segt[cur * 2].max;
    segt[cur * 2 + 1].val = segt[cur * 2 + 1].max;
    segt[cur * 2].tag = segt[cur * 2 + 1].tag = 1;
  }
}
void build(ll cur, ll l, ll r) {
  segt[cur].l = l;
  segt[cur].r = r;
  if (l == r) {
    segt[cur].val = sta[node[l]] * val[node[l]];
    segt[cur].max = val[node[l]];
    return;
  }
  ll mid = (l + r) / 2;
  build(cur * 2, l, mid);
  build(cur * 2 + 1, mid + 1, r);
  pushup(cur);
}
bool check(ll cur, ll pos) {
  if (segt[cur].l == pos && segt[cur].r == pos) {
    return segt[cur].val == segt[cur].max;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  pushdown(cur);
  if (pos <= mid)
    return check(cur * 2, pos);
  else
    return check(cur * 2 + 1, pos);
}
void modify(ll cur, ll pos) {
  if (segt[cur].l == pos && segt[cur].r == pos) {
    segt[cur].val = (segt[cur].val == segt[cur].max ? 0 : segt[cur].max);
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  pushdown(cur);
  if (pos <= mid)
    modify(cur * 2, pos);
  else
    modify(cur * 2 + 1, pos);
  pushup(cur);
}
void modify(ll cur, ll l, ll r) {
  if (l > r)
    return;
  if (l <= segt[cur].l && segt[cur].r <= r) {
    segt[cur].val = segt[cur].max;
    segt[cur].tag = 1;
    return;
  }
  pushdown(cur);
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (l <= mid)
    modify(cur * 2, l, r);
  if (mid + 1 <= r)
    modify(cur * 2 + 1, l, r);
  pushup(cur);
}
bool vis[MAXN];
ll q[MAXN], head, tail;
int main() {
  ll u, v;
  cin >> n >> m;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> u >> v;
    tr[u].emplace_back(v);
    tr[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> sta[i];
  }
  head = tail = 1;
  q[tail++] = 1;
  vis[1] = true;
  while (head < tail) {
    u = q[head++];
    bfn[u] = ++tot;
    node[bfn[u]] = u;
    for (auto v : tr[u]) {
      if (vis[v])
        continue;
      fa[v] = u;
      q[tail++] = v;
      vis[v] = true;
    }
  }
  for (u = 1; u <= n; ++u) {
    top[u] = n;
    for (auto v : tr[u]) {
      if (v == fa[u])
        continue;
      top[u] = min(top[u], bfn[v]);
      bot[u] = max(bot[u], bfn[v]);
    }
  }
  build(1, 1, n);
  cout << segt[1].val << endl;
  while (m--) {
    cin >> u;
    if (check(1, bfn[u]))
      modify(1, top[u], bot[u]);
    modify(1, bfn[u]);
    if (segt[1].val)
      cout << segt[1].val << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
/**
11 5
1 2
1 8
1 9
2 3
2 4
9 10
9 11
4 5
4 6
4 7
7 4 5 2 3 3 6 5 3 4 1
1 0 0 0 0 1 0 0 1 0 1
1
8
2
4
1

7
5
4
5
6
7
**/