
def kmp_matching(target,pattern,pnext):
    t_idx,match_len = 0,0
    n,m = len(target),len(pattern)
    while t_idx < n and match_len < m:
        if match_len == -1:
            t_idx,match_len = t_idx + 1,match_len + 1
        elif target[t_idx] == pattern[match_len]:
            t_idx,match_len = t_idx + 1,match_len + 1
        else:
            match_len = pnext[match_len]
    if match_len == m:
        return t_idx - match_len
    return -1

# next 数组见算法笔记这本书的456页

