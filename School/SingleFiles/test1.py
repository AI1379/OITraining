s = [int(x) for x in input().split()]
for i in range(5):
    s[i-1] += s[i]//3
    s[(i+1) % 5] += s[i]//3
    s[i] //= 3
for i in s:
    print("%5d"%i,end='')