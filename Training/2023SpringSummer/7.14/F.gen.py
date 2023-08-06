import cyaron
import time

prefix = "data/F/f"
for i in range(1, 21):
    io = cyaron.IO(file_prefix=prefix, data_id=i)
    n = cyaron.randint(1, 1000)
    t = cyaron.randint(1, 1000)
    io.input_writeln(n, t)
    for _ in range(n):
        io.input_writeln(cyaron.randint(1, 1000), cyaron.randint(1, 1000))
    t1 = time.perf_counter()
    io.output_gen("python ./F.py")
    t2 = time.perf_counter()
    print(t2 - t1)
