import cyaron

prefix = "data/A/a"
for i in range(1, 21):
    io = cyaron.IO(file_prefix=prefix, data_id=i)
    n = cyaron.randint(1, 100000)
    s = cyaron.String.random(n, charset=cyaron.ALPHABET + " ")
    io.input_writeln(n)
    io.input_writeln(s)
    io.output_gen("python ./A.py")
