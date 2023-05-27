import subprocess
import os
import random as rd
import copy

title = "surreal"
num = 20
cmd = ["python", "./T6-sol.py"]

letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"


def gen(id, f):
    if id <= int(0.6*num):
        n = rd.randint(10, 3000)
    else:
        n = rd.randint(3000, 99000)
    print(n, file=f)
    for i in range(n):
        print(rd.choice(range(1, n+1)), end=" ", file=f)
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
