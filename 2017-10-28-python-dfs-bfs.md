---
tags: [python,algs]
---


#1
```python
# here is a list of edges:
T = [('Bob','Eve'),('Alice','Carol'),('Eve','Frank'),('Alice','Doug'),('Frank','Ginger'), \
         ('Eve','Howard'),('Carol','Irene'),('Frank','Jeff'),('Doug','Kathy'),('Bob','Luis'), \
         ('Alice','Bob'),('Bob','Mabel'),('Ginger','Norm'),('Howard','Oprah'),('Carol','Peter'), \
         ('Kathy','Queen'),('Mabel','Ursala'),('Luis','Ronald'),('Ginger','Sarah'),('Irene','Tom'), \
         ('Jeff','Vince'),('Peter','Wanda'),('Oprah','Xanthia'),('Norm','Yaakov'),('Luis','Zandra')]

print ('T has',len(T),'edges')
vertices = set()
for edge in T:
    s,t = edge
    vertices.add(s)
    vertices.add(t)
print ('T has',len(vertices),'vertices')
```
#2
So this could be a tree. Now lets compute the number of parents for each vertex. The result confirms that we indeed have a tree and that the root is Alice (right?).   
```python
np = {}
for v in vertices:
    np[v] = 0
for parent,child in T:
    np[child] += 1
print (np)
```

Yes.

We now construct a dictionary of pairs (p,c) where p is the parent of the list of children c


#3   

```python
adjacency_map = {}
for v in vertices:
    adjacency_map[v] = []
for p,c in T:
    adjacency_map[p].append(c)

print ("node and children:")
for p in adjacency_map:
    print (p, ":", adjacency_map[p])

print ()
print (adjacency_map)
```

`print (5*"Hello!")`


#4

做DFS,相当于树的前序遍历,python写起来相当简洁.DFS是遇到深度更深的节点立马去执行, 而不是像BFS一样拖着,加入队列,直到无法同层遍历时才选择深入(层序遍历).

```python

# A recursive Depth-First traversal of a tree defined by an adjacency_map
def print_tree_depth_first(parent, adjacency_map, level=0):
    print (level*'  ', parent)
    children = adjacency_map[parent]
    for child in children:
        print_tree_depth_first(child, adjacency_map, level+1)

root = 'Alice'
print_tree_depth_first(root, adjacency_map)
```


BFS
```python
from collections import deque

# breadth-first traversal using a queue
def print_tree_breath_first(root, adjacency_map):
    Q = deque()
    Q.append(root)
    while len(Q)>0:
        p = Q.popleft()
        print (p)
        children = adjacency_map[p]
        for child in children:
            Q.append(child)

print_tree_breath_first("Alice", adjacency_map)

```

修改成如下打印格式:

1: Alice
2: Carol Doug Bob
3: ...

代码如下:

通过比较当前层总共的节点个数与当前层已经输出的总节点数,来判断是否深度要加+1.


```python
from collections import deque

# breadth-first traversal using a queue
def print_tree_breath_first(root, adjacency_map):
    Q = deque()
    Q.append(root)
    level = 1
    cnt = 1
    nextcnt = 0
    curfirst = 1
    while len(Q)>0:
        p = Q.popleft()
        cnt-=1
        if(curfirst==1):
            print(level,':',p,end=' ')
            curfirst=0
        else:
            print(p,end=' ')
        children = adjacency_map[p]
        for child in children:    #for循环要在if之前,这样当层最后一个节点遍历到后才能顺利衔接下一层
            Q.append(child)
            nextcnt += 1
        if(cnt==0):
            level += 1
            cnt = nextcnt
            nextcnt = 0
            curfirst = 1
            print()
print_tree_breath_first("Alice", adjacency_map)
```


#遇到一些问题，运行单个例子是对的，多个例子运行就不对了.id[]相当于C里的全局数组，但是多个例子运行时没有考虑重新初始化。 python里的list情况，L = []这样是无效的，应该L[:] = [] 或者del L[:]

可以参考这篇博客：http://blog.csdn.net/lujiandong1/article/details/48808627




```python


id = []
def find(x):
    if(id[x]==x):
        return x
    else:
        tmp = find(id[x])
        id[x] = tmp
        return tmp

def isconnected(p,q):
    root_p = find(p)
    root_q =find(q)
    if(root_p==root_q):
        return True
    else:
        return False

def all_connected_to(edge_list, root):
    """ return true if you can reach all nodes in the graph given
    by a list of edges (edge_list) can be reached by root """

    # start by constructing set of vertices and a dictionary for looking up children
    vertices = set()
    for edge in edge_list:
        s, t = edge
        vertices.add(s)
        vertices.add(t)

    node_to_num = {}
    pos = 0
    for vertex in vertices:
        node_to_num[vertex] = pos
        pos += 1

    id[:] = []
    for index in range(0, pos):
        id.append(index)  # mistake: id[index] = index  (list assignment index out of range)
    for edge in edge_list:
        s, t = edge
        p = node_to_num[s]
        q = node_to_num[t]
        if not isconnected(p, q):
            root_p = find(p)
            root_q = find(q)
            id[root_p] = root_q
    print("start")
    for vertex in vertices:
        print('vertex name:[{}] id:[{}] root: [{}]'.format(vertex,node_to_num[vertex],id[node_to_num[vertex]]))
    print("end")
    for vertex in vertices:
        if not isconnected(node_to_num[vertex], node_to_num[root]):
            return False

    return True


print("case 1 :")
G = [("A","B"), ("B","C")]
print (all_connected_to(G, "A"))

print("case 2 :")
G2 = [("1","2"), ("A","B"), ("B","C"), ("C","A")]
print (all_connected_to(G2, "A"))

print("case 3 :")
print (all_connected_to(G2, "1"))

print("case 4 :")
G3 = [("A","B"), ("B","C"), ("C","A")]
print (all_connected_to(G3, "C"))
#and our graph from above?

print("case 5 :")
T = [('Bob','Eve'),('Alice','Carol'),('Eve','Frank'),('Alice','Doug'),('Frank','Ginger'), \
         ('Eve','Howard'),('Carol','Irene'),('Frank','Jeff'),('Doug','Kathy'),('Bob','Luis'), \
         ('Alice','Bob'),('Bob','Mabel'),('Ginger','Norm'),('Howard','Oprah'),('Carol','Peter'), \
         ('Kathy','Queen'),('Mabel','Ursala'),('Luis','Ronald'),('Ginger','Sarah'),('Irene','Tom'), \
         ('Jeff','Vince'),('Peter','Wanda'),('Oprah','Xanthia'),('Norm','Yaakov'),('Luis','Zandra')]
print (all_connected_to(T, "Alice"))
```

 字典里的list用append，可能和string混在一起会出问题，因为string不可变。可用如下方法：

 ```python
 # -*- coding: utf-8 -*-
 from collections import  deque
 # here is a list of edges:
 T = [('Bob','Eve'),('Alice','Carol'),('Eve','Frank'),('Alice','Doug'),('Frank','Ginger'), \
          ('Eve','Howard'),('Carol','Irene'),('Frank','Jeff'),('Doug','Kathy'),('Bob','Luis'), \
          ('Alice','Bob'),('Bob','Mabel'),('Ginger','Norm'),('Howard','Oprah'),('Carol','Peter'), \
          ('Kathy','Queen'),('Mabel','Ursala'),('Luis','Ronald'),('Ginger','Sarah'),('Irene','Tom'), \
          ('Jeff','Vince'),('Peter','Wanda'),('Oprah','Xanthia'),('Norm','Yaakov'),('Luis','Zandra')]

 print ('T has',len(T),'edges')
 vertices = set()
 for edge in T:
     s,t = edge
     vertices.add(s)
     vertices.add(t)
 print ('T has',len(vertices),'vertices')

 root = 'Bob'

 # construct adjacency for graph T:
 adjacency_map = {}

 for vertex in vertices:
     adjacency_map[vertex] = []
 for edge in T:
     s, t = edge
     adjacency_map[s].append(t)       # 看成无向图/双向图，后面的while循环会进入死循环，因为无法保证每个节点只入队一次了
     adjacency_map[t].append(s)

 print ("parents/children of Ginger:", adjacency_map['Ginger'])  # 直接相邻的节点
 print (adjacency_map)

 singledirec_adjacency_map = {}
 for vertex in vertices:
     singledirec_adjacency_map[vertex] = []
 for edge in T:
     s, t = edge
     singledirec_adjacency_map[s].append(t)       # 看成无向图/双向图，后面的while循环会进入死循环，因为无法保证每个节点只入队一次了


 # now create tree as a dictionary "n maps to children(n)"
 # 把tree 变成 adjacency_map
 tree = {}

 Q = deque()
 Q.append(root)

 while len(Q) > 0:
     p = Q.popleft()
     for adjacency_node in singledirec_adjacency_map[p]:
         Q.append(adjacency_node)
         if p in tree:
             tree[p].append(adjacency_node)
             #tree.setdefault('p', []).append(adjacency_node)
         else:
             tree[p] = [adjacency_node]
         if adjacency_node in tree:
             tree[adjacency_node].append(p)
             #tree.setdefault('adjacency_node', []).append(p)
         else:
             tree[adjacency_node] = [p]

         '''  
         use the queue!
         #每一个节点都要遍历
         '''
 print()
 print (tree)

 print("BFS:")
 def print_tree_breath_first(root, adjacency_map):
     Q = deque()
     Q.append(root)
     while len(Q)>0:
         p = Q.popleft()
         print (p)
         children = adjacency_map[p]
         for child in children:
             Q.append(child)

 print_tree_breath_first(root, singledirec_adjacency_map)

 print("DFS:")

 def print_tree_depth_first(parent, adjacency_map, level=0):
     print (level*'  ', parent)
     children = adjacency_map[parent]
     for child in children:
         print_tree_depth_first(child, adjacency_map, level+1)

 print_tree_depth_first(root, singledirec_adjacency_map)
 ```
