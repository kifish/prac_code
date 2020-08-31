最佳二叉排序树，初始化时比较简单的，见 http://www.math.pku.edu.cn/teachers/qiuzy/ds_python/courseware/DS7-dict-2.pdf

```PY
""" Dictionary and searching 
"""

from BiTree1 import BiTNode, print_BiTNodes
from Assoc import Assoc
from DictBTree import DictBTree

inf = float("inf")

class DictOptBTree(DictBTree):
    def __init__(self, seq):
        DictBTree.__init__(self)
        data = sorted(seq)
        self._root = DictOptBTree.buildOBT(data, 0, len(data)-1)

    @staticmethod
    def buildOBT(data, start, end):
        if start > end: return None
        mid = (end + start)//2
        left = DictOptBTree.buildOBT(data, start, mid-1)
        right = DictOptBTree.buildOBT(data, mid+1, end)
        return BiTNode(Assoc(*data[mid]), left, right)

def build_opt_btree(wp, wq):
    """ Assume wp is a list of n values representing weights of
internal nodes, wq is a list of n+1 values representing
weights of n+1 external nodes. This function builds the
optimal binary searching tree from wp and wq.
"""
    num = len(wp)+1
    if len(wq) != num:
        raise ValueError("Arguments of build_opt_btree are wrong.")
    w = [[0 for i in range(num)] for j in range(num)]
    c = [[0 for i in range(num)] for j in range(num)]
    r = [[0 for i in range(num)] for j in range(num)]
    for i in range(num):   # 璁＄畻鎵€鏈夌殑 w[i][j]
        w[i][i] = wq[i]
        for j in range(i+1, num):
            w[i][j] = w[i][j-1] + wp[j-1] + wq[j]
    for i in range(0, num-1): # Set trees with only one node
        c[i][i+1] = w[i][i+1]
        r[i][i+1] = i

    for m in range(2, num):
        # 绠� m 涓唴閮ㄧ粨鐐圭殑鏈€浣虫爲锛坣鈥搈+1妫碉級
        for i in range(0, num-m):
            k0, j = i, i+m
            wmin = inf
            for k in range(i, j):
                # 鍦╗i,j)閲屾壘浣緾[i][k]+C[k+1][j]鏈€灏忕殑k
                if c[i][k] + c[k+1][j] < wmin:
                    wmin = c[i][k] + c[k+1][j]
                    k0 = k
            c[i][j] = w[i][j] + wmin
            r[i][j] = k0

    return (c, r)

if __name__ == '__main__':
    from random import randint

    wp = [5, 1, 2]
    wq = [4, 3, 1, 1]

    trees = build_opt_btree(wp, wq)

    print(trees[0])
    print(trees[1])

    wp = [5, 1, 2, 6, 8, 10]
    wq = [4, 3, 3, 1, 6, 12, 9]

    trees = build_opt_btree(wp, wq)

    print(trees[0])
    print(trees[1])

##    "Result:"
##    [[0, 12, 23, 35, 66, 112, 167],
##     [0,  0,  7, 16, 38,  80, 130],
##     [0,  0,  0,  6, 24,  62, 112],
##     [0,  0,  0,  0, 13,  46,  96],
##     [0,  0,  0,  0,  0,  26,  71],
##     [0,  0,  0,  0,  0,   0,  31],
##     [0,  0,  0,  0,  0,   0,   0]]
##    
##    [[0, 0, 0, 0, 3, 3, 4],
##     [0, 0, 1, 1, 3, 4, 4],
##     [0, 0, 0, 2, 3, 4, 4],
##     [0, 0, 0, 0, 3, 4, 4],
##     [0, 0, 0, 0, 0, 4, 5],
##     [0, 0, 0, 0, 0, 0, 5],
##     [0, 0, 0, 0, 0, 0, 0]]    

```

动态更新比较困难，AVL树是最佳二叉排序树的近似，但是性能是在同一数量级的。


```py
""" Dictionary and searching 
"""

from BiTree1 import BiTNode, print_BiTNodes
from SStack import *
from Assoc import Assoc
from DictBTree import DictBTree

class AVLNode(BiTNode):
    def __init__(self, data):
        BiTNode.__init__(self, data)
        self.bf = 0        

class DictAVL(DictBTree):
    def __init__(self):
        self._root = None

    @staticmethod
    def LL(a, b):
        a.left = b.right
        b.right = a
        a.bf = b.bf = 0
        return b

    @staticmethod
    def RR(a, b):
        a.right = b.left
        b.left = a
        a.bf = b.bf = 0
        return b

    @staticmethod
    def LR(a, b):
        c = b.right
        a.left, b.right = c.right, c.left 
        c.left, c.right = b, a
        if c.bf == 0:   # c 
            a.bf = b.bf = 0 
        elif c.bf == 1: #
            a.bf = -1; b.bf = 0 
        else:           # 
            a.bf = 0; b.bf = 1
        c.bf = 0;
        return c;

    def RL(a, b):
        c = b.left
        a.right, b.left = c.left, c.right
        c.left, c.right = a, b
        if c.bf == 0: # c 
            a.bf = 0;  b.bf = 0 
        elif c.bf == 1:  # 
            a.bf = 0; b.bf = -1
        else:         # 
            a.bf = 1;  b.bf = 0
        c.bf = 0 
        return c

    def insert(self, key, value):
        a = p = self._root
        if a is None:
            self._root = AVLNode(Assoc(key, value)); return
        pa = q = None # 
        while p is not None: # 
            if key == p.data.key: # key
                p.data.value = value; return    
            if p.bf != 0: pa, a = q, p # 
            q = p
            if key < p.data.key: p = p.left
            else: p = p.right
        # q 
        node = AVLNode(Assoc(key, value))
        if key < q.data.key: q.left = node  #         
        else: q.right = node                #  
        # 
        if key < a.data.key: #
            p = b = a.left; d = 1
        else:                #
            p = b = a.right; d = -1 # 
        # 
        while p != node:     # node 
            if key < p.data.key:   # p 
                p.bf = 1;  p = p.left
            else:                  # p
                p.bf = -1;  p = p.right
        if a.bf == 0: a.bf = d; return # a
        if a.bf == -d: a.bf = 0; return # 
        # 
        if d == 1:       # 
            if b.bf == 1: b = DictAVL.LL(a, b)  # LL 
            else: b = DictAVL.LR(a, b)          # LR 
        else:            #
            if b.bf == -1: b = DictAVL.RR(a, b) # RR
            else: b = DictAVL.RL(a, b)          # RL

        if pa is None: self._root = b    # 
        else:
            if pa.left == a: pa.left = b
            else: pa.right = b
    
    def delete(self, key):
        return

    def print(self):
        for entry in self.inorder():
            print(entry.key, entry.value)

    def depth(self):
        def depth0(t):
            if t is None: return 0
            return max(depth0(t.left),
                       depth0(t.right)) + 1
        return depth0(self._root)
        
# END class

def build_AVLTree(entries):
    dic = DictAVL()
    for k, v in entries:
        dic.insert(k, v)
    return dic

def build_random_AVL(n):
    dic = DictAVL()
    for i in range(n):
        dic.insert(randint(1,n*2), randint(1,100))
    return dic

if __name__ == '__main__':
    from random import randint
    
##    dic1 = build_random_AVL(20)
##    for entry in dic1.inorder():
##        print(entry.key, entry.value)

    dic2 = DictAVL()
    for i in range(15): # 15 entries with increasing keys
        dic2.insert(i, i*i)
    print(dic2.depth())
    for entry in dic2.inorder():
        print(entry.key, entry.value)

##    dic3 = build_random_AVL(1000)
##    print(dic3.depth())
##
##    dic4 = DictAVL()
##    for i in range(1000): # 1000 entries with increasing keys
##        dic4.insert(i, i*i)
##    print(dic4.depth())
    

    pass
        
    

```
