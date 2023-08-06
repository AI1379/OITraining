from cyaron import *

title = "B"
prefix = f"data/{title}/{title}"

for i in range(1, 21):
    io = IO(file_prefix=prefix, data_id=i)
    n, x = 0, 0
    a = []
    if i <= 6:
        n = randint(2, 20)
        a = [randint(1, 100) for _ in range(n)]
        x = randint(1, 100)
    elif i <= 14:
        n = randint(100, 1000)
        a = [randint(1, 100000) for _ in range(n)]
        x = randint(1, 100000)
    else:
        n = randint(1000, 100000)
        a = [randint(1, 100000000) for _ in range(n)]
        x = randint(1, 100000000)
    io.input_writeln(n, x)
    io.input_writeln(a)
    io.output_gen(f"python ./{title}.py")
