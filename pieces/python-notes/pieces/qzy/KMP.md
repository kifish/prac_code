```PY
# Naive string matching

def naive_matching(t, p):
    j, i = 0, 0
    n, m = len(t), len(p)
    while j < n and i < m:  # i==m means a matching
        if t[j] == p[i]: # ok! consider next char in p
            j, i = j+1, i+1
        else:            # no! consider next position in t
            j, i = j-i+1, 0
    if i == m: # find a matching, return its index
        return j-i
    return -1  # no matching, return special value

## KMP string matching

def gen_pnext0(p):
    """ Generate a list for the next checking index
    """
    i, k, m = 0, -1, len(p)
    pnext = [-1] * m
    while i < m-1: # generate pnext[i+1] 
        while k >= 0 and p[i] != p[k]:
            k = pnext[k]
        i, k = i+1, k+1
        pnext[i] = k # set a pnext entry
    return pnext

def gen_pnext(p):
    """ Generate a list for the next checking index,
    a little revised version.
    """
    i, k, m = 0, -1, len(p)
    pnext = [-1] * m
    while i < m-1: # generate pnext[i+1] 
        while k >= 0 and p[i] != p[k]:
            k = pnext[k]
        i, k = i+1, k+1
        if p[i] == p[k] :
            pnext[i] = pnext[k]
        else:
            pnext[i] = k 
    return pnext

def KMPmatching(t, p, pnext):
    """ KMP string mateching, the main function."""
    j, i = 0, 0
    n, m = len(t), len(p)
    while j < n and i < m:  # i==m means a matching
        if i == -1 or t[j] == p[i]: # consider next char in p
            j, i = j+1, i+1
        else:            # no! consider pnext char in p
            i = pnext[i]
    if i == m: # find a matching, return its index
        return j-i
    return -1  # no matching, return special value

def KMPmatching1(t, p, pnext):
    """ KMP string matching, a little revised version."""
    j, i = 0, 0
    n, m = len(t), len(p)
    while j < n and i < m:  # i==m means a matching
        while i >= 0 and t[j] != p[i]:
            i = pnext[i]
        j, i = j+1, i+1
    if i == m: # find a matching, return its index
        return j-i
    return -1  # no matching, return special value

def matching(t, p):
    return KMPmatching(t, p, gen_pnext0(p))

def matching1(t, p):
    return KMPmatching1(t, p, gen_pnext0(p))

t = "abbabababbbbababaaaabababbbaaa"
p = "aabab
```



```py
#aaadd
#aad

def nmatching(target,pattern):
    t_idx,match_len = 0,0
    n,m = len(target),len(pattern)
    while t_idx < n and match_len < m:
        if target[t_idx] == pattern[match_len]:
            t_idx,match_len = t_idx + 1,match_len + 1
        else:
            t_idx,match_len = t_idx - match_len + 1,0
    if match_len == m:
        return t_idx - match_len
    return -1


def kmp_matching(target, pattern, pnext):
    t_idx, match_len = 0, 0
    n, m = len(target), len(pattern)
    while t_idx < n and match_len < m:
        if match_len == -1:
            t_idx, match_len = t_idx + 1, match_len + 1
        elif target[t_idx] == pattern[match_len]:
            t_idx, match_len = t_idx + 1, match_len + 1
        else:
            match_len = pnext[match_len]
    if match_len == m:
        return t_idx - match_len
    return -1

# next 数组见算法笔记这本书的456页

#分支合并
def kmp_matching2(target, pattern, pnext):
    t_idx, match_len = 0, 0
    n, m = len(target), len(pattern)
    while t_idx < n and match_len < m:
        if match_len == -1 or target[t_idx] == pattern[match_len]:
            t_idx, match_len = t_idx + 1, match_len + 1
        else:
            match_len = pnext[match_len]
    if match_len == m:
        return t_idx - match_len
    return -1

def genPNext0(p):
    i,k,m = 0,-1,len(p)
    pnext = [-1] * m 
    while i < m - 1:  # generate pnext[i+1],前向dp
        while k >= 0 and p[i] != p[k]:
            k = pnext[k]
        i,k = i+1,k+1
        pnext[i] = k #set a pnext entry
    return pnext

text = 'ababcabcacbab'
pattern = 'abcac'
print(kmp_matching2(text,pattern,genPNext0(pattern))) #5


def genPNext(p):
    i, k, m = 0, -1, len(p)
    pnext = [-1] * m
    while i < m - 1:  # generate pnext[i+1],前向dp
        while k >= 0 and p[i] != p[k]:
            k = pnext[k]
        i, k = i+1, k+1
        if p[i] == p[k]: #小修改，可能避免一些不必要的比较
            pnext[i] = pnext[k]
        else:
            pnext[i] = k  
    return pnext


print(kmp_matching2(text, pattern, genPNext(pattern)))  # 5

```



