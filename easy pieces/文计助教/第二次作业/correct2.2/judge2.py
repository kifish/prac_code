import subprocess
import re
import os
import zipfile
import shutil

def func1(paramPath, paramInput):
    child1 = subprocess.Popen("python "+paramPath, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    child1.stdin.write(bytes(paramInput, encoding="utf8"))
    out = child1.communicate()
    sss=out[0].decode("gbk")
    return sss

test_list=["80\r\n90\r\nNO","10\r\n23\r\n100\r\nNO","42\r\n37\r\n30\r\n20\r\n60\r\nNO","62\r\n37\r\n30\r\n80\r\n60\r\nNO","71\r\n69\r\n31\r\n99\r\n99\r\n60\r\nNO"]
score_list=[0,0]


# unzip
current_path = os.path.abspath('.')
resources_path = os.path.join(current_path,"resources")
_li=os.listdir(resources_path)
zip_path = os.path.join(resources_path,_li[0])
unzip_path = os.path.join(current_path,"unzip")

fz = zipfile.ZipFile(zip_path, 'r')
for file in fz.namelist():
    fz.extract(file, unzip_path)       
fz.close()

standard_path = os.path.join(current_path, "standard")

# question 1
for i in range(len(test_list)):
    s=re.split("\r\n",func1(os.path.join(unzip_path,"1.py"), test_list[i]))
    stan = re.split("\r\n", func1(os.path.join(standard_path,"1.py"), test_list[i]))
    if s[0]==stan[0] and s[1]==stan[1]:
        score_list[0]+=10

#question 2
for i in range(len(test_list)):
    s=re.split("\r\n",func1(os.path.join(unzip_path,"2.py"), test_list[i]))
    stan = re.split("\r\n", func1(os.path.join(standard_path,"2.py"), test_list[i]))
    if s[0]==stan[0] and s[1]==stan[1]:
        score_list[1]+=10


print(score_list)
print("final score is:", sum(score_list))

# delete unzip and zip files
# os.remove(zip_path)
shutil.rmtree(unzip_path)

