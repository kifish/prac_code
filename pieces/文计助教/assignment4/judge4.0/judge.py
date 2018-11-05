import os

def fun1(paramPath):
    rFile = open(paramPath,"r",encoding="utf-8")
    result_list = []
    result_dic={}
    for line in rFile.readlines():
        line=line.strip()
        line=line.split(",")
        line[1]=float(line[1])
        result_list.append(line)
        result_dic[line[0]] = line[1]
    return result_list, result_dic

def judgeSeq(paramList):
    temp = -1
    for item in paramList[0]:
        if temp>item[1]:
            print(temp,item[1])
            return False
        temp = item[1]
    temp=10000000
    for item in paramList[1]:
        if temp<item[1]:
            return False
        temp = item[1]
    return True

path_list = ["resources1", "resources2"]

# run
li2=os.listdir(path_list[1])
for item in li2:
    if item[-2:]=="py":
        raw_path = os.getcwd()
        os.chdir(os.path.join(raw_path, path_list[1]))
        os.system("python "+ item)
        os.chdir(raw_path)

# read
str_list=[]
dic_list=[]
for _item in path_list:
    _li = os.listdir(_item)
    temp_list1=[[],[]]
    temp_list2=[{},{}]
    for item in _li:
        if item[-6:-4]=="cf":
            temp_list1[0], temp_list2[0] = fun1(os.path.join(_item, item))  
        elif item[-6:-4]=="cd":
            temp_list1[1], temp_list2[1] = fun1(os.path.join(_item, item))
    str_list.append(temp_list1)
    dic_list.append(temp_list2)

flag=True
# judge order
if judgeSeq(str_list[1])==False:
    flag = False
    print("Warning: The order of sequence is wrong!")

# judge number
if not (dic_list[0][0] ==dic_list[1][0] and dic_list[0][1] ==dic_list[1][1]):
    flag = False
    print("Warning: Sequence is wrong!")

if flag==True:
    print("Pass")

# delete
li2=os.listdir(path_list[1])
for item in li2:
    if item[-6:-4]=="cf" or item[-6:-4]=="cd":
        os.remove(os.path.join(path_list[1],item))


