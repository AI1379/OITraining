from cyaron import *

title = "C"
prefix = f"data/{title}/{title}"

for i in range(1, 21):
    io = IO(file_prefix=prefix, data_id=i)
    n, x = 0, 0
    a = []
    n = randint(2, 20)
    a = [randint(1, 100000) for _ in range(n)]
    x = randint(1, n)
    io.input_writeln(n, x)
    io.input_writeln(a)
    io.output_gen(f"python ./{title}.py")
