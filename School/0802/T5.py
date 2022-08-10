n = int(input())
MOD = 10007
if n % 2 == 0:
    a = (n / 2 - 1) * (n / 2) * (n / 2 + 1) / 6
    b = (n / 2) * (n / 2 + 1) * (n / 2 + 2)
    c = (n / 2 + 1) * (n / 2 + 2) * (n / 2 + 3) / 6
    a = (a + b + c) % MOD
    b = (b + c) % MOD
    for i in range(1, n//2 + 1):
        if i <= (n//2 - 2):
            print(a)
        elif i == n//2 - 1:
            print(b)
        else:
            print(c)
else:
    b = ((n - 3) / 2 + 1) * ((n - 3) / 2 + 2) * ((n - 3) / 2 + 3) / 6 * 4
    c = ((n - 1) / 2 + 1) * ((n - 1) / 2 + 2) * ((n - 1) / 2 + 3) / 6 * 4
    b = (b + c) % MOD
    for i in range(1, n//2 + 1):
        if i <= ((n - 3)//2):
            print(b)
        else:
            print(c)
