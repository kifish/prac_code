https://www.zybuluo.com/diyer22/note/310572
https://blog.csdn.net/a1628864705/article/details/57074653



排序测试
```
#https://www.nowcoder.com/practice/508f66c6c93d4191ab25151066cb50ef?tpId=69&&tqId=29657&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking

n = input()
x = list(map(int,input().split()))
x = f(x)

s = ''
for item in x:
    s += str(item) + ' '
s.strip()
print(s)
```



```python
import sys
# https://pintia.cn/problem-sets/14/problems/807
# https://blog.csdn.net/a1628864705/article/details/57074653
# row1 = sys.stdin.readline().strip()
# n,k = row1.split()
# row2 = sys.stdin.readline().strip()
# a = row2.split()
n,k = list(map(lambda x: int(x), input().split()))
a = list(map(lambda x: int(x), input().split()))
k = k if k >0 else 0
for i in range(k):
  for j in range(n-i-1):
    if a[j] > a[j+1]:
      a[j+1],a[j] = a[j],a[j+1]

for i in range(len(a)):
  if i != 0:
    sys.stdout.write(' ')
  sys.stdout.write(str(a[i]))

```

也可以参考这个：
https://github.com/EINDEX/Python-algorithm/blob/master/algorithm/test/test_sort.py
写下单元测试。
