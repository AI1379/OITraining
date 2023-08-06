from cyaron import *

idx = 1
while True:
    io = IO()
    n = randint(5, 15)
    m = randint(5, 10)
    t = Graph.tree(n)
    io.input_writeln(n, m)
    io.input_writeln(t.to_str(output=lambda x: "%d %d" % (x.start, x.end)))
    val = [randint(1, 15) for _ in range(n)]
    io.input_writeln(val)
    lst = []
    for _ in range(m):
        x = randint(1, 2)
        if x == 1:
            lst.append([x, randint(1, n), randint(0, 15)])
            io.input_writeln(lst[len(lst) - 1])
        else:
            lst.append([x, randint(1, n), randint(1, n), randint(0, 15)])
            io.input_writeln(lst[len(lst) - 1])
    print("testing...", idx)
    try:
        Compare.program(
            "./P4592.o", input=io, std_program="./P4592-std.o", max_workers=1
        )
    except Exception as e:
        print(n, m)
        for i in val:
            print(i, end=" ")
        print("")
        print(t.to_str(output=lambda x: "%d %d" % (x.start, x.end)))
        for i in lst:
            print(i)
        print(e)
    idx += 1
    if idx == 100:
        break
