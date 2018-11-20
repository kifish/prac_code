import os
import zipfile

root_path = '/Users/k/Downloads/resources/'

pre_path1 = '/Users/k/Documents/prac_code/pieces/文计助教/assignment5/judge/resources1/'
txt_list1 = [pre_path1 + str(i) + '.txt' for i in range(2, 6)]
pre_path2 = '/Users/k/Downloads/resources/upzip/1800015446/'
txt_list2 = [pre_path2 + str(i) + '.txt' for i in range(2, 6)]

flag = [True] * 4

import re


def parse(paramPath):
    # print(paramPath)
    # print(os.getcwd()) #即使这里相对目录是对的，竟然也会出问题！ 用绝对路径也会出问题！
    # paramPath = os.path.join(os.getcwd(),paramPath) # 不是路径的问题！
    rFile = open(paramPath, "r", encoding="utf-8")
    top500_list = []
    after500_list = []
    top500_dict = {}
    after500_dict = {}
    counter = 1
    for line in rFile.readlines():
        line = line.strip()
        line = re.split(",|\s+", line)
        try:
            line[1] = float(line[1])
        except:
            print(paramPath)
            print(line)
            raise
        if counter <= 500:
            top500_list.append(line)
            top500_dict[line[0]] = line[1]
        else:
            after500_list.append(line)
            after500_dict[line[0]] = line[1]
        counter += 1
    rFile.close()
    return top500_list, after500_list, top500_dict, after500_dict


# 递减
def judgeSeq(List):
    pre = 1
    for item in List:
        if pre < item[1]:
            return False
        pre = item[1]
    return True


def parse2(paramPath):
    rFile = open(paramPath, "r", encoding="utf-8")
    result_list = []
    for line in rFile.readlines():
        line = line.strip()
        line = re.split(",|\s+", line)
        result_list.append(line)
    rFile.close()
    return result_list


def parse3(paramPath):
    rFile = open(paramPath, "r", encoding="utf-8")
    rContent = rFile.read()
    rContent = rContent.strip()
    result_list = re.split(",|\s+", rContent)
    rFile.close()
    return result_list


def diff(L1, L2):
    len1 = len(L1)
    len2 = len(L2)
    min_len = min(len1, len2)
    diff_list = []
    for i in range(min_len):
        if L1[i] != L2[i]:
            diff_list.append((L1[i], L2[i]))
    while i < len1 - 1:
        diff_list.append((L1[i], "NaN"))
        i += 1
    while i < len2 - 1:  # 最多只进入一个分支
        i += 1  # 要先加1，因为i之前是停在L1最后一个item上的
        diff_list.append(("#", L2[i]))
    if len(diff_list) == 0:
        print("this line is good!")
    else:
        print("nope")
        print(diff_list)


# 2
list_11, list_12, dic11, dic12 = parse(txt_list1[0])
list_21, list_22, dic21, dic22 = parse(txt_list2[0])
if not (judgeSeq(list_21) and judgeSeq(list_22)):
    print('here wrong1')
    flag[0] = False
if not (dic11 == dic21 and dic12 == dic22):
    print('here wrong2')
    flag[0] = False

# print(list_11)
# print(list_12)
print(diff(list_11, list_21))
print(diff(list_12, list_22))
# print(list_21)
# print(list_22)

# 3
rfile1 = open(txt_list1[1], "r", encoding="utf-8")
rfile2 = open(txt_list2[1], "r", encoding="utf-8")
file1_content = rfile1.read()
file2_content = rfile2.read()
rfile1.close()
rfile2.close()
if not file1_content == file2_content:
    flag[1] = False

# 4
li_list = [[], []]
li_list[0] = parse2(txt_list1[2])
li_list[1] = parse2(txt_list2[2])

for i in range(2):
    if not len(li_list[0][i]) == len(li_list[1][i]):
        flag[2] = False
    for cha in li_list[1][i]:
        if not cha in li_list[0][i]:
            flag[2] = False

# 5
li_list = []
li_list.append(parse3(txt_list1[3]))
li_list.append(parse3(txt_list2[3]))

for cha in li_list[1]:
    if not cha in li_list[0]:
        flag[3] = False

print(flag)

# for item in txt_list:
#     #print(os.path.join(path_list[1], item))
#     #os.remove(os.path.join(path_list[1], item)) #有时候不能删除
#     os.remove(os.path.join(os.getcwd(),os.path.join(path_list[1], item)))



