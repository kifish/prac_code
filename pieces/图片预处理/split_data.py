import os
import itertools
file2path = {}
pic_id2idx = {}


#data
#   train
#   test
from shutil import copyfile
def split_data(path):
    root = os.path.abspath('.')
    data_path = root + '/' + 'data'
    os.mkdir(data_path)
    
    train_path = data_path + '/' + 'train'
    test_path = data_path + '/' + 'test'
    os.mkdir(train_path)
    os.mkdir(test_path)
    
    files = os.listdir(path)
    for file in files:
        if file[-4:] == '.jpg':
            file2path[file] = os.path.join(root + '/' + 'all',file)
    idxs = list(range(len(file2path)))
    itertools.permutations(idxs)
    th = int(len(idxs) * 0.8)
    idx = 0
    for file,path in file2path.items():
        new_path = ''
        if(idxs[idx] <= th):
            new_path = train_path + '/' + file
            copyfile(path, new_path)
        else:
            new_path = test_path + '/' + file
            copyfile(path, new_path)
        idx += 1
path = os.path.join(os.path.abspath('.'),'all')
split_data(path)

