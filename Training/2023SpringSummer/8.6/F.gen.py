from cyaron import *
import random

title = "F"
prefix = f"data/{title}/{title}"

for i in range(1, 21):
    io = IO(file_prefix=prefix, data_id=i)
    s = [chr(i + ord("A")) for i in range(26)]
    random.shuffle(s)
    io.input_writeln("".join(s))
    random.shuffle(s)
    io.input_writeln("".join(s))
    io.output_gen(f"python ./{title}.py")
