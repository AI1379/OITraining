from cyaron import *
import time


title = "A"
prefix = f"data/{title}/{title}"
for i in range(1, 21):
    io = IO(file_prefix=prefix, data_id=i)
    if i <= 6:
        t = randint(10, 100)
        io.input_writeln(t)
        for _ in range(t):
            n, m = randint(1, 100), randint(1, 100)
            io.input_writeln(n, m)
    else:
        t = randint(10000, 80000)
        io.input_writeln(t)
        for _ in range(t):
            n, m = randint(1e6, 1e14), randint(1e6, 1e14)
            x = randint(1, 3)
            if x == 1:
                io.input_writeln(n, m)
            elif x == 2:
                io.input_writeln(n, n | m)
            else:
                io.input_writeln(n, n & m)
    t1 = time.perf_counter()
    io.output_gen("python ./A-2.py")
    t2 = time.perf_counter()
    print(t2 - t1)
