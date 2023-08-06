import cyaron
import time

prefix = "data/D/d"
for i in range(1, 21):
    io = cyaron.IO(file_prefix=prefix, data_id=i)
    s = [cyaron.randint(1, 16) for _ in range(4)]
    lis = [[cyaron.randint(1, 54) for _ in range(k)] for k in s]
    io.input_writeln(s)
    for x in lis:
        io.input_writeln(x)
    t1 = time.perf_counter()
    io.output_gen("python ./D.py")
    t2 = time.perf_counter()
    print(t2 - t1)
