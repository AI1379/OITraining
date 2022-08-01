ans = 0
f = open("高二技术.txt",encoding='utf-8')
# 去掉第一行
f.readline()
for line in f.readlines():
    if int(line.split()[-1]) >= 95:
        ans += 1
print(ans)
