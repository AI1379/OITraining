import cyaron
import time

prefix = "data/E/e"
for i in range(1, 21):
    io = cyaron.IO(file_prefix=prefix, data_id=i)
    n = cyaron.randint(1, 100)
    tree = cyaron.Graph.binary_tree(n)
    io.input_writeln(n)
    io.input_writeln(tree.to_str(output=lambda x: "%d %d" % (x.start, x.end)))
    t1 = time.perf_counter()
    io.output_gen("python ./E.py")
    t2 = time.perf_counter()
    print(t2 - t1)
