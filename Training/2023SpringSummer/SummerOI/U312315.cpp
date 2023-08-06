/**

# 只因光炸弹 - 龚炫文

## 题目背景

题目名称仅供参考。

题目难度仅供参考。

## 题目描述

本题共有 $T$ 组数据。

一种新型的激光炸弹，可以摧毁一个一条边长为 $m$、临边长为 $n$
的长方形内的所有目标。现在地图上有 $p$ 个目标，用整数 $x_i$ , $y_i$
表示目标在地图上的位置，每个目标都有一个价值
$v_i$。激光炸弹的投放是通过卫星定位的，但其有一个缺点，就是其爆破范围，即那个边长为
$m,n$ 的长方形，边长为 $m$ 的边必须与 $x$ 轴平行, 边长为 $n$ 的边与 $y$
轴平行。若目标位于爆破正方形的边上，该目标不会被摧毁。

现在你的任务是计算一颗炸弹最多能炸掉地图上总价值为多少的目标。

## 输入格式

输入的第一行为一个正整数 $T$。

接下来重复 $T$ 次：

下一行输入三个整数 $p,m,n$。

接下来的 $p$ 行，每行有 $3$ 个整数 $x_i, y_i, v_i$，表示一个目标的坐标与价值。

## 输出格式

每一行输出一个正整数，表示每组数据中一颗炸弹最多能炸掉地图上总价值为多少的目标。

## 样例 #1

### 样例输入 #1

```
1
5 10 10
114514 1919810 114
114519 1919813 514
114508 1919821 1415
1919810 114514 1919
1919802 114511 145
```

### 样例输出 #1

```
2064
```

## 提示

- 对于 $100\%$ 的数据，保证 $1 \le T \le 10,1 \le p \le 10^4$,$0 \le x_i,y_i,v_i
< 2^{31}$,$1 \le m,n \le 10^6$。

**/

#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;
#define ll long long
const ll MAXP = 10010;
struct SegtNode {
  ll l, r, tag, val;
};
struct ScanLine {
  ll pos, down, up, weight;
};
ll t;
ll p, m, n;
ScanLine lines[MAXP * 2];
SegtNode segt[MAXP * 8];
void build(ll cur, ll l, ll r) {
  segt[cur].l = l;
  segt[cur].r = r;
  segt[cur].tag = segt[cur].val = 0;
  if (l == r)
    return;
  ll mid = (l + r) / 2;
  build(cur * 2, l, mid);
  build(cur * 2 + 1, mid + 1, r);
}
void modify(ll cur, ll l, ll r, ll d) {
  if (l > r)
    swap(l, r);
  if (l <= segt[cur].l && segt[cur].r <= r) {
    segt[cur].tag += d;
    segt[cur].val += d;
    return;
  }
  if (segt[cur].tag) {
    segt[cur * 2].tag += segt[cur].tag;
    segt[cur * 2].val += segt[cur].tag;
    segt[cur * 2 + 1].tag += segt[cur].tag;
    segt[cur * 2 + 1].val += segt[cur].tag;
    segt[cur].tag = 0;
  }
  ll mid = (segt[cur].l + segt[cur].r) / 2;
  if (l <= mid)
    modify(cur * 2, l, r, d);
  if (mid + 1 <= r)
    modify(cur * 2 + 1, l, r, d);
  segt[cur].val = max(segt[cur * 2].val, segt[cur * 2 + 1].val);
}
void solve() {
  static ll tmp[MAXP * 2];
  ll x, y, k, ans = 0;
  cin >> p >> m >> n;
  for (int i = 1; i <= p; ++i) {
    cin >> x >> y >> k;
    lines[2 * i - 1] = ScanLine{x, y, y + n - 1, k};
    lines[2 * i] = ScanLine{x + m, y, y + n - 1, -k};
    tmp[2 * i - 1] = y;
    tmp[2 * i] = y + n - 1;
  }
  sort(lines + 1, lines + 2 * p + 1,
       [](const ScanLine &lhs, const ScanLine &rhs) {
         return lhs.pos < rhs.pos;
       });
  sort(tmp + 1, tmp + 2 * p + 1);
  ll tot = unique(tmp + 1, tmp + 2 * p + 1) - tmp;
  for (int i = 1; i <= 2 * p; ++i) {
    lines[i].up = lower_bound(tmp, tmp + tot + 1, lines[i].up) - tmp;
    lines[i].down = lower_bound(tmp, tmp + tot + 1, lines[i].down) - tmp;
    // cout << lines[i].pos << ' ' << lines[i].down << ' ' << lines[i].up << ' '
    //      << lines[i].weight << endl;
  }
  build(1, 1, tot);
  for (int i = 1; i <= 2 * p; ++i) {
    modify(1, lines[i].down, lines[i].up, lines[i].weight);
    ans = max(ans, segt[1].val);
  }
  cout << ans << endl;
  return;
}
int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}
