class SegmentTreeNode:
    def __init__(self, l: int, r: int) -> None:
        self.l = l
        self.r = r
        self.lc = self.rc = self.val = self.tag = 0


class SegmentTree:
    def buildTreeImpl(self, orig: list, l: int, r: int) -> int:
        if l == r:
            node = SegmentTreeNode(l, r)
            node.val = orig[l]
            self.buffer.append(node)
            return len(self.buffer)-1
        mid = (l+r)//2
        pos = len(self.buffer)
        node = SegmentTreeNode(l, r)
        self.buffer.append(node)
        self.buffer[pos].lc = self.buildTreeImpl(orig, l, mid)
        self.buffer[pos].rc = self.buildTreeImpl(orig, mid+1, r)
        self.buffer[pos].val = self.buffer[self.buffer[pos].lc].val + \
            self.buffer[self.buffer[pos].rc].val
        return pos

    def __init__(self, orig: list) -> None:
        self.buffer = []
        self.root = self.buildTreeImpl(orig, 0, len(orig)-1)

    def pushdown(self, cur: int) -> None:
        if self.buffer[cur].tag != 0:
            self.buffer[self.buffer[cur].lc].val += self.buffer[cur].tag * \
                (self.buffer[self.buffer[cur].lc].r -
                 self.buffer[self.buffer[cur].lc].l + 1)
            self.buffer[self.buffer[cur].rc].val += self.buffer[cur].tag * \
                (self.buffer[self.buffer[cur].rc].r -
                 self.buffer[self.buffer[cur].rc].l + 1)
            self.buffer[self.buffer[cur].lc].tag += self.buffer[cur].tag
            self.buffer[self.buffer[cur].rc].tag += self.buffer[cur].tag
            self.buffer[cur].tag = 0

    def queryImpl(self, l: int, r: int, cur: int) -> int:
        if l <= self.buffer[cur].l and self.buffer[cur].r <= r:

            return self.buffer[cur].val
        self.pushdown(cur)
        mid = (self.buffer[cur].l + self.buffer[cur].r)//2
        res = 0
        self.pushdown(cur)
        if l <= mid and self.buffer[cur].lc != 0:
            res += self.queryImpl(l, r, self.buffer[cur].lc)
        if mid+1 <= r and self.buffer[cur].rc != 0:
            res += self.queryImpl(l, r, self.buffer[cur].rc)
        return res

    def query(self, l: int, r: int) -> int:
        if l <= r:
            return self.queryImpl(l, r, self.root)
        else:
            return self.queryImpl(r, l, self.root)

    def modifyImpl(self, l: int, r: int, delta: int, cur: int) -> None:
        if l <= self.buffer[cur].l and self.buffer[cur].r <= r:
            self.buffer[cur].val += delta * \
                (self.buffer[cur].r - self.buffer[cur].l+1)
            self.buffer[cur].tag += delta
            return
        mid = (self.buffer[cur].l + self.buffer[cur].r)//2
        self.pushdown(cur)
        if l <= mid and self.buffer[cur].lc != 0:
            self.modifyImpl(l, r, delta, self.buffer[cur].lc)
        if mid+1 <= r and self.buffer[cur].rc != 0:
            self.modifyImpl(l, r, delta, self.buffer[cur].rc)
        self.buffer[cur].val = self.buffer[self.buffer[cur].lc].val + \
            self.buffer[self.buffer[cur].rc].val

    def modify(self, l: int, r: int, delta: int) -> None:
        if l <= r:
            self.modifyImpl(l, r, delta, self.root)
        else:
            self.modifyImpl(r, l, delta, self.root)


n, m = [int(x) for x in input().split()]
orig = [int(x) for x in input().split()]
segt = SegmentTree(orig)

for i in range(m):
    inp = [int(x) for x in input().split()]
    if inp[0] == 1:
        segt.modify(inp[1]-1, inp[2]-1, inp[3])
    else:
        # print(segt.buffer[segt.root].l, segt.buffer[segt.root].r)
        print(segt.query(inp[1]-1, inp[2]-1))
