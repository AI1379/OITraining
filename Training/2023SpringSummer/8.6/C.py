n, k = map(int, input().split())
lis = [int(x) for x in input().split()]
ans = 0


def isprime(x):
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True


def dfs(cur, beg, num):
    global ans
    if num == k:
        if isprime(cur):
            ans += 1
        return
    for i in range(beg, n):
        dfs(cur + lis[i], i + 1, num + 1)


dfs(0, 0, 0)
print(ans)
