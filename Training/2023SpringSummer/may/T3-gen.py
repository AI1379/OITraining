import subprocess
import os
import random as rd
import copy

title = "adventurer"
num = 20
cmd = ["python", "./T3-sol.py"]

letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"


def gen(id, f):
    if id <= int(0.5*num):
        n = rd.randint(10, 300)
    else:
        n = rd.randint(300, 29000)
    print(n, file=f)
    x = rd.sample(range(1, 10*n), n+1)
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
