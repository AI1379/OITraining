import subprocess
import os
import random
import copy

title = "sumeru"
num = 20
cmd = ["python", "./T4-sol.py"]

letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"


class TreeNode:
    def __init__(self, value=None, id=None):
        self.v = value
        self.id = id
        self.l, self.r = None, None
        self.f = None

    def p(self, f):
        print(self.l.id if self.l else 0,
              self.r.id if self.r else 0,
              self.v,
              file=f)


def build_tree(n):
    assert n > 1
    import random as rd
    all_nodes = [[0, TreeNode(rd.randint(1, 10000), i+1)]
                 for i in range(n)]
    in_nodes = [i for i in range(n)]
    out_nodes = [i for i in range(n)]
    uf = [i for i in range(n)]

    def uf_find(x):
        return x if x == uf[x] else uf_find(uf[x])

    def uf_union(i, j):
        if rd.random() > 0.5:
            i, j = j, i
        uf[uf_find(i)] = uf_find(j)

    while len(in_nodes) > 1:
        fa_id = out_nodes[rd.randint(0, len(out_nodes) - 1)]
        ch_id = in_nodes[rd.randint(0, len(in_nodes) - 1)]

        if uf_find(fa_id) == uf_find(ch_id):
            continue

        fa, ch = all_nodes[fa_id], all_nodes[ch_id]

        if fa[0] == 0:
            if rd.random() > 0.5:
                fa[1].l = ch[1]
            else:
                fa[1].r = ch[1]
            fa[0] += 1
        elif fa[0] == 1:
            if fa[1].l:
                fa[1].r = ch[1]
            elif fa[1].r:
                fa[1].l = ch[1]
            out_nodes.remove(fa_id)

        ch[1].f = fa[1]
        uf_union(fa_id, ch_id)

        in_nodes.remove(ch_id)

    root = all_nodes[in_nodes[0]][1]
    nodes = map(lambda nd: nd[1], filter(
        lambda x: x[1] != root, all_nodes))
    return [root] + list(nodes)


def gen(id, f):
    t = random.choice([True, False])
    n = 0
    if id <= int(0.6*num):
        n = random.randint(10, 500)
    else:
        n = random.randint(500, 10000)
    import operator
    if t:
        half = build_tree(n//2-1)
        half_sym = copy.deepcopy(half)
        for i in half_sym:
            i.id += n//2-1
            i.l, i.r = i.r, i.l
        x = TreeNode(random.randint(1, 10000), 2*(n//2-1)+1)
        x.l, x.r = half[0], half_sym[0]
        res = [x] + half + half_sym
        res.sort(key=operator.attrgetter("id"))
        print(len(res), file=f)
        for i in res:
            i.p(f)
    else:
        res = build_tree(n)
        res.sort(key=operator.attrgetter("id"))
        print(len(res), file=f)
        for i in res:
            i.p(f)


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
