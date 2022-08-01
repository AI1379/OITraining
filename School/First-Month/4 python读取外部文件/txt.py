f=open("高二技术.txt")    #必须先打开
for line in f.readlines():   #f.readlines()表示txt中的所有行
    print(line[-4:-2])

f.close()