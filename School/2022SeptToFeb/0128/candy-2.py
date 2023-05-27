def pos(i):
    return (i % n+n) % n


n = int(input())
a = [int(x) for x in input().split()]
ans = [0 for i in range(n)]
p = sorted([(a[i], i) for i in range(n)])

for i in range(n):
    if a[pos(p[i][1]-1)] == a[p[i][1]] and a[pos(p[i][1]+1)] == a[p[i][1]]:
        ans[p[i][1]] = 1
    elif a[pos(p[i][1]-1)] == a[p[i][1]]:
        ans[p[i][1]] = ans[pos(p[i][1]+1)]+1
    elif a[pos(p[i][1]+1)] == a[p[i][1]]:
        ans[p[i][1]] = ans[pos(p[i][1]-1)]+1
    else:
        ans[p[i][1]] = max(ans[pos(p[i][1]-1)], ans[pos(p[i][1]+1)])+1

s = sum(ans)
print(s)
