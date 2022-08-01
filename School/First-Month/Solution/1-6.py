x = int(input())
if x >= 10000:
    x -= 2000
elif x >= 5000:
    x -= 1000
elif x >= 1000:
    x -= 100

if x >= 1000:
    x *= 0.8
elif x >= 5000:
    x *= 0.9
elif x >= 1000:
    x *= 0.95

val = x // 100 * 5
x -= val
print(x)
