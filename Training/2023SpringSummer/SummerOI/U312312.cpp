/**

# OI，启动! - 主打一个信心の王嘉熙

## 题目背景

_感谢@AndyShen的数据支持_

_数据暂未完成 先别急着交_

“中考可算是结束了！” 小查茶心里是欢喜不已，“可以接着回去学信奥咯！”

但是，在fj的一节课后，小查茶头昏脑涨：“我脑袋里的OI知识真的是一点都不剩了......”一不做二不休，
他下定决心重新开始复习信奥知识。可是一个问题浮现在了他的脑海中：“我该从哪里开始复习呢？”

小查茶认识到，每个OI知识点可以连成一个有向图。而小查茶也是一个一根筋的同学，当他攻破了某个知识
点后，他才**能够且必须**学习以这个知识点为基础的下一个知识点。因此，他找到了你，希望你能用程序
帮他找到**最有价值且最有效利用时间**的复习方案。

## 题目描述

今天，小查茶决定开始复习，于是他给你了一份由知识点连成的有向图。

他告诉了你：

* 知识点有向图中知识点的总数 --- $n$
* 他今天想复习的时间 --- $m$

而这份有向图中，每个知识点的信息有：

* 复习该知识点的时间（小时）--- $u$
* 复习该知识点的价值系数 --- $v$
* 该知识点复习完成后，可以继续复习的知识点个数 --- $num$
* 该知识点复习完成后，可以继续复习的知识点编号 --- $child[num]$

而他想知道，在这$m$小时内，他能复习的**最大价值系数和**为多少

## 输入格式

输入最多有 $2n+1$ 行。

第一行有两个数，分别为：
知识点总数 $n$ 与 复习时间 $m$（中间用空格隔开）

此后将依编号逐个表示 $n$ 个知识点：

该知识点的第1行有3个数，分别为：

该点复习时间 $u$ ，该点价值系数 $v$ ，该点指向的点的个数 $num$
（中间用空格隔开）

该知识点的第2行有 $num$ 个数，为该点指向的点的编号（中间用空格隔开）

值得注意的是，当 $num=0$ 时，将没有第二行

## 输出格式

共一行，一个数，即最大价值系数和。

## 样例 #1

### 样例输入 #1

```
6 10
1 1 2
2 3
2 3 2
4 5
3 4 2
5 6
4 6 0
6 6 0
7 10 0
```

### 样例输出 #1

```
11
```

## 提示

样例解释如图：
![](https://cdn.luogu.com.cn/upload/image_hosting/4j9ts101.png)

在100%的数据中，$0 < n,num \le 10000$ ； $u$ 始终大于零而 $v$ 可能小于0.

所有数均不超过int范围.

**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 10010;
ll n, m;
ll cost[MAXN], weight[MAXN];
vector<ll> graph[MAXN];
ll ans = 0;
bool flag[MAXN];
void dfs(ll u, ll curc, ll curw) {
  if (curc > m)
    return;
  else
    ans = max(ans, curw);
  for (auto v : graph[u]) {
    dfs(v, curc + cost[v], curw + weight[v]);
  }
}
int main() {
  ll k, tmp;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> cost[i] >> weight[i] >> k;
    for (int j = 1; j <= k; ++j) {
      cin >> tmp;
      graph[i].emplace_back(tmp);
      flag[tmp] = true;
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!flag[i])
      dfs(i, cost[i], weight[i]);
  cout << ans << endl;
  return 0;
}
