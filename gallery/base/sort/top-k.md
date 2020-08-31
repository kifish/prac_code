```py
import random 

def partition(a, lo, hi):
    '''返回pivot的索引，索引之前的元素都小于等于pivot,索引之后的元素都大于等于pivot'''
    i = lo
    j = hi + 1
    while True:
        i += 1
        while a[i] < a[lo] and i < hi:
            i += 1

        j -= 1
        while a[j] > a[lo] and j > lo:
            j -= 1
        # j > lo is redundant while i < hi is not.
        if i >= j:
            break
        a[i], a[j] = a[j], a[i]

    a[lo], a[j] = a[j], a[lo]
    return j
# 第k个举例：第0个，即最小的元素
def find_top_k(a,k):
    arr = a.copy()
    random.shuffle(arr)
    lo = 0
    hi = len(arr) - 1
    while lo < hi:
        j = partition(arr,lo,hi) #划分然后返回pivot的位置
        if j < k:
            lo = j + 1
        elif j > k:
            hi = j -1
        else:
            return arr[k]
    return arr[k] # 这种情况下 lo == hi 

if __name__ == '__main__':
    test = [3, 6, 8, 10, 1, 2, 1]
    print(find_top_k(test,0))
    print(find_top_k(test,4))
```