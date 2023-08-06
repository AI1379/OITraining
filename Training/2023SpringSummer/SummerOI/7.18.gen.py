from cyaron import *


def det(a, b, c, d):
    return a * d - b * c


def getab(x1, y1, x2, y2):
    d = det(x1 * x1, y1 * y1, x2 * x2, y2 * y2)
    d1 = det(x1 * x1 * y1 * y1, y1 * y1, x2 * x2 * y2 * y2, y2 * y2)
    d2 = det(x1 * x1, x1 * x1 * y1 * y1, x2 * x2, x2 * x2 * y2 * y2)
    return d1 / d, d2 / d


idx = 1
name = "data/equ/equ"

eps = 1e-9

while idx < 20:
    io = IO(file_prefix=name, data_id=idx)
    a, b = 0, 0
    x1, y1, x2, y2 = 0, 0, 0, 0
    while abs(a - int(a)) > eps or a <= 0 or abs(b - int(b)) > eps or b <= 0:
        x1 = randint(4, 100)
        y1 = randint(4, 100)
        x2 = randint(4, 100)
        y2 = randint(4, 100)
        if det(x1 * x1, y1 * y1, x2 * x2, y2 * y2) != 0:
            a, b = getab(x1, y1, x2, y2)
        print("gen...")
    io.input_writeln(int(a), int(b))
    io.output_gen("./7.18.o")
    idx += 1
