from cyaron import *
import random
import time

title = "F"
prefix = f"data/{title}/{title}"
for i in range(1, 21):
    io = IO(file_prefix=prefix, data_id=i)
    n, q = 0, 0
    if i <= 2:
        n, q = 10, 10
    elif i <= 10:
        n, q = randint(5, 100), randint(10, 1000)
    else:
        n, q = randint(100, 500), randint(1000, 100000)
    lis = [randint(10, 100000) for _ in range(n * n)]
    lis = sorted(lis, reverse=True)
    l, r = n // 5, n * 4 // 5
    tab = lis[l:r]
    query = []
    for _ in range(q):
        if randint(0, 1):
            query.append(random.choice(tab))
        else:
            query.append(random.choice(lis))
    random.shuffle(lis)
    io.input_writeln(n, q)
    for j in range(n):
        for k in range(n):
            io.input_write(lis[j * n + k], " ")
        io.input_write("\n")
    for k in query:
        io.input_writeln(k)
    t1 = time.perf_counter()
    io.output_gen("python ./F-2.py")
    t2 = time.perf_counter()
    print(t2 - t1)
