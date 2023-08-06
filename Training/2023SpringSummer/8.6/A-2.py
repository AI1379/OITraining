t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    x, y = 0, 0
    while a or b:
        if a % 2 == 1 and b % 2 == 0:
            x = 1
        if a % 2 == 0 and b % 2 == 1:
            y = 1
        a //= 2
        b //= 2
        if x and y:
            break
    print(x + y)
