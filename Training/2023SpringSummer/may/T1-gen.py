import subprocess
import random
import os

title = "rex"
n = 10
cmd = ["python", "./T1-sol.py"]

letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"


def gen(f):
    n = random.randint(10, 10000)
    maxm = 10000//n
    print(n, file=f)
    for i in range(n):
        m = random.randint(1, maxm)
        print(m, file=f)
        for j in range(m):
            s = random.choices(letters, k=random.randint(5, 300))
            if len(s) < 5:
                continue
            t = random.choice([True, False])
            if t:
                p = random.randint(0, len(s)-5)
                s[p] = "lL"[random.randint(0, 1)]
                s[p+1] = "iI"[random.randint(0, 1)]
                s[p+2] = "yY"[random.randint(0, 1)]
                s[p+3] = "uU"[random.randint(0, 1)]
                s[p+4] = "eE"[random.randint(0, 1)]
            print("".join(s), file=f)


for i in range(1, n+1):
    if not os.path.exists(f"data/{title}"):
        os.mkdir(f"data/{title}")
    infile_name = f"data/{title}/{title}{i}.in"
    outfile_name = f"data/{title}/{title}{i}.out"
    infile = open(infile_name, "w+")
    outfile = open(outfile_name, "w+")
    gen(infile)
    infile.seek(0)
    subprocess.run(cmd, stdin=infile, stdout=outfile)
    infile.close()
    outfile.close()
