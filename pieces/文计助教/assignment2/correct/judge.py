import subprocess
import re
import os
import zipfile
import shutil

# 这个standard里的答案有问题。

def func1(paramPath, paramInput):
    child1 = subprocess.Popen("/Users/k/anaconda3/bin/python "+ paramPath, stdin= subprocess.PIPE, stdout=subprocess.PIPE,shell=True)
    child1.stdin.write(bytes(paramInput, encoding="utf8"))
    out = child1.communicate()
    sss=out[0].decode("utf8")
    return sss

test_list=["80\n90\nNO","10\n23\n100\nNO","42\n37\n30\n20\n60\nNO","62\n37\n30\n80\n60\nNO","71\n69\n31\n99\n99\n60\nNO"]
score_list=[0,0]


# unzip
current_path = '/Users/k/Downloads/'
resources_path = '/Users/k/Downloads/resources'
_li=os.listdir(resources_path)
zip_path = os.path.join(resources_path,_li[0])
unzip_path = os.path.join(current_path,"unzip")

# fz = zipfile.ZipFile(zip_path, 'r')
# for file in fz.namelist():
#     fz.extract(file, unzip_path)
# fz.close()

standard_path = './standard'

# question 1
for i in range(len(test_list)):
    # s=re.split("\r\n",func1(os.path.join(unzip_path,"1.py"), test_list[i]))
    stan = re.split("\r\n", func1(os.path.join(standard_path,"1.py"), test_list[i]))
    print(stan)
    # if s[0]==stan[0] and s[1]==stan[1]:
    #     score_list[0] += 10

#question 2
for i in range(len(test_list)):
    # s=re.split("\r\n",func1(os.path.join(unzip_path,"2.py"), test_list[i]))
    stan = re.split("\r\n", func1(os.path.join(standard_path,"2.py"), test_list[i]))
    print(stan)
    # if s[0]==stan[0] and s[1]==stan[1]:
    #     score_list[1] += 10


print(score_list)
print("final score is:", sum(score_list))

# delete unzip and zip files
# os.remove(zip_path)
# shutil.rmtree(unzip_path)

