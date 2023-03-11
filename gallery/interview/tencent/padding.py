# wechat intern interview problem

import numpy as np
import torch

# 2d
max_seq_num = 20
max_seq_len =20
# shape: (n,max_seq_num,max_seq_len)
raw = np.zeros([max_seq_num,max_seq_len])
seqs = [[1,2],[7,7]]
for i in range(len(seqs)):
    for j in range(len(seqs[i])):
        raw[i][j] = seqs[i][j]

#  (12,10,15)
# ->  (12*10,15)

# cnn
# 1d conv

# 1d conv

# lstm

# (b,token_len)
# (b,token_len)

def softmax(input,input_mask):
    input = torch.exp(input,dim = -1)
    input.mask_fill(x = input_mask,value = 0)
    ret = input / (torch.sum(input,dim = -1) + 1e-10)
    return ret 




