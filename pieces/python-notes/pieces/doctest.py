#https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/0014319170285543a4d04751f8846908770660de849f285000
 
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jan 27 16:32:34 2018
@author: k
"""
class Dict(dict):
       #''' 如果是这一行，程序会报错，因为doctest是按'''之间的内容来测试的，但需要遵循格式。
    '''
    Simple dict but also support access as x.y style.
>>> d1 = Dict()
    >>> d1['x'] = 100
    >>> d1.x
    100
    >>> d1.y = 200
    >>> d1['y']
    200
    >>> d2 = Dict(a=1, b=2, c='3')
    >>> d2.c
    '3'
    >>> d2['empty']
    Traceback (most recent call last):
        ...
    KeyError: 'empty'
    >>> d2.empty
    Traceback (most recent call last):
        ...
    AttributeError: 'Dict' object has no attribute 'empty'
    '''
    
    def __init__(self,**kw):
        super(Dict,self).__init__(**kw)
    
    def __getattr__(self,key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'Dict' object has no attribute '%s'"%key)
            
    def __setattr__(self,key,value):
        self[key] = value
if __name__ == '__main__':
    import doctest #不会在非测试环境执行
    doctest.testmod()
    
    
 
 
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jan 27 16:32:34 2018
@author: k
"""
def fact(n):
      
    '''
    Calculate 1*2*...*n
>>> fact(1)
    1
    >>> fact(10)
    3628800
    >>> fact(-1)
    Traceback (most recent call last):
        ...
    ValueError: Invalid input
    '''
    if n<1 :
        raise ValueError("Invalid input")
    if n == 1:
        return 1
    return n*fact(n-1)
if __name__ == '__main__':
    import doctest
    doctest.testmod()
    
    
 
    >>> fact(-1)
    Traceback (most recent call last):
        ...
    ValueError: Invalid input  #这一行需要有空格，本质上需要和命令行中
                               #的结果完全匹配
    '''
 
