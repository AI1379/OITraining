# pb_ds食用教程

> 平板电视：比STL还STL
> 
> ——来自luogu某佬

## Intro 前言

`pb_ds`的主体部分在`__gnu_pb_ds`命名空间下，使用前需要`using namespace __gnu_pbds`

> WARNING: NOIP评测的时候可能不允许使用`using namespace __gnu_pbds`。

头文件如下：

```cpp
#include <ext/pb_ds/assoc_container.hpp> // 各种类的定义 必须引用
#include <ext/pb_ds/tree_policy.hpp> // tree
#include <ext/pb_ds/hash_policy.hpp> // hash
#include <ext/pb_ds/trie_policy.hpp> // trie
#include <ext/pb_ds/priority_queue.hpp> // priority_queue
```

或者

```cpp
#include <bits/extc++.h>
// 类似bits/stdc++.h
// 据称这个文件在dev-c++里面会报找不到文件 因此建议上面的写法
```

**WARNING: pb_ds是以libstdc++为标准库的编译器中专属的库 仅gcc可用**

为什么要`pb_ds`？

它封装了可并堆，字典树，平衡树等一堆常用且难搞的东西，极大程度减少码量，甚至可能可以降低时间复杂度。

而且，就算不敢在正经的提交文件中使用pbds，我们也可以用它来进行对拍。

## hash 哈希表

## trie 字典树

## tree 平衡树

平衡树的实现有三个：`rb_tree_tag`，`splay_tree_tag`和`ov_tree_tag`。**除了红黑树都不建议使用，除非是一道Splay维护区间的问题而又不会写Splay。**

模板参数如下：

```cpp
template <
    typename Key, 
    typename Mapped,
    typename Cmp_Fn = std::less<Key>,
    typename Tag = rb_tree_tag,
    template <
        typename Node_CItr,
        typename Node_Itr,
        typename Cmp_Fn_,
        typename _Alloc_ >
    class Node_Update = null_node_update,
    typename Alloc = std::allocator<char> >
class tree;
```

其中：

+ `Key`是键类型，也就是平衡树中存储的类型

+ `Mapped`映射类型，通常为`null_type`表示无映射

+ `Cmp_Fn`比较函数

+ `Tag`实现方式

+ `Node_Update`节点更新方式 通常使用`tree_order_statistics_node_update`

+ `Alloc`内存分配器

其中`Node_Update`是pbds tree最重要的一部分，也是自定义pbds平衡树行为的最重要的手段

### RB-Tree 红黑树

红黑树的基本原理超出了我们的范围。我们所需要知道的只是：这是一种跑的飞快且非常难写的平衡二叉树。

平衡树的用途通常比较固定（除了Splay），一般就这么几种：

1. 插入一个数

2. 删除一个数

3. 查询一个数的排名

4. 查询排名为k的数

5. 求一个数的前驱后继

[【模板】普通平衡树](https://www.luogu.com.cn/problem/P3369)

代码：

```cpp
// https://www.luogu.com.cn/problem/P3369
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll INF = 1ll << (sizeof(ll) * 8 - 2);
__gnu_pbds::tree<pll, __gnu_pbds::null_type, std::less<pll>,
                 __gnu_pbds::rb_tree_tag,
                 __gnu_pbds::tree_order_statistics_node_update>
    rbt;
ll n;
int main() {
  ll opt, k;
  decltype(rbt)::point_iterator ptr;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> opt >> k;
    switch (opt) {
    case 1:
      rbt.insert(make_pair(k, i));
      break;
    case 2:
      rbt.erase(rbt.lower_bound(make_pair(k, 0)));
      break;
    case 3:
      cout << rbt.order_of_key(make_pair(k, 0)) + 1 << endl;
      break;
    case 4:
      cout << (rbt.find_by_order(k - 1)->first) << endl;
      break;
    case 5:
      ptr = rbt.lower_bound(make_pair(k, 0));
      --ptr;
      cout << (ptr->first) << endl;
      break;
    case 6:
      ptr = rbt.upper_bound(make_pair(k, INF));
      cout << (ptr->first) << endl;
      break;
    }
  }
  return 0;
}
```

### Node_Update的实现

> WARNING: 前方需要大量C++高级知识 看不懂可以暂时跳过

首先我们要知道：`Node_Update`是`tree`的公有基类。也就是说，`Node_Update`中的所有成员方法都会在`tree`中公开。`Node_Update`是这样的一个模板类：

```cpp
template <
    typename Node_CItr,
    typename Node_Itr,
    typename Cmp_Fn_,
    typename _Alloc_ >
class Node_Update;
```



## priority_queue 堆

> 注意：如果用`__gnu_pbds::priority_queue`那么建议不要引用万能头或者`using namespace std`以免与`std::priority_queue`发生冲突导致CE。

### 前置知识：如何自定义`priority_queue`的排序方式

~~其实这个前置知识并不会影响pbds堆的使用~~

我们都知道，对于一个结构体，我们不能直接把它丢进`priority_queue`，无论是STL还是pbds。那么我们有两种方案：重载小于号，或者写一个**仿函数 functor**

仿函数听着玄乎，其实很简单，只是一个重载了括号运算符的结构体而已。

比方说，众所周知，有个东西叫`std::less`，它其实就是一个仿函数，实现也很简单：

```cpp
template<typename T>
struct less{
    bool operator()(const T& lhs,const T& rhs){
        return lhs<rhs;
    }
};
```

那么，我们同样也可以自己写一个`comp`，用来比较，就像这样：

```cpp
struct comp{
    bool operator()(int x, int y){
        return dis[x] > dis[y];
    }    
};
```

使用的时候则这么用：

```cpp
std::priority_queue<int,std::vector<int>,comp> q;
```

于是就可以得到堆里面装了数组下标，以下标对应的`dis`值为关键字的小根堆

~~是不是非常简单~~

### 模板参数 & 成员函数

```cpp
template<
    typename ValueType,
    typename Comp = std::less<ValueType>,
    typename Tag = pairing_heap_tag,
    typename Alloc = std::allocator<char>>
class priority_queue;
```

其中：

+ `ValueType`是堆里面的元素类型

+ `Comp`是比较器，是一个functor。注意pbds的堆和STL一样 传入less会得到大根堆

+ `Tag`是堆的实现，总共有以下几种：
  
  + `pairing_heap_tag` 配对堆 最有用
  
  + `binary_heap_tag` 二叉堆
  
  + `binomial_heap_tag` 二项堆
  
  + `rc_binomial_heap_tag` 冗余计数二项堆
  
  + `thin_heap_tag` Tarjan老爷子发明的一种 除了合并以外复杂度都和Fibonacci堆一样的一种堆

+ `Alloc`是空间分配器，不用管他，省略即可 

除了`pairing_heap_tag`以外，其他四个在OI中都不如`std::pirority_queue`。配对堆不仅优于STL的二叉堆，同时也优于`algorithm`头文件中的`make_heap`系列函数。因此，如果不做说明，下文所指的pbds堆都指配对堆。

五种tag都支持以下的操作：

+ `push` 压入一个元素

+ `pop` 弹出一个元素

+ `top` 获得堆顶

+ `size` 获得大小

+ `empty` 获得是否为空

+ `modify` 修改某一个位置的元素 并且重新调整结构

+ `erase` 删除某一个位置的元素

+ `join` 合并两个堆

### 复杂度

|                        | push                                | pop                                 | modify                                                         | erase                               | join              |
| ---------------------- | ----------------------------------- | ----------------------------------- | -------------------------------------------------------------- | ----------------------------------- | ----------------- |
| `std::priority_queue`  | 最坏$\Theta(n)$均摊$\Theta(\log n)$     | $\Theta(\log n)$                    | $\Theta(n\log n)$                                              | $\Theta(n\log n)$                   | $\Theta(n\log n)$ |
| `pairing_heap_tag`     | $O(1)$                              | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$                            | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | $O(1)$            |
| `binary_heap_tag`      | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | $\Theta(n)$                                                    | $\Theta(n)$                         | $\Theta(n)$       |
| `binomial_heap_tag`    | 最坏 $\Theta(\log(n))$ 均摊 $O(1)$      | $\Theta(\log(n))$                   | $\Theta(\log(n))$                                              | $\Theta(\log(n))$                   | $\Theta(\log(n))$ |
| `rc_binomial_heap_tag` | $O(1)$                              | $\Theta(\log(n))$                   | $\Theta(\log(n))$                                              | $\Theta(\log(n))$                   | $\Theta(\log(n))$ |
| `thin_heap_tag`        | $O(1)$                              | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | 最坏 $\Theta(\log(n))$ 均摊 $O(1)$或者$\Theta(\log n)$ 这取决于修改是增加还是减少 | 最坏 $\Theta(n)$ 均摊 $\Theta(\log(n))$ | $\Theta(n)$       |

### 应用

#### Dijkstra & Prim

![SPFA](D:\Projects\OITraining\Templates\pb_ds\SPFA.jpg)

OI中堆最常见的应用之一就是图论里最短路和最小生成树。

我们知道，对于非负权图的最短路，有两大经典算法：Dijkstra和~~已死的~~SPFA。其中，`std::priority_queue`优化的Dijkstra复杂度是$\Theta(m\log m)$的，而手搓堆和线段树则是$\Theta(m\log n)$，对于Fibonacci堆则是吓人的$\Theta(m+n\log n)$。对于很稠密的图来说，我们有$m=O(n^2)$，此时dijkstra的常数会涨得飞快，而在考场上手搓Fib堆又并不现实，因此我们需要一种简单的方式对dijkstra进一步提速。

同样，面对最小生成树，我们也有一样的问题：Kruskal在稠密图上的表现不尽人意，而单独`std::priority_queue`优化的Prim算法复杂度和Kruskal相同，常数还更大，因此面对稠密图我们需要更快的最小生成树算法，典型例子就是[Moo Network G](https://www.luogu.com.cn/problem/P8191)。

>  **WARINING: 事实上，如果pbds堆优化dij是标算的一部分，那么它不应该给出`std::priority_queue`不能通过的测试点。因此，pbds堆优化更多可以看作是一种从标算不是最短路但是可以用最短路解的问题中骗分的方式。**

> GCC认为`thin_heap_tag`在Dijkstra上表现会优于`pairing_heap_tag`，并且单从复杂度分析它也确实更优（等同于Fib堆），但是由于常数比较大，实测下来它的性能并没有配对堆优秀。

那么为什么pbds堆会比STL堆跑的快呢？究其原因有两点：

1. pbds堆支持`modify`操作

2. pbds堆`modify`操作时，如果堆中元素是减少的，那么复杂度是$o(\log n)$的（注意这里不是上确界）。事实上配对堆的`modify`复杂度在学术界还无法给出精确解~~（就连Tarjan老爷子都没算出来）~~。目前认为的下界是$\Omega(\log\log n)$，上界是$O(2^{\sqrt{\log\log n}})$。

事实上，Fib堆跑dijkstra和prim快的原因也在于此：Fib堆中元素减小时修改的复杂度是$\Theta(1)$的，这也是为什么`thin_heap_tag`有更优的理论复杂度。而dijkstra和prim中，每次松弛后，dis显然是减小的。

> 有一个很奇怪的事情，pbds的dij在luogu P4779里比stl堆快得多，但是我本机benchmark测无论是随机图还是网格套菊花两者速度都不相上下，开O2后STL堆甚至远远快过了手打堆和线段树。个人猜测是由于配对堆常数较大以及pbds堆底层数据结构内存不连续导致的

代码:

```cpp
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
constexpr const ll MAXN = 100010;
constexpr const ll INF = 1ll << (sizeof(ll) * 8 - 2);
static ll n, m, s;
static ll dis[MAXN];
vector<pll> graph[MAXN];
__gnu_pbds::priority_queue<pll, greater<pll>> q;
decltype(q)::point_iterator its[MAXN];
void dijkstra() {
  ll u, v, d;
  for (int i = 1; i <= n; i++) {
    dis[i] = INF;
  }
  dis[s] = 0;
  for (int i = 1; i <= n; i++) {
    its[i] = q.push(make_pair(dis[i], i));
  }
  while (!q.empty()) {
    u = q.top().second;
    q.pop();
    for (pll obj : graph[u]) {
      v = obj.first;
      d = obj.second;
      if (dis[v] > dis[u] + d) {
        dis[v] = dis[u] + d;
        q.modify(its[v], make_pair(dis[u] + d, v));
      }
    }
  }
}
int main() {
  ll u, v, w;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
  }
  dijkstra();
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << ' ';
  }
  cout << endl;
  return 0;
}
```

#### 可并堆

相比起优化dijkstra和prim，pbds堆在这一方面应用更广——毕竟STL中并没有数据结构能直接实现可并堆，而配对堆和左偏树都不是很好写。

**注意：`a.join(b)`后，`b`这个堆中的元素将会被清空。**

[【模板】左偏树（可并堆）](https://www.luogu.com.cn/problem/P3377)

可并堆可以解决很多类型的问题，比如某些树上问题。这些题目一般是一个节点维护一个堆，然后儿子的堆不断向父亲合并，过程中进行计算。这些题虽然常常有省选及以上的难度，但主要原因在于可并堆并不好实现。另外，可并堆通常会与并查集一块出现（比如上面的模板题）

### 例题

- [P2713 罗马游戏](https://www.luogu.com.cn/problem/P2713)
- [P1456 Monkey King](https://www.luogu.com.cn/problem/P1456)
- [P1552 [APIO2012]派遣](https://www.luogu.com.cn/problem/P1552)
- [P3261 [JLOI2015]城池攻占](https://www.luogu.com.cn/problem/P3261)
- [P3273 [SCOI2011]棘手的操作](https://www.luogu.com.cn/problem/P3273)
- [P4331 [BOI2004]Sequence](https://www.luogu.com.cn/problem/P4331)
