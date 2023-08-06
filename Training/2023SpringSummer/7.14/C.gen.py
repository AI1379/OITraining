import cyaron
import time

prefix = "data/C/c"
for i in range(1, 21):
    io = cyaron.IO(file_prefix=prefix, data_id=i)
    if i <= 15:
        n = cyaron.randint(5, 2000)
    else:
        n = cyaron.randint(5, 200000)
    c = cyaron.randint(5, 100)
    lis = []
    for i in range(n):
        lis.append(cyaron.randint(5, 10000))
    io.input_writeln(n, c)
    io.input_writeln(lis)
    t1 = time.perf_counter()
    io.output_gen("python ./C.py")
    t2 = time.perf_counter()
    print(t2 - t1)
