



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


插入排序更适用于部分有序的数组(若数组中的大部分元素都已经有序,则可以接近O(n)),shell排序是基于此的改进.当然子排序法也可以换成冒泡排序等其他排序.
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


def merge_sort(arr):
    a = arr.copy()
    if len(a) <= 1:
        return a 
    mid = len(a) // 2
    left_part = merge_sort(a[:mid])
    right_part = merge_sort(a[mid:])
    return merge(left_part,right_part)
def merge(left_part,right_part):
    i,j = 0,0
    res = []
    while i < len(left_part) and j < len(right_part):
        if left_part[i] < right_part[j]:
            res.append(left_part[i])
            i += 1
        else:
            res.append(right_part[j])
            j += 1
    if i < len(left_part):
        res += left_part[i:]
    else:
        res += right_part[j:]
    return res 




def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[int(len(arr)/2)]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x==pivot]
    right = [x for x in arr if x> pivot]
    return quicksort(left)+middle+quicksort(right)

def quicksort2(arr):
    a = arr.copy()
    less,pivot_list,more = [],[],[]
    if len(a) <= 1:
        return a
    else:
        pivot = a[0]
        for item in a:
            if item < pivot:
                less.append(item)
            elif item > pivot:
                more.append(item)
            else:
                pivot_list.append(item)
        return quicksort2(less) + pivot_list + quicksort2(more)

def quicksort3(arr):
    if len(arr) <= 1:
        return arr 
    else:
        pivot = arr[0]
        return quicksort3([x for x in arr[1:] if x < pivot]) + [pivot] + quicksort3([x for x in arr[1:] if x >= pivot])



'''
堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。
堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
步骤
1.创建最大堆:将堆所有数据重新排序，使其成为最大堆
2.最大堆调整:作用是保持最大堆的性质，是创建最大堆的核心子程序
3.堆排序:移除位在第一个数据的根节点，并做最大堆调整的递归运算
'''
def heap_sort(arr):
    a = arr.copy()
    # 创建最大堆
    # (len(a)-1)//2 为深度最深的右节点的父节点的索引
    # (len(a)-2)//2 为深度最深的左节点的父节点的索引
    # 两者相等
    # 上浮
    for start in range((len(a)-2)//2,-1,-1):
        sift_down(a,start,len(a)-1)
    
    # 堆排序
    # 用数组模拟树,下标从0开始,a[0]即树的根
    # 模拟每次从堆顶取出最大数并调整堆
    # 下滤
    for end in range(len(a)-1,0,-1):
        a[0],a[end] = a[end],a[0] # 最大的放后面
        sift_down(a,0,end-1) 
    return a
def sift_down(a,start,end):
    parent = start
    while True:
        child = 2*parent + 1
        if child > end:
            break
        # 取两个子节点中value较大的节点的索引
        if child + 1 <= end and a[child] < a[child + 1]:
            child += 1
        # 保证父节点的值大于等于子节点的值
        if a[parent] < a[child]:
            a[parent],a[child] = a[child],a[parent]
            parent = child
        else:
            break


# 计数排序,hash思想
def count_sort(arr):
    a = arr.copy()
    min = 2147483647
    max = 0
    for num in a:
        if num < min:
            min = num 
        if num > max:
            max = num 

    count = [0] * (max-min+1) #分配内存会耗费大量时间
    for num in a:
        count[num-min] += 1
    
    index = 0
    for idx in range(len(count)):
        for _ in range(count[idx]):
            a[index] = idx + min 
            index += 1
    return a 


    


# 以上所有排序都通过oj测试

if __name__ == '__main__':
    test = [3,6,8,10,1,2,1]
    print(bubble_sort(test)) 
    print(select_sort(test))
    print(insert_sort(test))
    print(shell_sort(test))
    print(shell_sort2(test))
    print(merge_sort(test))
    print(quicksort(test))
    print(quicksort2(test))
    print(heap_sort(test))
    print(count_sort(test))




