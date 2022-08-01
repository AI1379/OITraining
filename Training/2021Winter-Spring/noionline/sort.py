from random import randint
import os

def gen():
    pass

def run():
    while True:
        gen()
        print('.', end='', flush=True)
        cmd1 = 'wa.exe < in.txt'
        cmd2 = 'ac.exe < in.txt'
        ret1 = os.popen(cmd1).read()
        ret2 = os.popen(cmd2).read()
        if ret1 != ret2:
            with open('1.txt', 'w') as f:
                f.write(ret1)
            with open('2.txt', 'w') as f:
                f.write(ret2)
            os.popen('meld 1.txt 2.txt')
            break

if __name__ == '__main__':
    randint()
