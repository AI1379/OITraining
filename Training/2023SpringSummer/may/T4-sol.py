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
