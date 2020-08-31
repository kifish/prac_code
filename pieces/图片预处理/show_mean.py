import os,sys
from collections import defaultdict

import matplotlib
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

import cv2

from PIL import Image


def cal_samples(path):
    # print()
    unique_ids = set()
    for file_name in os.listdir(path):
        if file_name == '.DS_Store':
            continue
        person_id = file_name.split('_')[0]
        if int(person_id) > 825:
            continue
        unique_ids.add(person_id)
    id_cnt = len(unique_ids)
    print('id num : {}'.format(id_cnt))
    
    return id_cnt

def stat(path,with_mask = True):
    flag2cnt = defaultdict(int)
    
    for file_name in os.listdir(path):
        if file_name == '.DS_Store':
            continue
        person_id = file_name.split('_')[0]
        if int(person_id) > 825:
            continue
        if (with_mask and file_name.split('_')[1] == '1') or (not with_mask and file_name.split('_')[1] == '0'):
            for pic_name in os.listdir(os.path.join(path,file_name)):
                if pic_name == '.DS_Store':
                    continue
                pic_name = pic_name.split('.')[0]
                flag = pic_name.split('_')[-1]
                flag = int(flag)
                flag2cnt[flag] += 1

                if flag == 5: # print wrong data
                    print(os.path.join(path, file_name))
                    print(pic_name)

    print(flag2cnt)
    return flag2cnt

def iter_imgs(path, flag2img_np, flag2cnt, with_mask = True, mini_data = False, debug = False):
    iter_cnt = 0
    for file_name in os.listdir(path):
        if file_name == '.DS_Store':
            continue
        person_id = file_name.split('_')[0]
        if int(person_id) > 825:
            continue
        if mini_data:
            if iter_cnt > 10:
                for flag, img_np in flag2img_np.items():
                    flag2img_np[flag] *= 80
                return
        if (with_mask and file_name.split('_')[1] == '1') or (not with_mask and file_name.split('_')[1] == '0'):
            sub_dir = os.path.join(path,file_name)
            for pic_name in os.listdir(sub_dir):
                if pic_name == '.DS_Store':
                    continue
                pic_name_no_suffix = pic_name.split('.')[0]
                flag = pic_name_no_suffix.split('_')[-1]
                flag = int(flag)
                pic_path = os.path.join(sub_dir,pic_name)
                # https://blog.csdn.net/hjxu2016/article/details/79104607
                # img = cv2.imread(pic_path) # NoneType
                # img = mpimg.imread(pic_path)
                
                img = Image.open(pic_path)
                resized_img = img.resize([200,200], Image.ANTIALIAS)
                # print(dir(resized_img))
                
                # https://stackoverflow.com/questions/29367990/what-is-the-difference-between-image-resize-and-image-thumbnail-in-pillow-python
                # img.thumbnail((64, 64), Image.ANTIALIAS)  # resizes image in-place
                img = np.array(img)
                resized_img = np.array(resized_img)
                
                if debug:
                    print(img.shape)
                    print(resized_img.shape)
                    # resized_img = cv2.resize(img, dsize=(200, 200), interpolation=cv2.INTER_CUBIC)
                    # https://stackoverflow.com/questions/48121916/numpy-resize-rescale-image
                    # https://matplotlib.org/tutorials/introductory/images.html
                    
                    plt.figure(1)
                    plt.subplot(2,1,1)
                    plt.imshow(img)
                    plt.subplot(2,1,2)
                    plt.imshow(resized_img)
                    print(resized_img)
                    plt.show()
                    return 
                
                if flag in flag2img_np:
                    flag2img_np[flag] += resized_img / flag2cnt[flag]
                else:
                    flag2img_np[flag] = resized_img / flag2cnt[flag]

            iter_cnt += 1

                    
                    
                    
def show_mean(path):
    cal_samples(path)
    flag2cnt = stat(path, with_mask = False)
    flag2img_np = {}

    plt.figure(1)

    iter_imgs(path, flag2img_np, flag2cnt, with_mask=False, mini_data = False, debug= False)
    for flag, img_np in flag2img_np.items():
        plt.subplot(2, 5, flag + 1)
        # print(img_np)
        # 要把浮点数转化为int  否则会显示为空白
        # https://moonbooks.org/Articles/How-to-convert-a-float-array-to-an-integer-array-in-python-/
        # img_np = np.around(img_np)
        # print(img_np)
        # img_np = img_np.astype(int) # wrong
        img_np = img_np.astype(np.uint8)
        print(img_np)
        plt.imshow(img_np)
        matplotlib.image.imsave('{}.png'.format(flag+1), img_np)
        plt.axis("off")


    flag2cnt = stat(path, with_mask = True)
    flag2img_np = {}
    iter_imgs(path, flag2img_np, flag2cnt, with_mask= True, mini_data = False, debug= False)
    for flag, img_np in flag2img_np.items():
        plt.subplot(2, 5, 5 + flag + 1)
        # print(img_np)
        # 要把浮点数转化为int  否则会显示为空白
        # https://moonbooks.org/Articles/How-to-convert-a-float-array-to-an-integer-array-in-python-/
        # img_np = np.around(img_np)
        # print(img_np)
        # img_np = img_np.astype(int) # wrong
        img_np = img_np.astype(np.uint8)
        print(img_np)
        plt.imshow(img_np)
        matplotlib.image.imsave('{}.png'.format(5 + flag + 1), img_np)
        plt.axis("off")

    plt.show()
        
    
    
    
if __name__ == '__main__':
    root_dir = 'C:/document/口罩人脸/pics'
    # root_dir = '/c/document/口罩人脸/pics' # wrong
    show_mean(root_dir)
    
    
    
    

