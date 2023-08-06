import cyaron

prefix = "data/B/b"
for i in range(1, 21):
    io = cyaron.IO(file_prefix=prefix, data_id=i)
    a = cyaron.randint(5, 100000)
    b = cyaron.randint(5, 100000)
    a, b = min(a, b), max(a, b)
    io.input_writeln(a, b)
    io.output_gen("python ./B.py")
