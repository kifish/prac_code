import math

total_num=0.0
highest = 0
lowest = 100
failed_num=0
good_num=0
li=[0,0,0,0,0,0,0,0,0,0,0]
_li=[]
while True:
    s = input()
    if s=="NO":
        break
    a=int(s)
    total_num+=1
    if a>highest:
        highest = a
    if a< lowest:
        lowest = a
    if a<60:
        failed_num+=1
    if a>=85:
        good_num+=1
    for i in range(len(li)):
        if a<10*(i+1):
            li[i]+=1
            break
    _li.append(a)

_sum=sum(_li)
average=_sum/len(_li)
biaozhun = 0
for i in range(len(_li)):
    biaozhun+=math.pow(_li[i]-average,2)
biaozhun=math.sqrt(biaozhun)

print(str(total_num)+","+str(highest)+","+str(lowest)+","+str(failed_num)+","+str(good_num)+","+round(str(biaozhun),2))
for i in range(len(li)):
    if i!=len(li)-1:
        print(li[i], end=",")
    else:
        print(li[i], end="")
