import subprocess
import os
import random as rd
import copy

title = "wanderer"
num = 20
cmd = ["python", "./T5-sol.py"]
# cmd = ["./T5-sol.o"]

letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"


def gen(id, f):
    if id <= int(0.5*num):
        n = rd.randint(10, 100)
    else:
        n = rd.randint(100, 49000)
    m = rd.randint(1, n)
    print(n, m, file=f)
    x = rd.sample(range(1, 10*n), n+1)
    x = sorted(x)
    for i in x:
        print(i, end=" ", file=f)
    print('', file=f)


for i in range(1, num+1):
    if not os.path.exists(f"data/{title}"):
        os.mkdir(f"data/{title}")
    infile_name = f"data/{title}/{title}{i}.in"
    outfile_name = f"data/{title}/{title}{i}.out"
    infile = open(infile_name, "w+")
    outfile = open(outfile_name, "w+")
    gen(i, infile)
    infile.seek(0)
    subprocess.run(cmd, stdin=infile, stdout=outfile)
    infile.close()
    outfile.close()
