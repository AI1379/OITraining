from cyaron import *
import random

title = "D"
prefix = f"data/{title}/{title}"

for i in range(1, 21):
    io = IO(file_prefix=prefix, data_id=i)
    n, x = 0, 0
    if i <= 6:
        n = randint(2, 15)
    elif i <= 12:
        n = randint(15, 50)
    else:
        n = randint(50, 1000)
    a = [j + 1 for j in range(n)]
    random.shuffle(a)
    x = randint(1, 100)
    io.input_writeln(n)
    io.input_writeln(x)
    io.input_writeln(a)
    io.output_gen(f"python ./{title}.py")
