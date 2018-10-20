total_num=0
highest = 0
lowest = 100
failed_num=0
good_num=0
li=[0,0,0,0,0,0,0,0,0,0,0]
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

print(str(total_num)+","+str(highest)+","+str(lowest)+","+str(failed_num)+","+str(good_num))
for i in range(len(li)):
    if i!=len(li)-1:
        print(li[i], end=",")
    else:
        print(li[i], end="")


