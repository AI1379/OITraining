from cyaron import *
import time
from random import shuffle

prefix = "data/galaxy/galaxy"
tab = [1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4]
for i in range(1, 21):
    io = IO(file_prefix=prefix, data_id=i)
    t0 = time.perf_counter()
    if i <= 12:
        n = randint(5, 5000)
        val = [randint(10, 1000000000) for _ in range(n)]
        q = []
        if 3 <= i <= 6:
            tr = Graph.chain(n)
            s = tr.to_str(output=lambda x: "1 %d %d" % (x.start, x.end))
            m = randint(n, n + 1000)
            q = [
                [randint(3, 4), randint(1, n), randint(1, n)] for _ in range(m - n + 1)
            ]
            io.input_writeln(n, m)
            io.input_writeln(val)
            io.input_writeln(s)
            for x in q:
                io.input_writeln(x)
        elif 7 <= i <= 12:
            m = randint(1, 6000)
            q = sorted([[choice(tab), randint(1, n), randint(1, n)] for _ in range(m)])
            io.input_writeln(n, m)
            io.input_writeln(val)
            for x in q:
                io.input_writeln(x)
        else:
            m = randint(1, 6000)
            q = [[choice(tab), randint(1, n), randint(1, n)] for _ in range(m)]
            io.input_writeln(n, m)
            io.input_writeln(val)
            for x in q:
                io.input_writeln(x)
    else:
        n = randint(50000, 90000)
        val = [randint(10, 10000000) for _ in range(n)]
        m = randint(n, 100000)
        tr = Graph.tree(n)
        q = tr.to_str(output=lambda x: "1 %d %d" % (x.start, x.end)).split("\n")
        while len(q) < m:
            q.append([randint(2, 4), randint(1, n), randint(1, n)])
        shuffle(q)
        io.input_writeln(n, m)
        io.input_writeln(val)
        for x in q:
            io.input_writeln(x)
    t1 = time.perf_counter()
    io.output_gen("./7.23.o")
    t2 = time.perf_counter()
    print(t1 - t0, t2 - t1)
