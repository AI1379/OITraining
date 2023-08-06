from cyaron import *

title = "E"
prefix = f"data/{title}/{title}"

for i in range(1, 21):
    io = IO(file_prefix=prefix, data_id=i)
    n = randint(1, 1000000)
    m = randint(1, n // 10)
    k = randint(n // m + 10, n // m + 100)
    io.input_writeln(n, m, k)
    io.output_gen(f"python ./{title}.py")
