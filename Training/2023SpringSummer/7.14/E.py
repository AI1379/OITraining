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
