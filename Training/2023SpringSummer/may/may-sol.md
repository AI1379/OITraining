# 五一欢乐赛 题解

## T1

> [ICPC 2022 亚洲区域赛 杭州站 F题](https://codeforces.com/gym/104090/problem/F)
>
> ~~当然还是略有改动的~~

`find` 或者 `in` 即可。

注意忽略大小写。

```python
n = int(input())
ans = []
flag = False
for i in range(n):
    m = int(input())
    flag = False
    for j in range(m):
        s = input()
        if s.lower().find("liyue") != -1:
            ans.append(s)
            flag = True
    if not flag:
        ans.append("Time to play Genius Invokation TCG!")
for s in ans:
    print(s)
```

## T2

这个东西在密码学里其实很有名，叫CBC模式。不过真正的CBC模式中间还会有一层加密流程，这里把它省略掉了。这里的 $e_0$ 在密码学中被称作初始化向量（IV），有些地方也叫Salt（就是盐）。

当然，CBC模式的加密因为不利于并行计算而且安全性较低，现在在工业上已经被淘汰了。

~~但是再怎么说也比凯撒之类的安全得多罢。~~

```python
def decode(d: int, cipher: str):
    plain = ""
    tmp = d
    for i in range(0, len(cipher), 2):
        plain += chr(int(cipher[i:i+2], 16) ^ tmp)
        tmp = int(cipher[i:i+2], 16)
    return plain

print(decode(int(input()), input()))
```

## T3

贪心。

要使消耗体力最大，显然是从当前能跳的最高的跳到最低的。排序然后扫一遍即可。

```python
n = int(input())
h = [0] + sorted([int(x) for x in input().split()])
p, q = n, 0
ans = 0
while q < p:
    ans += (h[q]-h[p])**2
    q += 1
    ans += (h[q]-h[p])**2
    p -= 1

print(ans)
```

## T4

在树上双指针深搜即可。

我们定义一个函数 `dfs(u,v)` 表示判断**以 `u` 为根的子树 翻转后是否与以 `v` 为根的子树相同**， 于是最终要做的就是求 `dfs(root,root)`。

然后就是怎么写的问题。深搜的基本思想就是递归，就是**处理好自己，然后用一样的方式处理自己的孩子**。那么我们也分两部分考虑。

对于 `u v` 两个点，只要两点的权值相等即可。

然后就是处理孩子们。我们发现， `dfs(u,v)` 如果为真，说明 `u` 的左儿子与 `v` 的右儿子翻转后相同，并且 `u` 的右儿子与 `v` 的左儿子翻转后相同。

那么我们只要在 `dfs` 里判断这三个条件即可。

接下来还有一个递归出口的问题。容易发现，如果 `u == v == 0` 则一定成立，因此把这个作为递归出口即可。

```python
tr = [(0, 0, 0)]
n = int(input())
fa = [0]*(n+1)
for i in range(n):
    tr.append(tuple([int(x) for x in input().split()]))

for i in range(1, n+1):
    fa[tr[i][0]] = i
    fa[tr[i][1]] = i

rt = 0
for i in range(1, n+1):
    if fa[i] == 0:
        rt = i
        break


def dfs(p: int, q: int):
    if p == 0 and q == 0:
        return True
    return tr[p][2] == tr[q][2] and dfs(tr[p][0], tr[q][1]) and dfs(tr[p][1], tr[q][0])


if dfs(rt, rt):
    print("YES")
else:
    print("NO")
```

### update

后来发现还有一个做法

众所周知，通过先序遍历和中序遍历可以确定一颗二叉树。

那么只要把原树的先序和中序求出来，然后交换左右儿子，再求一边先序和中序，比较是否相同即可。

（代码略）

## T5

[「NOIP 2015 提高组」 跳石头](https://www.luogu.com.cn/problem/P2678)

带了一点点贪心的二分答案。

求最小值最大之类的问题，我们首先应当想到的就是二分答案。二分答案，基本的思想就是，**把最值问题变成判定问题**。

以这个题为例。本题枚举显然是不行的，所以考虑二分。由于 `n` 块石头的位置是确定的，所以可能的答案是在一个有限的区间里的，这种情况下就可以考虑二分。这个二分与二分查找不同，**它不是在给定的序列上二分，而是在答案的区间里二分**。

二分首先得找单调性。我们容易发现，当最小值逐渐增大时，所需要的去掉的石头数量是在不断增加的。那么我们就考虑，**二分最终的最小值，然后贪心求至少去掉的石头个数**。于是，我们的问题就从求最小值的最大值，变成了**判定一个最小值是否可行**。

然后就是在二分的同时考虑贪心。我们从前往后扫，同时开一个变量 `tmp` 记录当前的位置。当扫到 `i` 时，我们判断第 `i` 块与当前的距离是否小于 `mid`，如果小于，则与二分时的最小值为mid矛盾，于是就得把 `i` 去掉，然后记录去掉的石头总数。扫完一遍后，判断需要去掉的石头是否小于 `m` 即可。注意要扫到 `n+1`。

代码

```python
n, m = map(int, input().split())
val = [int(x) for x in input().split()]


def check(x: int):
    tmp = 0
    p = 0
    for i in val:
        if i-tmp < x:
            p += 1
        else:
            tmp = i
    return p <= m


l = 1
r = val[n]
ans = 0
while l <= r:
    mid = (l+r)//2
    if check(mid):
        ans = mid
        l = mid + 1
    else:
        r = mid - 1

print(ans)
```

## T6

[「NOIP 1999 普及组」导弹拦截](https://www.luogu.com.cn/problem/P1020)

经典最长上升子序列（LIS）问题。

首先，我们定义 `f[i]` 为**第 `i` 位为结尾**的LIS的长度。我们从前往后扫过来一位一位求 `f[i]` 的值，那么枚举的想法是显然的：对于第 `i` 位，因为前 `i-1` 位的对应值已经求好了，那么只要扫一遍前 `i-1` 位，先判断对应的 `v[j]` 是否小于 `v[i]` ，如果小于，就打擂求 `f[j]` 的最大值，这样 `f[i]` 就是 `f[j]` 的最大值再加一。

但是这样的时间复杂度是 $O(n^2)$ 的。

这个时候我们考虑二分。定义 `d[i]` 为**要达到 `i` 的长度，对应的 `v[i]` 至少要大于 `d[i]`**。显然，`d[i]` 是不下降的。那么我们要找的就是，**`d[i]` 中的最后一个最后一个小于 `v[i]` 的位置**。注意，二分得到 `f[i]` 的时候，还得要进行更新

> 关于 `d[i]` 不下降的证明：
>
> 假设对于 `d[i]` ，存在 `j > i` 并且 `d[j] < d[i]`，

```python
n = int(input())
v = [int(x) for x in input().split()]
f = [0]*n
d = [0x3fffffff]*(n+1)
d[1] = 0


def find(x: int):
    l = 1
    r = n
    ans = -1
    while l <= r:
        mid = (l+r)//2
        if d[mid] < x:
            ans = mid
            l = mid+1
        else:
            r = mid-1
    return ans


for i in range(n):
    f[i] = find(v[i])
    d[f[i]+1] = v[i]

print(max(f))

```
