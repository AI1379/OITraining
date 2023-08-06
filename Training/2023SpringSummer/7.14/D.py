s = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]
d = [int(x) for x in input().split()]


def dfs(lis, cur, l, r):
    if cur == len(lis):
        return max(l, r)
    return min(dfs(lis, cur + 1, l + lis[cur], r), dfs(lis, cur + 1, l, r + lis[cur]))


r1, r2, r3, r4 = dfs(a, 0, 0, 0), dfs(b, 0, 0, 0), dfs(c, 0, 0, 0), dfs(d, 0, 0, 0)
ans = r1 + r2 + r3 + r4
print(r1, r2, r3, r4)

print(ans)



