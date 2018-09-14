

from collections import deque


class BST():

    class Node():
        def __init__(self, val=-1):
            self.val = val
            self.left = None
            self.right = None
            self.times = 1

        def __str__(self):
            return str(self.val)

    def __init__(self):
        self.root = None

    def insert(self, val):
        self.root = self.insert_(self.root, val)

    def insert_(self, parent_node, val):
        """
        由于需要排序，因此相同的数值也需要保留。
        """
        if parent_node == None:
            return self.Node(val)

        if val < parent_node.val:
            parent_node.left = self.insert_(parent_node.left, val)
        elif val > parent_node.val:
            parent_node.right = self.insert_(parent_node.right, val)
        else:
            parent_node.times += 1

        return parent_node

    def search(self, val):
        cur = self.root
        while cur:
            if val < cur.val:
                cur = cur.left
            elif val > cur.val:
                cur = cur.right
            else:
                return 'found'
        raise KeyError

    def show(self):
        # 层序遍历
        q = deque()
        if self.root:
            q.append(self.root)
        while q:
            cur = q.popleft()
            for _ in range(cur.times):
                print(cur.val, end=' ')
            if cur.left:
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)

    def sorted(self):
        """
        cur.left 有三种情况：
        1. None 不处理
        2. 非None，未operated，
            则把cur.left 加入队列
        3. 非None,operated,
            则处理cur.val (相等于 局部的根)
            并把cur.right 加入队列
        """
        q = deque()
        operated = []
        res = []
        if self.root:
            q.append(self.root)
        while q:
            cur = q[0]
            if cur.left and not (cur.left in operated):
                q.appendleft(cur.left)
            elif (cur.left and cur.left in operated) or not cur.left:
                for _ in range(cur.times):
                    res.append(cur.val)
                operated.append(q.popleft())
                if cur.right:
                    q.appendleft(cur.right)
        return res


if __name__ == '__main__':
    n = input()
    x = list(map(int, input().split()))
    t = BST()
    for item in x:
        t.insert(item)
    res = t.sorted()
    s = ''
    for item in res:
        s += str(item) + ' '
    s.strip()
    print(s)

    # t = BST()
    # a = [1,2,3,4,5,6,7]
    # for num in a:
    #     t.insert(num)
    # for num in a:
    #   t.search(num)

    # t.show()
