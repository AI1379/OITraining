def fact(x):
    res = 1
    for i in range(1,x+1):
        res *= i
    return res

n = int(input())
res = 0
for i in range(1,n+1):
    res += fact(i)
print(res)