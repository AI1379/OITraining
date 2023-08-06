n, m = int(input()), int(input())
lis = [int(x) for x in input().split()]

flag = False
num = 0
visited = [False for _ in range(n)]


def dfs(cur):
    global flag, num, n, m
    if flag:
        return
    if cur >= n:
        num += 1
        if num == m + 1:
            for i in lis:
                print(i, end=" ")
            print("")
            flag = True
        return
    idx = 0
    while idx < n:
        if num == 0:
            idx = lis[cur] - 1
        if not visited[idx]:
            visited[idx] = True
            lis[cur] = idx + 1
            dfs(cur + 1)
            visited[idx] = False
        idx += 1


dfs(0)
