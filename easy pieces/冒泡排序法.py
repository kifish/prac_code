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
