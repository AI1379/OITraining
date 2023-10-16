from random import *

MOD = 1000000007


def qpow(a, b):
    global MOD
    res = 1
    while b:
        if b & 1:
            res = res * a % MOD
        a = a * a % MOD
        b >>= 1
    return res


for i in range(1, 10000):
    a, b, m, n = 1, 1, 3, 100000
    f1, f2 = 1, 1
    ans1, ans2 = 0, 0
    for _ in range(3, n + 1):
        f1, f2 = f2, a * f1 + b * f2
    # print(f2)
    # print(f2 % (MOD - 1))
    ans1 = qpow(m, f2)
    f1, f2 = 1, 1
    for _ in range(3, n + 1):
        f1, f2 = f2, (a * f1 % (MOD - 1) + b * f2 % (MOD - 1)) % (MOD - 1)
    ans2 = qpow(m, f2)
    # print(f2)
    if ans1 != ans2:
        print(a, b, m, n)
        # print(ans1, ans2)
        break
    print(ans1, ans2)
    break
    a, b, m, n = randint(1, 1000), randint(1, 1000), randint(1, 1000), randint(1, 1000)
    if i % 100 == 0:
        print("check", i)
