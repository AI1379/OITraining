from cyaron import *

title = "A"
prefix = f"data/{title}/{title}"
for i in range(1, 21):
    io = IO(file_prefix=prefix, data_id=i)
    s = String.random(6, charset=ALPHABET_CAPITAL)
    t = String.random(6, charset=ALPHABET_CAPITAL)
    io.input_writeln(s)
    io.input_writeln(t)
    io.output_gen("python ./A.py")
