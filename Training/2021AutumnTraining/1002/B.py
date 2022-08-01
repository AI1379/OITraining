def binpow(a, b, m):
    a = a % m
    res = 1
    while b > 0:
        if (b & 1):
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res


m = int(input())
h = int(input())
ans = 0
for i in range(0, h):
    str = input()
    a = int(str.split(' ')[0])
    b = int(str.split(' ')[1])
    ans = (ans + binpow(a, b, m)) % m

print(ans)
