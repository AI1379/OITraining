/**
# 贴标签 - 沈奕天

## 题目描述

小A的墙上有$n$个钩子，每个钩子上可以挂若干个标签。接下来小A进行了若干次操作，每次操作是将钩子
$((i\times p+q  )\mod n)+1$到$((i\times q+p)\mod n)+1$之间的钩子挂上标签$i$。

现在，总共有$m$次这样的操作，问最后所有钩子最上面的一个标签编号是多少。

## 输入格式

第一行四个整数$n,m,p,q$，意义题目中已给出。

## 输出格式

输出一行$n$个整数，代表每个钩子最上面的一个标签的编号。

## 样例 #1

### 样例输入 #1

```
7 5 3 2
```

### 样例输出 #1

```
4 4 4 5 5 5 5
```

## 提示

对于$20\%$的数据，保证$p=q$

对于$60\%$的数据，$n,m\leq 1000$。

对于$100\%$的数据，$1\leq n \leq 1\times 10^6,1\leq m \leq 1\times 10^7$。

保证$m\times q +p$与$m\times p +q$在`int`范围内。

本题开启subtask

**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
struct Node {
  ll l, r, tag;
};
ll n, m, p, q, curp, curq;
Node segt[MAXN * 4];
ll pos[MAXN];
void build(ll cur, ll l, ll r) {
  ll mid = (l + r) / 2;
  segt[cur].l = l;
  segt[cur].r = r;
  if (l != r) {
    build(cur * 2, l, mid);
    build(cur * 2 + 1, mid + 1, r);
  } else {
    pos[l] = cur;
  }
}
void modify(ll cur, ll l, ll r, ll t) {
  if (l <= segt[cur].l && segt[cur].r <= r) {
    segt[cur].tag = max(segt[cur].tag, t);
    return;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (l <= mid && t > segt[cur * 2].tag)
    modify(cur * 2, l, r, t);
  if (mid + 1 <= r && t > segt[cur * 2 + 1].tag)
    modify(cur * 2 + 1, l, r, t);
}
void pushdown(ll cur) {
  if (segt[cur].l == segt[cur].r)
    return;
  segt[cur * 2].tag = max(segt[cur * 2].tag, segt[cur].tag);
  segt[cur * 2 + 1].tag = max(segt[cur * 2 + 1].tag, segt[cur].tag);
  pushdown(cur * 2);
  pushdown(cur * 2 + 1);
}
int main() {
  // ll x, y;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> p >> q;
  if (p != q) {
    build(1, 1, n);
    p %= n;
    q %= n;
    for (int i = m; i >= 1; --i) {
      curp = min((i * p + q) % n, (i * q + p) % n) + 1;
      curq = max((i * p + q) % n, (i * q + p) % n) + 1;
      modify(1, curp, curq, i);
    }
    pushdown(1);
    for (int i = 1; i <= n; ++i) {
      cout << segt[pos[i]].tag << ' ';
    }
    cout << endl;
  } else {
    for (int i = 1; i <= m; ++i)
      pos[(i + 1) * p % n + 1] = i;
    for (int i = 1; i <= n; ++i)
      cout << pos[i] << ' ';
    cout << endl;
  }
  return 0;
}