import os
from shutil import copyfile
root_path = os.path.abspath('.')
dir_path1 = os.path.join(os.path.abspath('../'),'pic_dir1')
dir_path2 = os.path.join(os.path.abspath('../'), 'pic_dir2')
os.mkdir(dir_path1)
os.mkdir(dir_path2)

meta = {}
for filename in os.listdir('.'):
    if len(filename) >= 4 and filename[-4:] == '.jpg':
        k = filename.split('_')[0]
        if k in meta:
            meta[k].append(filename)
        else:
            meta[k] = [filename]
cnt = 0
for k,v in meta.items():
    assert len(v) == 2
    new_path = os.path.join(dir_path1,k + '.jpg')
    old_path = os.path.join(root_path,v[0])
    copyfile(old_path,new_path)
    new_path = os.path.join(dir_path2, k + '.jpg')
    old_path = os.path.join(root_path, v[1])
    copyfile(old_path, new_path)
    cnt += 2
print('moved {} pics'.format(cnt))


