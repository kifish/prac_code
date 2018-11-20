
diff = False
for i in range(2,6):
    path1 = '../resources1/' + str(i) + '.txt'
    path2 = str(i) + '.txt'
    f1 = open(path1)
    f2 = open(path2)
    if f1.read() != f2.read():
        diff = True
        print(path2)
    f1.close()
    f2.close()




def diff(L1,L2):
    len1 = len(L1)
    len2 = len(L2)
    min_len = min(len1,len2)
    diff_list = []
    for i in range(min_len):
        if L1[i] != L2[i]:
            diff_list.append((L1[i],L2[i]))
    while i < len1 -1:
        diff_list.append((L1[i],"NaN"))
        i += 1
    while i < len2 -1: #最多只进入一个分支
        i += 1 # 要先加1，因为i之前是停在L1最后一个item上的
        diff_list.append(("#",L2[i]))
    if len(diff_list) == 0:
        print("this line is good!")
    else:
        print("nope")
        print(diff_list)

for i in range(2,6):
    path1 = '../resources1/' + str(i) + '.txt'
    path2 = str(i) + '.txt'
    f1 = open(path1)
    f2 = open(path2)
    l1 = f1.readlines()
    l1 = [s.strip() for s in l1]
    l2 = f2.readlines()
    l2 = [s.strip() for s in l2]
    f1.close()
    f2.close()
    if i==5:
        diff(l1[0].split(','),l2[0].split(','))
    elif i == 4:
        for i in range(len(l1)):
            diff(l1[i].split(','), l2[i].split(','))
            if(set(l1[i].split(',')) == set(l1[i].split(','))):
                print("set same")
    else:
        diff(l1,l2)


