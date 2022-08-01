f = open("高二技术.txt", encoding='utf-8')
f.readline()
count = dict.fromkeys(range(1, 13), 0)
classes = []
names = []
score = []
for line in f.readlines():
    x = line.split()
    if int(x[3]) > 95:
        classes.append(x[0])
        names.append(x[2])
        score.append(int(x[3]))
        count[int(x[0][x[0].find('（')+1:x[0].find('）')])] += 1
print(classes)
print(names)
print(score)
for i in range(1, 13):
    print(count[i], end=' ')
