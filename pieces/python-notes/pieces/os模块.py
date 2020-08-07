#https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001431925324119bac1bc7979664b4fa9843c0e5fcdcf1e000
 
from datetime import datetime
import os
pwd = os.path.abspath('.')
print('    Size    Last Modified Name')
print('------------------------') 
for f in os.listdir(pwd):
    fsize = os.path.getsize(f)
    mtime = datetime.fromtimestamp(os.path.getmtime(f)).strftime('%Y-%m-%d %H:%M')
    flag = '/' if os.path.isdir(f) else ''
    print('%10d %s %s%s' % (fsize,mtime,f,flag))
#在当前目录以及当前目录的所有子目录下查找文件名包含指定字符串的文件，并打印出绝对路径和相对路径。
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
pwd = os.path.abspath('.')
name = 'shan' 
for f in os.listdir(pwd):
    if os.path.isdir(f):
        temp_path = os.path.join(pwd,f)
        for f1 in os.listdir(temp_path):
            if name in os.path.splitext(f1)[0]:
                print(temp_path)
                print(os.path.join(f,''))
                print(f1)
    elif os.path.isfile(f) and name in os.path.splitext(f)[0]:
        print(pwd)
        print(os.path.join(pwd,''))
        print(f)
        
    
 
#递归
#注意isfile(fpath)和isdir(fpath)的参数默认为当前目录，写相对路径或绝对路径，不要只写个文件名，避免递归查询时找不到子目录的文件
 
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
def find_file(name,path = os.path.abspath('.')): #如果改成path = '.',打印相对路径
    for f in os.listdir(path):
        fpath = os.path.join(path,f)
        if os.path.isfile(fpath) and name in os.path.splitext(f)[0]:
            print(path)
            print(f)
        elif os.path.isdir(fpath):
            find_file(name,fpath)
find_file('shan') 
