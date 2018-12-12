import os
import itertools
file2path = {}

#data
#train
#test


from shutil import copyfile


def split_data(path):
    parent_path = os.path.abspath(path + '/..')
    train_path = parent_path + '/' + 'train'
    test_path = parent_path + '/' + 'test'
    os.mkdir(train_path)
    os.mkdir(test_path)
    files = os.listdir(path)
    for file in files:
        if file[-4:] == '.jpg':
            file2path[file] = os.path.join(path, file)
    idxs = list(range(len(file2path)))
    itertools.permutations(idxs)
    th = int(len(idxs) * 0.8)
    idx = 0
    for file, path in file2path.items():
        new_path = ''
        if (idxs[idx] <= th):
            new_path = train_path + '/' + file
            copyfile(path, new_path)
        else:
            new_path = test_path + '/' + file
            copyfile(path, new_path)
        idx += 1


path = os.path.join(os.path.abspath('.'), 'people')
split_data(path)
