# A

略

# B

先判定回不回文再判定素数即可

也可以筛法求素数之后判断回文

关于为什么偶数位回文数只有11是素数：容易证明偶数位的回文数必然是11的倍数

# C

这题本意是想二分

先sort，从小往大扫，遇到每一个数`lis[i]`，二分两次，一次找**第一个`lis[i]+c`**，一次找**最后一个`lis[i]+c`**。或者说，一次找**第一个大于等于`lis[i]+c`的**，一次找**第一个大于`lis[i]+c`的**，然后做一个差加到答案上即可。

代码：

```python
n, c = map(int, input().split())
s = sorted([int(x) for x in input().split()])


def find1(p, x):
    l = p + 1
    r = len(s) - 1
    ans = len(s)
    while l <= r:
        mid = (l + r) // 2
        if s[mid] >= x:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    return ans


def find2(p, x):
    l = p + 1
    r = len(s) - 1
    ans = len(s)
    while l <= r:
        mid = (l + r) // 2
        if s[mid] > x:
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    return ans


ans = 0
for i in range(len(s)):
    ans += find2(i, s[i] + c) - find1(i, s[i] + c)

print(ans)
```

但是事实上有个更好的做法：

开一个`1000000`的列表`t`，`t[i]`表示`i`这个数在`lis`中出现的次数，然后每次加上`t[lis[i]+c]`即可。

```python
n, c = map(int, input().split())
lis = [int(x) for x in input().split()]
ans = 0
t = [0 for _ in 1000010]
for i in range(n):
    t[lis[i]] += 1
for i in range(n):
    ans += t[lis[i] + c]
print(ans)
```

# D

**真的不是贪心！！！**

> 反例：`5 14 10 12 7`
>
> 如果贪心的话会认为一边`22`一边`26`
>
> 但是事实上`14`和`10`放在一起是一个更优的解

所以这个题其实是要深搜。

剩下的就是板子了

```python
s = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]
d = [int(x) for x in input().split()]


# l表示当前左半边大小 r表示当前右半边大小
def dfs(lis, cur, l, r):
    # 到头了 返回左右两边较大的
    if cur == len(lis):
        return max(l, r)
    # 否则 考虑当前这一个放在左边还是右边
    # 左边就l+lis[cur] 右边就r+lis[cur]
    return min(dfs(lis, cur + 1, l + lis[cur], r), dfs(lis, cur + 1, l, r + lis[cur]))


r1, r2, r3, r4 = dfs(a, 0, 0, 0), dfs(b, 0, 0, 0), dfs(c, 0, 0, 0), dfs(d, 0, 0, 0)
ans = r1 + r2 + r3 + r4
print(r1, r2, r3, r4)

print(ans)
```

# E

树上问题。依然深搜即可

搜的时候记录每一个点的深度，然后记录每个深度的点数即可

```python
n = int(input())
tree = [[] for _ in range(n)]
tot = [0 for _ in range(n)]
for i in range(n - 1):
    u, v = map(int, input().split())
    tree[u - 1].append(v - 1)
    tree[v - 1].append(u - 1)
depth = 0


def dfs(u, fa, dep):
    global x, y, depth, l
    tot[dep - 1] += 1
    depth = max(depth, dep)
    for v in tree[u]:
        if v == fa:
            continue
        dfs(v, u, dep + 1)


dfs(0, -1, 1)

print(depth)
print(max(tot))
```

# F

**这题才是真的贪心！！**

由于这个题的物品可以分割，所以不是01背包问题，而是一个典型的贪心

把每个物品按照性价比降序排序即可

```python
n, t = map(int, input().split())
lis = [[0, 0, 0] for _ in range(n)]
for i in range(n):
    lis[i][0], lis[i][1] = map(int, input().split())
    lis[i][2] = lis[i][1] / lis[i][0]
# 按性价比降序排序
# 当然也可以手写冒泡
lis.sort(key=lambda x: x[2], reverse=True)
ans = 0
idx = 0
while t > 0:
    ans += lis[idx][2] * min(t, lis[idx][0])
    t -= min(t, lis[idx][0])
    idx += 1
print("%.2f" % ans)

```
