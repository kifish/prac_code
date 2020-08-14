
class Node(object):
    def __init__(self,val):
        self.val = val 
        self.next = None

class List(object):
    def __init__(self):
        self.sentinel = Node(-1)
        self.last = self.sentinel
        self.total = 0
    def insert(self,node):
        self.last.next = node
        self.last = self.last.next 
        self.total += 1
    def print(self):
        cur = self.sentinel.next
        while cur:
            print(cur.val,end=' ')
            cur = cur.next
    def remove(self,idx):
        cnt = -1
        cur = self.sentinel
        while cur:
            if cnt == idx-1:
                remove_node = cur.next
                cur.next = remove_node.next
                remove_node.next = None
                self.total -= 1
                break
            else:
                cur = cur.next
                cnt += 1
    def get(self,idx):
        cnt = -1
        cur = self.sentinel
        while cur:
            if cnt == idx-1:
                the_node = cur.next
                if the_node: # 判断空链表
                    return the_node.val
                break 
            else:
                cur = cur.next
                cnt += 1
        return None 

    def reverse(self):
        pre = None
        cur = next = self.sentinel.next
        while cur and cur.next: # cur (判断是否是空链表) and ... 
            next = cur.next

            cur.next = pre 
            pre = cur 
            cur = next 
        if cur: #判断是否是空链表 
            cur.next = pre
        self.sentinel.next = cur 

    def size(self):
        return self.total
         



if __name__ == '__main__':
    L = List()
    for i in range(5):
        L.insert(Node(i))
    L.print()
    L.remove(2)
    print()
    L.print()
    L.reverse()
    print()
    L.print()
    print()
    print(L.get(0))
    print(L.get(3))
    print(L.get(4))
    print(L.size())


