```py
class LNode :
    def __init__(self, elm, nxt):
        self.elem = elm
        self.next = nxt

if __name__ == '__main__':
    llist1 = LNode(1, None)
    pnode = llist1

    for i in range(2, 11):
        pnode.next = LNode(i, None)
        pnode = pnode.next

    pnode = llist1
    while pnode != None:
        print(pnode.elem)
        pnode = pnode.next
```

```py
from LNode import LNode

class LList:
    def __init__(self):
        self.head = None
        
    def isEmpty(self):
        return self.head is None
    
    def prepend(self, elem):
        self.head = LNode(elem, self.head)
        
    def pop(self):
        if self.head is None:
            raise ValueError
        e = self.head.elem
        self.head = self.head.next
        return e
    
    def append(self, elem):
        if self.head is None:
            self.head = LNode(elem, None)
            return
        p = self.head
        while p.next is not None:
            p = p.next
        p.next = LNode(elem, None)

    def poplast(self):
        if self.head is None: # empty list
            raise ValueError
        p = self.head
        if p.next is None: # list with only one element
            e = p.elem; self.head = None
            return e
        while p.next.next is not None: # till p.next be last node
            p = p.next
        e = p.next.elem; p.next = None
        return e
    
    def find(self, pred):
        p = self.head
        while p is not None:
            if pred(p.elem):
                return p.elem
            p = p.next
        return None
    
    def printall(self):
        p = self.head
        while p is not None:
            print(p.elem)
            p = p.next

if __name__ == '__main__':
    mlist1 = LList()

    for i in range(10):
        mlist1.prepend(i)

    for i in range(11, 20):
        mlist1.append(i)

    mlist1.printall()
```

```py
from LNode import LNode
from LList import LList

class LList1(LList):
    def __init__(self):
        LList.__init__(self)
        self.rear = None
        
    def prepend(self, elem):
        self.head = LNode(elem, self.head)
        if self.rear is None: # empty list
            self.rear = self.head
            
    def append(self, elem):
        if self.rear is None: # empty list
            self.prepend(elem)
        else:
            self.rear.next = LNode(elem, None)
            self.rear = self.rear.next
            
    def pop(self):
        if self.head is None:
            raise ValueError
        e = self.head.elem
        if self.rear is self.head: # list with one node
            self.rear = None
        self.head = self.head.next
        return e
    
    def poplast(self):
        return None # to be implemented

if __name__ == '__main__':
    mlist1 = LList1()
    for i in range(10):
        mlist1.prepend(i)
        
    for i in range(11, 20):
        mlist1.append(i)
        
    mlist1.printall()

```


```py
from LNode import LNode

class LCList: # class of Circular Linked List
    def __init__(self):
        self.rear = None
        
    def isEmpty(self):
        return self.rear is None
    
    def prepend(self, elem): # add element in the front end
        p = LNode(elem, None)
        if self.rear is None:
            p.next = p # initiates circle
            self.rear = p
        else:
            p.next = self.rear.next
            self.rear.next = p
            
    def append(self, elem): # add element in the rear end
        self.prepend(elem)
        self.rear = self.rear.next
        
    def pop(self): # pop out head element
        if self.rear is None:
            raise ValueError
        p = self.rear.next
        if self.rear is p:
            self.rear = None
        else:
            self.rear.next = p.next
        return p.elem
    
    def printall(self):
        p = self.rear.next
        while True:
            print(p.elem)
            if p is self.rear:
                break
            p = p.next

if __name__ == '__main__':
    mlist = LCList()
    for i in range(10):
        mlist.prepend(i)
    for i in range(11, 20):
        mlist.append(i)
    #mlist1.printall()

    while not mlist.isEmpty():
        print(mlist.pop())

```


```py
from LNode import LNode
from LList1 import LList1

class LDNode(LNode): # class of Double Linked Nodes
    def __init__(self, prev, elem, nxt):
        LNode.__init__(self, elem, nxt)
        self.prev = prev

class LDList(LList1): # class of Double Linked List
    def __init__(self):
        LList1.__init__(self)
        
    def prepend(self, elem):
        p = LDNode(None, elem, self.head)
        self.head = p
        if self.rear is None: # insert in empty list
            self.rear = p
        else: # otherwise, create the prev reference
            p.next.prev = p
            
    def append(self, elem):
        p = LDNode(self.rear, elem, None)
        self.rear = p
        if self.head is None: # insert in empty list
            self.head = p
        else: # otherwise, create the next reference
            p.prev.next = p
            
    def pop(self):
        if self.head is None:
            raise ValueError
        e = self.head.elem
        self.head = self.head.next
        if self.head is None:
            self.rear = None # it is empty now
        else:
            self.head.prev = None
        return e
    
    def poplast(self):
        if self.head is None:
            raise ValueError
        e = self.rear.elem
        self.rear = self.rear.prev
        if self.rear is None:
            self.head = None # it is empty now
        else:
            self.rear.next = None
        return e

if __name__ == '__main__':
    mlist = LDList()
    for i in range(10):
        mlist.prepend(i)
    for i in range(11, 20):
        mlist.append(i)
    #mlist1.printall()

    while not mlist.isEmpty():
        print(mlist.pop())
        if not mlist.isEmpty():
            print(mlist.poplast())

```


```py
from LNode import LNode

class LList:
    def __init__(self):
        self.head = None
        
    def isEmpty(self):
        return self.head is None
    
    def prepend(self, elem):
        self.head = LNode(elem, self.head)
        
    def pop(self):
        if self.head is None:
            raise ValueError
        e = self.head.elem
        self.head = self.head.next
        return e
    
    def append(self, elem):
        if self.head is None:
            self.head = LNode(elem, None)
            return
        p = self.head
        while p.next is not None:
            p = p.next
        p.next = LNode(elem, None)

    def poplast(self):
        if self.head is None: # empty list
            raise ValueError
        p = self.head
        if p.next is None: # list with only one element
            e = p.elem; self.head = None
            return e
        while p.next.next is not None: # till p.next be last node
            p = p.next
        e = p.next.elem; p.next = None
        return e

    def find(self, pred):
        p = self.head
        while p is not None:
            if pred(p.elem):
                return p.elem
            p = p.next
        return None
    
    def printall(self):
        p = self.head
        while p is not None:
            print(p.elem, end='')
            if p.next is not None:
                print(', ', end='')
            p = p.next
        print('')

    def rev(self):
        p = None
        while self.head is not None:
            q = self.head
            self.head = q.next
            q.next = p
            p = q
        self.head = p

    def sortm(self):
        if self.head is None:
            return
        crt = self.head.next
        while crt is not None:
            x, p = crt.elem, self.head
            while p is not crt and p.elem <= x:
                p = p.next
            while p is not crt:
                y = p.elem
                p.elem = x
                x = y
                p = p.next
            crt.elem = x
            crt = crt.next

    def sort(self):
        if self.head is None:
            return
        last = self.head; crt = last.next
        while crt is not None:
            p = self.head; q = None
            while p is not crt and p.elem <= crt.elem:
                q = p; p = p.next
            if p is crt:
                last = crt
            else:
                last.next = crt.next
                crt.next = p
                if q is None:
                    self.head = crt
                else:
                    q.next = crt
            crt = last.next        
#end of class LList

def listSort(lst) :
    for i in range(1, len(lst)): # seg [0:0] is sorted
        x = lst[i]
        j = i
        while j > 0 and lst[j-1] > x: # moving one by one
            lst[j] = lst[j-1]         # in reversed-order
            j -= 1
        lst[j] = x

import random

if __name__ == '__main__':
    mlist1 = LList()

    for i in range(10):
        mlist1.prepend(i)

    for i in range(11, 20):
        mlist1.append(i)

    mlist1.printall()
    for i in range(5):
        print(mlist1.pop())
        print(mlist1.poplast())

    print('remained:')
    mlist1.printall()
    mlist1.rev()
    print('\nreversed:')
    mlist1.printall()

    mlist1.sort()
    print('\nsorted:')
    mlist1.printall()
    

##    list1 = [random.randint(1, 50) for i in range(20)]
##    print(list1, '\n')
##    listSort(list1)
##    print(list1)
```

```py
from LCList import LCList

def JosephusA(n, k, m):
    people = list(range(1, n+1))
    num, i = 0, k-1
    for num in range(n):
        count = 0
        while count < m:
            if people[i] > 0:
                count += 1
            if count == m:
                print(people[i], end = "")
                people[i] = 0
            i = (i+1) % n
        if num < n-1:
            print(", ", end="")
        else:
            print("")
    return

def JosephusL(n, k, m):
    people = list(range(1, n+1))
    if k < 1 or k > n:
        raise ValueError

    num, i = n, k-1
    for num in range(n, 0, -1):
        i = (i + m-1) % num            
        print(people.pop(i), end = "")
        if num > 1:
            print(", ", end="")
        else:
            print("")
    return

class Josephus(LCList):
    def turn(self, m):
        for i in range(m):
            self.rear = self.rear.next

    def __init__(self, n, k, m):
        LCList.__init__(self)
        for i in range(n):
            self.append(i+1)
        self.turn(k-1)
        while not self.isEmpty():
            self.turn(m-1)
            print(self.pop(), end="")
            if not self.isEmpty():
                print(", ", end="")
            else:
                print("")
# end class Josephus

if __name__ == '__main__':
    s = input("Josephus parameters (n k m): ")
    n, k, m = map(int, s.split()) 
    JosephusA(n, k, m)    
    JosephusL(n, k, m)
    Josephus(n, k, m)
```


```py

def JosephusA(n,k,m):
    people = list(range(1,n+1)) #[1,2,...,n] people[0]为1
    i = k -1
    for iter_times in range(n):
        cnt = 0
        while cnt < m:
            if people[i] > 0:
                cnt += 1
            if cnt == m:
                print(people[i],end = "")
                people[i] = 0
            i = (i+1) % n
        print("," if iter_times < n-1 else "\n", end = "")
JosephusA(10,2,7)
JosephusA(10,1,1)
def JosephusL(n,k,m):
    people = list(range(1,n+1))
    i = k - 1
    for cur_people_num in range(n,0,-1):
        i = (i + m -1) % cur_people_num
        print(people.pop(i),end = "")
        print("," if cur_people_num > 1 else '\n',end = "")

JosephusL(10,2,7)
JosephusL(10,1,1)
```

