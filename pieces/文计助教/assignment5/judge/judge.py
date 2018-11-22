import os
import zipfile

root_path = '/Users/k/Downloads/resources/'

zipfile_path = ''
for file in os.listdir(root_path):
    if file != '.DS_Store':
        zipfile_path = os.path.join(root_path, file)
        break

unzip_path = os.path.join(root_path, "unzip")
print(zipfile_path)  # 无法解压rar
files = zipfile.ZipFile(zipfile_path, 'r')
for file in files.namelist():
    files.extract(file, unzip_path)
files.close()

# print(unzip_path)
if '__MACOSX' in os.listdir(unzip_path):
    if len(os.listdir(unzip_path)) == 2:
        print('case 1')
        unzip_good_path = ''
        for file in os.listdir(unzip_path):
            if file != '__MACOSX' and file != '.DS_Store':
                unzip_good_path = os.path.join(unzip_path, file)
                break

        filename = ''
        if unzip_good_path:
            for file in os.listdir(unzip_good_path):
                if '.py' in file:
                    filename = file
                    break
        #     print(filename)
        py_path = os.path.join(unzip_good_path, filename)
    else:
        print('case 2')
        filename = ''
        for file in os.listdir(unzip_path):
            if '.py' in file:
                filename = file
                break
        #   print(filename)
        py_path = os.path.join(unzip_path, filename)
elif len(os.listdir(unzip_path)) >= 3:
    print('case 3')
    filename = ''
    for file in os.listdir(unzip_path):
        if '.py' in file:
            filename = file
            break
    py_path = os.path.join(unzip_path, filename)
else:  # upzip_path/1800015422_20181017/xxx.txt
    print('case 4')
    unzip_good_path = ''
    for file in os.listdir(unzip_path):
        if file != '__MACOSX' and file != '.DS_Store':
            unzip_good_path = os.path.join(unzip_path, file)
            break
    filename = ''
    for file in os.listdir(unzip_good_path):
        if '.py' in file:
            filename = file
            break
    py_path = os.path.join(unzip_good_path, filename)

print(os.path.split(py_path)[0])
for file in os.listdir(os.path.split(py_path)[0]):
    if '.txt' in file:
        os.remove(os.path.join(os.path.split(py_path)[0], file))

raw_path1 = '/Users/k/Documents/prac_code/pieces/文计助教/assignment5/judge/resources2/红楼梦.txt'
raw_path2 = '/Users/k/Documents/prac_code/pieces/文计助教/assignment5/judge/resources2/水浒传.txt'
from shutil import copyfile

copyfile(raw_path1, os.path.split(py_path)[0] + '/' + '红楼梦.txt')
copyfile(raw_path2, os.path.split(py_path)[0] + '/' + '水浒传.txt')

# run
os.chdir(os.path.split(py_path)[0])
os.system('python ' + py_path)

# import subprocess
# os.chdir(os.path.join(raw_path, path_list[1]))
# p = subprocess.Popen("python "+item,stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
# # p.terminate()
# # p.kill()
# #这个bug很难复现出来，似乎是因为直接kill或者terminate，就会导致文件没有保存。
# p.wait() #必须要wait
# # print(os.getcwd())
# # print(os.listdir('.'))
# # os.system("python " + item) # 用os.system 没有上面的问题，但是在windows上可能出问题,没有os.system的接口


pre_path1 = '/Users/k/Documents/prac_code/pieces/文计助教/assignment5/judge/resources1/'
txt_list1 = [pre_path1 + str(i) + '.txt' for i in range(2, 6)]
pre_path2 = os.path.split(py_path)[0] + '/'
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
    is_first = True
    is_hundred = False
    for line in rFile.readlines():
        line = line.strip()
        line = re.split(",|\s+", line)
        try:
            line[1] = float(line[1])
            if (is_first):
                if (line[1] > 1):
                    is_hundred = True
                is_first = False
            if (is_hundred):
                line[1] /= 100
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
def decSeq(List):
    pre = 1
    for item in List:
        if pre < item[1]:
            return False
        pre = item[1]
    return True


def get_list(paramPath):
    rFile = open(paramPath, "r", encoding="utf-8")
    result_list = []
    for line in rFile.readlines():
        line = line.strip()
        line = re.split(",|\s+", line)
        #         result_list.append(line)
        result_list.extend(line)
    rFile.close()
    return result_list


def get_L(paramPath):
    rFile = open(paramPath, "r", encoding="utf-8")
    rContent = rFile.read()
    rContent = rContent.strip()
    if (rContent[-1] == ','):
        print('fuck!!!!!!! ,')
        rContent = rContent[:-1]
    result_list = re.split("(,|s)+", rContent)
    rFile.close()
    return result_list


def diff(L1, L2):
    len1 = len(L1)
    len2 = len(L2)
    min_len = min(len1, len2)
    diff_list = []
    i = 0
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
if not decSeq(list_21):
    print('here wrong1')
    flag[0] = False
if not (dic11 == dic21):
    print('here wrong2')
    flag[0] = False

diff(list_11, list_21)

# 3
rfile1 = open(txt_list1[1], "r", encoding="utf-8")
rfile2 = open(txt_list2[1], "r", encoding="utf-8")
file1_content = rfile1.read()
file2_content = rfile2.read()
rfile1.close()
rfile2.close()
L1 = list(map(int, (re.findall(r'[0-9]+', file1_content))))
L2 = list(map(int, (re.findall(r'[0-9]+', file2_content))))
spaces = re.findall(r's+', file2_content)
if spaces:
    print('fuck!!!!, spaces')

if not L1 == L2:
    flag[1] = False
    print(diff(L1, L2))

# 4
li_lists = []
li_lists.append(get_list(txt_list1[2]))
li_lists.append(get_list(txt_list2[2]))

# print(li_lists[0])
# print(diff(li_lists[0],li_lists[1]))
# for i in range(2):
#     if not len(li_lists[0][i]) == len(li_lists[1][i]):
#         flag[2] = False
#     for cha in li_lists[1][i]:
#         if not cha in li_lists[0][i]:
#             flag[2] = False
# 有的同学先乘了100 在舍入，导致有相同频率的值。。。
if (set(li_lists[0]) != set(li_lists[1])):
    minus = set(li_lists[0]) - set(li_lists[1])
    if len(minus) >= 2:
        flag[2] = False
        print(len(minus))
        print(minus)

# 5
li_lists = []
li_lists.append(get_L(txt_list1[3]))
li_lists.append(get_L(txt_list2[3]))

for ch in li_lists[1]:
    if not ch in li_lists[0]:
        print(ch)
        flag[3] = False
if (not flag[3]):
    diff(li_lists[0], li_lists[1])

print(flag)

# for item in txt_list:
#     #print(os.path.join(path_list[1], item))
#     #os.remove(os.path.join(path_list[1], item)) #有时候不能删除
#     os.remove(os.path.join(os.getcwd(),os.path.join(path_list[1], item)))


if flag == [True] * 4:
    import shutil
    root_path = '/Users/k/Downloads/resources'
    for file in os.listdir(root_path):
        path = os.path.join(root_path,file)
        if os.path.isdir(path):
            shutil.rmtree(path)
        else:
            os.remove(path)
