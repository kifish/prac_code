# coding = utf-8
import re

def findRepeatNum(paramStr):
    result_list=[]
    li = re.findall(r'[0-9]+', paramStr)
    arr = [0]*20000
    for item in li:
        if arr[int(item)] ==0:
             arr[int(item)]=1
        else:
            result_list.append(int(item))
    return result_list

def findRepeatNumAndCha(paramList, paramStr):
    result_dic={}
    for item in paramList:
        li = re.findall(r"[\u4e00-\u9fa5]+\,"+str(item), paramStr)
        for _item in li:
            _li = _item.split(",")
            result_dic[_li[0]] = int(_li[1])
    return result_dic

def replaceStr(paramList, paramStr):
    result_str = paramStr
    for item in paramList:
        result_str = re.sub(r"[\u4e00-\u9fa5]+\,"+str(item), "", result_str)
    return result_str

def processStr(paramStr):
    paramStr = paramStr.strip()
    repeat_li = findRepeatNum(paramStr)
    result_dic = findRepeatNumAndCha(repeat_li, paramStr)
    result_str = replaceStr(repeat_li, paramStr)
    return result_dic, result_str

def judge(paramStr1, paramStr2):
    dic1, str1 = processStr(paramStr1)
    dic2, str2 = processStr(paramStr2)
    # print(dic1,dic2)
    # print(str1)
    # print(str2)
    # print(str2[0:2])
    # print(dic1==dic2)
    # print(str1==str2)

    if dic1==dic2 and str1==str2:
        return True
    else:
        return False

f1 = open("/Users/k/Documents/prac_code/pieces/文计助教/第三次作业/judge3/result.txtt", "r", encoding="utf-8")
# f2 = open("anyoneelse.txt", "r")
f2 = open("anyoneelse.txt", "r", encoding="utf-8")

list1 = f1.readlines()
list2 = f2.readlines()

print(list2[0])

result = True
result_list = [True]*5
for i in range(len(list1)):
    if not judge(list1[i], list2[i]):
        result= False
        result_list[i]=False

print(result_list)

if result:
    print(True)
else:
    print(False)

