

from collections import deque


class BST():

    class Node():
        def __init__(self, key=-1,val = -1):
            self.key = key
            self.val = val 
            self.left = None
            self.right = None
            # count of subtrees 
            # self.count = ?

        def __str__(self):
            return str(self.key)

    def __init__(self):
        self.root = None
    # put
    def insert(self, key, val):
        """
        如果是相同的key，且发生了替换掉value，则会出现问题：简单的self.times配合排序就有问题了。
        """
        self.root = self.insert_(self.root, key, val)

    def insert_(self, parent_node, key, val):
        """
        由于需要排序，因此相同的数值也需要保留。
        """
        if parent_node == None:
            return self.Node(key,val)

        if key < parent_node.key:
            parent_node.left = self.insert_(parent_node.left, key,val)
        elif key > parent_node.key:
            parent_node.right = self.insert_(parent_node.right, key, val)
        else:
            parent_node.val = val 

        return parent_node
    # get 
    def search(self, key):
        cur = self.root
        while cur:
            if key < cur.key:
                cur = cur.left
            elif key > cur.key:
                cur = cur.right
            else:
                return cur.val 
        raise KeyError
    def delete(self,key):
        pass 


    # 也可以用yield 来实现 java中iterable
    def show(self):
        # 层序遍历
        q = deque()
        if self.root:
            q.append(self.root)
        while q:
            cur = q.popleft()
            for _ in range(cur.times):
                print(cur.key, end=' ')
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
            则处理cur.key (相等于 局部的根)
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
                    res.append(cur.key)
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
