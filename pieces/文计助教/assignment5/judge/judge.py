import os
import subprocess
path_list = ["resources1", "resources2"]
txt_list = ["2.txt", "3.txt", "4.txt", "5.txt"]

flag = [True] * 4


def fun2(paramPath):
    # print(paramPath)
    # print(os.getcwd()) #即使这里相对目录是对的，竟然也会出问题！ 用绝对路径也会出问题！
    # paramPath = os.path.join(os.getcwd(),paramPath) # 不是路径的问题！
    rFile = open(paramPath, "r", encoding="utf-8")
    result_list1 = []
    result_list2 = []
    result_dic1 = {}
    result_dic2 = {}
    counter = 1
    for line in rFile.readlines():
        line = line.strip()
        line = line.split(",")
        line[1] = float(line[1])
        if counter <= 500:
            result_list1.append(line)
            result_dic1[line[0]] = line[1]
        else:
            result_list2.append(line)
            result_dic2[line[0]] = line[1]
    rFile.close()
    return result_list1, result_list2, result_dic1, result_dic2

# 递减
def judgeSeq(paramList):
    temp = 1
    for item in paramList:
        if temp < item[1]:
            return False
        temp = item[1]
    return True


def fun4(paramPath):
    rFile = open(paramPath, "r", encoding="utf-8")
    result_list = []
    for line in rFile.readlines():
        line = line.strip()
        line = line.strip(",")
        result_list.append(line)

    rFile.close()
    return result_list


def fun5(paramPath):
    rFile = open(paramPath, "r", encoding="utf-8")
    rContent = rFile.read()
    rContent = rContent.strip()
    result_list = rContent.strip(",")
    rFile.close()
    return result_list


# run
_li = os.listdir(path_list[1])
for item in _li:
    # print(item)
    if item[-2:] == "py":
        raw_path = os.getcwd()
        os.chdir(os.path.join(raw_path, path_list[1]))
        p = subprocess.Popen("python "+item,stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
        # p.terminate()
        # p.kill()
        #这个bug很难复现出来，似乎是因为直接kill或者terminate，就会导致文件没有保存。
        p.wait() #必须要wait
        # print(os.getcwd())
        # print(os.listdir('.'))
        # os.system("python " + item) # 用os.system 没有上面的问题，但是在windows上可能出问题
        os.chdir(raw_path)

# 2
# print(os.getcwd())
list_11, list_12, dic11, dic12 = fun2(os.path.join(path_list[0], txt_list[0]))
# print(os.getcwd())
list_21, list_22, dic21, dic22 = fun2(os.path.join(path_list[1], txt_list[0]))
if not (judgeSeq(list_21) and judgeSeq(list_22)):
    flag[0] == False
if not (dic11 == dic21 and dic12 == dic22):
    flag[0] == False

# 3
rfile1 = open(os.path.join(path_list[0], txt_list[1]), "r", encoding="utf-8")
rfile2 = open(os.path.join(path_list[1], txt_list[1]), "r", encoding="utf-8")
file1_content = rfile1.read()
file2_content = rfile2.read()
if not file1_content == file2_content:
    flag[1] == False
rfile1.close()
rfile2.close()

# 4
li_list = [[], []]
for i in range(2):
    li_list[i] = fun4(os.path.join(path_list[i], txt_list[2]))
for i in range(2):
    if not len(li_list[0][i]) == len(li_list[1][i]):
        flag[2] = False
    for cha in li_list[1][i]:
        if not cha in li_list[0][i]:
            flag[2] = False

# 5
li_list = []
for i in range(2):
    li_list.append(fun5(os.path.join(path_list[i], txt_list[3])))

for cha in li_list[1]:
    if not cha in li_list[0]:
        flag[3] = False

print(flag)

for item in txt_list:
    #print(os.path.join(path_list[1], item))
    #os.remove(os.path.join(path_list[1], item)) #有时候不能删除
    os.remove(os.path.join(os.getcwd(),os.path.join(path_list[1], item)))
