



def bubble_sort(arr):
    a = arr.copy()
    n = len(a)
    for i in range(n-1):  # i 为每轮冒泡最远终点的索引,经过该轮循环后,a[:i+1] == sorted_final[:i+1]
        swapped = False
        for j in range(n-1, i, -1):
            if a[j] < a[j-1]:
                a[j-1],a[j] = a[j],a[j-1]
                swapped = True 
        if not swapped:
            break
    return a



def select_sort(arr):
    a = arr.copy()
    n = len(a)
    for i in range(n-1):  # 经过该轮循环后,a[:i+1] == sorted_final[:i+1]
        min = a[i]
        min_idx = i
        for j in range(i+1,n):
            if a[j] < min:
                min_idx = j 
                min = a[j]
        a[i],a[min_idx] = a[min_idx],a[i]
    return a 


"""
选择排序维护的是一个已排序集合，(该集合只保证递增,并不保证a[:i+1] == sorted_final[:i+1],注意这里的循环不变量和bubble_sort,select_sort不同)
每次选择下一个元素插入到 已排序集合。
从后往前找位置，右边的往右移 让出位置。

"""       
def insert_sort(arr):
    a = arr.copy()
    n = len(a)
    for j in range(1,n):
        insert_val = a[j]
        i = j -1
        while i >= 0 and a[i] > insert_val:
            a[i+1] = a[i]
            i -= 1
        a[i+1] = insert_val
    return a 

"""
插入排序有点类似冒泡.插入排序和冒泡排序的区别是?
每次循环,插入排序是选下一个元素,然后插入到已排序序列(可能是内部).插入排序是n-1次插入的结果.
冒泡排序永远是选最后一个元素,因此两者起始位置不一样,然后比较到已排序序列(边缘),不需要到已排序队列[:-1]里面比,因此两者终点位置也不一样.冒泡排序是n-1次冒泡的结果.


插入排序更适用于部分有序的数组,shell排序是基于此的改进.当然子排序法也可以换成冒泡排序等其他排序.
假设最小的元素在序列最后,那么最小的元素需要比较n-1次之后,才能到正确的位置(队首),shell排序增大了比较和交换的间隔,相当于较少了turtle元素的比较
次数.
"""
def shell_sort(arr):
    a = arr.copy()
    n = len(a)
    h = 1
    while h < int(n/3):
        h = 3*h + 1
    # h <= 3*(int(n/3)-1) + 1 <= n -2

    while h >= 1:
        for i in range(h,n):
            # 分别对每个子序列进行一次排序
            # insert_sort
            # 但这里只做了一次插入排序,效果相当于分别对每个子序列进行一次插入排序
            j = i 
            while j>=h and a[j] < a[j-h]:
                a[j-h],a[j] = a[j],a[j-h]
                j -= h 
        h = int(h/3)
    return a 

# h也可以认为是比较间隔,插入排序相当于h=1

def shell_sort2(arr):
    a = arr.copy()
    n = len(a)
    h = 1
    while h < int(n/3):
        h = 3*h + 1
    while h >= 1:
        sub_arrs = []
        for i in range(h):
            sub_arr = a[i::h]
            sub_arr.sort()
            sub_arrs.append(sub_arr)  
        a.clear()
        for i in range(int(n/h)+1):
            for j in range(h):
                if i < len(sub_arrs[j]):
                    a.append(sub_arrs[j][i])
        h = int(h/3)
    return a


def wrong_shell_sort(arr):
    a = arr.copy()
    n = len(a)
    h = 1
    while h < int(n/3):
        h = 3*h + 1
    # h <= 3*(int(n/3)-1) + 1 <= n -2

    while h >= 1:
        for i in range(n-1, (n-1-h+1)-1,-1):
            j = i
            # 只做了一次遍历,并没有对子序列进行完整的冒泡排序
            # 实际上这次遍历既不是插入也不是冒泡
            while j >= h and a[j] < a[j-h]:
                a[j-h], a[j] = a[j], a[j-h]
                j -= h
            print('iter ',a)
        print('epoch ',a)
        print('---')
        h = int(h/3)
    return a

'''
iter  [3, 6, 1, 10, 1, 2, 8]
iter  [3, 2, 1, 10, 1, 6, 8]
iter  [1, 2, 1, 10, 3, 6, 8]
iter  [1, 2, 1, 10, 3, 6, 8]
epoch  [1, 2, 1, 10, 3, 6, 8]
---
iter  [1, 2, 1, 10, 3, 6, 8]
epoch  [1, 2, 1, 10, 3, 6, 8] # 8 > 6 直接跳出循环
---
'''


def shell_sort3(arr):
    a = arr.copy()
    n = len(a)
    h = 1
    while h < int(n/3):
        h = 3*h + 1
    # h <= 3*(int(n/3)-1) + 1 <= n -2
    while h >= 1:
        for i in range(n-1, (n-1-h+1)-1, -1):
            for j in [i] * int(i/h):  # int(i/h)为冒泡次数
                while j >= h:
                    # 一次冒泡的终点是有序序列的边缘
                    # a[j] < a[j-h]不应放在while上
                    if a[j] < a[j-h]:
                        a[j-h], a[j] = a[j], a[j-h]
                    j -= h
                # print('sub_iter ', a)
            # print('iter ', a)
        # print('epoch ', a)
        # print('---')
        h = int(h/3)
    return a



def shell_sort4(arr):
    a = arr.copy()
    # print(a)
    n = len(a)
    h = 1
    while h < int(n/3):
        h = 3*h + 1
    # h <= 3*(int(n/3)-1) + 1 <= n -2
    while h >= 1:
        for i in range(n-1, (n-1-h+1)-1, -1):
            for _ in range(int(i/h)): # int(i/h)为冒泡次数
                j = i
                while j >= h:
                    # 一次冒泡的终点是有序序列的边缘
                    # a[j] < a[j-h]不应放在while上
                    if a[j] < a[j-h]:
                        a[j-h], a[j] = a[j], a[j-h]
                    j -= h
                # print('sub_iter ', a)
            # print('iter ', a)
        # print('epoch ', a)
        # print('---')
        h = int(h/3)
    return a


def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[int(len(arr)/2)]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x==pivot]
    right = [x for x in arr if x> pivot]
    return quicksort(left)+middle+quicksort(right)

if __name__ == '__main__':
    test = [3,6,8,10,1,2,1]
    print(bubble_sort(test)) 
    print(select_sort(test))
    print(insert_sort(test))
    print(shell_sort(test))
    print(shell_sort2(test))
    print(quicksort(test))
    
