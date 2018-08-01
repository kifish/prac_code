
class Node(object):
    def __init__(self,val):
        self.val = val 
        self.left = None 
        self.right = None 


"""
二叉排序树，左子树小于等于根，右子树大于等于根。递归建立。
中序遍历即可得不递减序列。


前序遍历  根 左 右
中序遍历  左 根 右
后序遍历  左 右 根

左子树永远先于右子树

"""
class BinaryTree(object):
    def __init__(self,val):
        self.root = Node(val)



    def insert(self,val):
        self.insert_(self.root,val)
    

    '''
    不能写成默认形参 cur = self.root
     def insert(self,val,cur = self.root):
         ...
    但可以使用函数重载?
    python 不能显式支持函数重载
    https://www.zhihu.com/question/20053359/answer/226645438
    '''

    def insert_(self, cur, val):
        if not cur:
            return Node(val) 

        if val < cur.val:
            cur.left = self.insert_(cur.left,val)
        elif val > cur.val:
            cur.right = self.insert_(cur.right,val)
        else:
            pass

    def pre_order(self,cur):
        print(cur.val, end = ' ')
        if cur.left:
            self.pre_order(cur.left)
        elif cur.right:
            self.pre_order(cur.right)
    def in_order(self,cur):
        if cur.left:
            self.in_order(cur.left)
        print(cur.val,end = ' ')
        if cur.right:
            self.in_order(cur.right)
    def post_order(self,cur):
        if cur.left:
            self.post_order(cur.left)
        elif cur.right:
            self.post_order(cur.right)
        print(cur.val,end = ' ')


        

if __name__ == '__main__':
    pass
