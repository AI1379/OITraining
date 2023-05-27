import subprocess
import os
import random


def tohex(s: int):
    return "0x{:02X}".format(s)


def encode(d: int, plain: str):
    cipher = ""
    tmp = d
    for c in plain:
        # print(tohex(tmp), tohex(ord(c)), tohex(ord(c) ^ tmp))
        tmp = ord(c) ^ tmp
        cipher += "{:02X}".format(tmp)
    return cipher


def decode(d: int, cipher: str):
    plain = ""
    tmp = d
    for i in range(0, len(cipher), 2):
        # print(tohex(tmp), int(cipher[i:i+2], 16), tohex(int(cipher[i:i+2], 16) ^ tmp))
        plain += chr(int(cipher[i:i+2], 16) ^ tmp)
        tmp = int(cipher[i:i+2], 16)
    return plain


title = "faruzan"
n = 10
cmd = ["python", "./T2-sol.py"]

letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"


def gen(f):
    n = random.randint(1, 90000)
    iv = random.randint(0, 255)
    print(iv, file=f)
    p = "".join(random.choices(letters, k=n))
    print(encode(iv, p), file=f)


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
