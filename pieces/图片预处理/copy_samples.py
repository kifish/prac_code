#coding = utf-8
#0 NA
#age:
#child 1 teenage 2 adult 3 old 4
#gender:
#female 1 male 2
#bag:
#yes:1 no:2
#color:
#black 1 blue 2 green 3 red 4 white(gray) 5 yellow 6 other 7
#direction:
#up 1 down 2 right 3 left 4
#hair:
#long 1 short 2
#upper:
#black 1 blue 2 green 3 red 4 white 5 grey 6 yellow 7 purple 8 other 9
#lower:
#black 1 blue 2 green 3 red 4 white 5 grey 6 yellow 7 purple 8 other 9
#mask:
#yes:1 no:2
#shoes:
#black 1 white 2 other 3
#type:
#bicycle 1 motorcycle 2 tricycle 3
#head:
#hat 1 helmet 2 no 3

# age gender hair shoes bag upper lower mask head color type direction
import os
def travel(root,all = []):
    files = os.listdir(root)
    for file in files:
        # print(file)
        path = os.path.join(root,file)
        if os.path.isdir(path):
            travel(path,all)
        elif path[-4:] == '.jpg':
            all.append(path)
    return all

# 遍历的时候要用绝对路径，不能相对路径
# root必须绝对路径（多层递归的时候相对路径有问题）
# 而且 isdir 也要用绝对路径来判断

filepaths = travel(os.path.abspath('.'))

def get_id(s):
    """
    :param input: string
    :return:
    """
    items = s.split('_')
    last = items[-1]
    return items[-2] + '_'+ last[:-4]
# print(get_id('./helmet/helmet/bike_1114411402_411.jpg'))

def get_pic2attrs(filepaths):
    pic2attrs = {}
    for x in filepaths:
        id = get_id(x)
        if id in pic2attrs:
            pic2attrs[id].append(x)
        else:
            pic2attrs[id] = [x]
    return pic2attrs

# print(sorted(get_pic2attrs(all).items(),key = lambda x : len(x[1]),reverse = True))

pic2attrs = get_pic2attrs(filepaths)
print(pic2attrs)

def disgard(s,l):
    # 把第一个/ 也去掉
    return s[l+1:]

def get_attr_list(s):
    items = s.split('/')
    return items[:-1]


#defaultdict工厂函数是不能带参数的
def init_():
    attr_num = 12
    x = []
    for i in range(attr_num):
        x.append(0)
    return x

from collections import defaultdict
pic2label = defaultdict(init_)

def fill_1(pic_id,s):
    if 'child' in s:
        pic2label[pic_id][0] = 1
    elif 'teenage' in s:
        pic2label[pic_id][0] = 2
    elif 'adult' in s:
        pic2label[pic_id][0] = 3
    elif 'old' in s:
        pic2label[pic_id][0] = 4

def fill_2(pic_id,s):
    if 'female' in s:
        pic2label[pic_id][1] = 1
    elif 'male' in s:
        pic2label[pic_id][1] = 2

def fill_3(pic_id, s):
    if 'long' in s:
        pic2label[pic_id][2] = 1
    elif 'short' in s:
        pic2label[pic_id][2] = 2

def fill_4(pic_id, s):
    if 'black' in s:
        pic2label[pic_id][3] = 1
    elif 'white' in s:
        pic2label[pic_id][3] = 2
    elif 'other' in s:
        pic2label[pic_id][3] = 3

def fill_5(pic_id, s):
    if 'yes' in s:
        pic2label[pic_id][4] = 1
    elif 'no' in s:
        pic2label[pic_id][4] = 2

def fill_6(pic_id, s):
    if 'black' in s:
        pic2label[pic_id][5] = 1
    elif 'blue' in s:
        pic2label[pic_id][5] = 2
    elif 'green' in s:
        pic2label[pic_id][5] = 3
    elif 'red' in s:
        pic2label[pic_id][5] = 4
    elif 'white' in s:
        pic2label[pic_id][5] = 5
    elif 'gray' in s:
        pic2label[pic_id][5] = 6
    elif 'yellow' in s:
        pic2label[pic_id][5] = 7
    elif 'purple' in s:
        pic2label[pic_id][5] = 8
    elif 'other' in s:
        pic2label[pic_id][5] = 9

def fill_7(pic_id, s):
    if 'black' in s:
        pic2label[pic_id][6] = 1
    elif 'blue' in s:
        pic2label[pic_id][6] = 2
    elif 'green' in s:
        pic2label[pic_id][6] = 3
    elif 'red' in s:
        pic2label[pic_id][6] = 4
    elif 'white' in s:
        pic2label[pic_id][6] = 5
    elif 'gray' in s:
        pic2label[pic_id][6] = 6
    elif 'yellow' in s:
        pic2label[pic_id][6] = 7
    elif 'purple' in s:
        pic2label[pic_id][6] = 8
    elif 'other' in s:
        pic2label[pic_id][6] = 9

def fill_8(pic_id, s):
    if 'yes' in s:
        pic2label[pic_id][7] = 1
    elif 'no' in s:
        pic2label[pic_id][7] = 2

def fill_9(pic_id, s):
    if 'hat' in s:
        pic2label[pic_id][8] = 1
    elif 'helmet' in s:
        pic2label[pic_id][8] = 2
    elif 'no' in s:
        pic2label[pic_id][8] = 3

def fill_10(pic_id, s):
    if 'black' in s:
        pic2label[pic_id][9] = 1
    elif 'blue' in s:
        pic2label[pic_id][9] = 2
    elif 'green' in s:
        pic2label[pic_id][9] = 3
    elif 'red' in s:
        pic2label[pic_id][9] = 4
    elif 'white' in s:
        pic2label[pic_id][9] = 5
    elif 'yellow' in s:
        pic2label[pic_id][9] = 6
    elif 'other' in s:
        pic2label[pic_id][9] = 7

def fill_11(pic_id, s):
    if 'bicycle' in s:
        pic2label[pic_id][10] = 1
    elif 'motorcycle' in s:
        pic2label[pic_id][10] = 2
    elif 'tricycle' in s:
        pic2label[pic_id][10] = 3

def fill_12(pic_id, s):
    if 'up' in s:
        pic2label[pic_id][11] = 1
    elif 'down' in s:
        pic2label[pic_id][11] = 2
    elif 'right' in s:
        pic2label[pic_id][11] = 3
    elif 'left' in s:
        pic2label[pic_id][11] = 4



# get_pic2attrs(all)

prefix_len = len(os.path.abspath('.'))

def process_attr(pic_id,attr):
    attr = disgard(attr,prefix_len)
    attr = get_attr_list(attr)
    if 'age' in attr:
        fill_1(pic_id, attr)
    elif 'gender' in attr:
        fill_2(pic_id, attr)
    elif 'hair' in attr:
        fill_3(pic_id, attr)
    elif 'shoes' in attr:
        fill_4(pic_id, attr)
    elif 'bag' in attr:
        fill_5(pic_id, attr)
    elif 'upper' in attr:
        fill_6(pic_id, attr)
    elif 'lower' in attr:
        fill_7(pic_id, attr)
    elif 'mask' in attr:
        fill_8(pic_id, attr)
    elif 'head' in attr:
        fill_9(pic_id, attr)
    elif 'color' in attr:
        fill_10(pic_id, attr)
    elif 'type' in attr:
        fill_11(pic_id, attr)
    elif 'direction' in attr:
        fill_12(pic_id, attr)

def get_attr_id(pic_id,attrs):
    for attr in attrs:
        process_attr(pic_id, attr)

def process(pic2attrs):
    for pic_id,attrs in pic2attrs.items():
        get_attr_id(pic_id,attrs)


process(pic2attrs)
print(pic2label)

def travel2(root,pic2path = {}):
    files = os.listdir(root)
    for file in files:
        # print(file)
        path = os.path.join(root,file)
        if os.path.isdir(path):
            travel2(path,pic2path)
        elif path[-4:] == '.jpg':
            pic_id = get_id(path)
            if pic_id not in pic2path:
                pic2path[pic_id] = path
    return pic2path


from shutil import copyfile
def copy_sample(root_path,pic2path,pic2label):
    if not os.path.exists(root_path):
        os.mkdir(root_path)
    for k,v in pic2path.items():
        label = ''.join(list(map(str,pic2label[k])))
        new_path = os.path.join(root_path,k + '_' + label) + '.jpg'
        copyfile(v,new_path)


dst_path = os.path.join(os.path.abspath('.'),'all')
copy_sample(dst_path,travel2(os.path.abspath('.')),pic2label)

