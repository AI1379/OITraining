def isprime(p):
    d = 2
    while d * d <= p:
        if p % d == 0:
            return False
        d += 1
    return True


def count(p):
    res = 0
    while p:
        res += 1
        p //= 10
    return res


def ispalin(p):
    return str(p) == str(p)[::-1]


a, b = map(int, input().split())

for i in range(a, b + 1):
    if i % 2 == 0 or count(i) % 2 == 0 and i != 11:
        continue
    elif not ispalin(i):
        continue
    elif not isprime(i):
        continue
    print(i)
