
# coding: utf-8

# In[5]:


# -*- coding: utf-8 -*-

from functools import reduce

CHAR_TO_INT = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9
}


def str2int(s):
    ints = map(lambda ch: CHAR_TO_INT[ch], s)
    return reduce(lambda x, y: x * 10 + y, ints)

#print(str2int('0'))
#print(str2int('12300'))
#print(str2int('0012345'))


CHAR_TO_FLOAT = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    '.': -1
}


def str2float(s):
    nums = map(lambda ch: CHAR_TO_FLOAT[ch], s)
    point = 0

    def to_float(f, n):
        nonlocal point
        if n == -1:
            point = 1
            return f
        if point == 0:
            return f * 10 + n
        else:
            point = point * 10
            return f + n / point
    return reduce(to_float, nums, 0.0)


print(str2float('0'))
print(str2float('123.456'))
print(str2float('123.45600'))
print(str2float('0.1234'))
print(str2float('.1234'))
print(str2float('120.0034'))


# In[6]:


def _odd_iter():
    n = 1
    while True:
        n = n + 2
        yield n


# In[7]:


def _not_divisible(n):
    return lambda x: x % n > 0


# In[8]:


def primes():
    yield 2
    it = _odd_iter()  # 初始序列
    while True:
        n = next(it)  # 返回序列的第一个数
        yield n
        it = filter(_not_divisible(n), it)  # 构造新序列


# In[9]:


# 打印1000以内的素数:
for n in primes():
    if n < 1000:
        print(n)
    else:
        break


# In[10]:


from operator import itemgetter

L = ['bob', 'about', 'Zoo', 'Credit']

print(sorted(L))
print(sorted(L, key=str.lower))


# In[11]:


students = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]


# In[12]:


list(sorted(students, key=lambda t: t[1]))


# In[13]:


list(sorted(students, key=lambda t: t[0]))


# In[14]:


print(sorted(students, key=itemgetter(0)))


# In[15]:


print(sorted(students, key=itemgetter(1), reverse=True))


# In[16]:


# -*- coding: utf-8 -*-

def lazy_sum(*args):
    def sum():
        ax = 0
        for n in args:
            ax = ax + n
        return ax
    return sum


f = lazy_sum(1, 2, 4, 5, 7, 8, 9)


# In[17]:


f


# In[18]:


f()


# In[19]:


def count():
    fs = []
    for i in range(1, 4):
        def f():
             return i * i
        fs.append(f)
    return fs


# In[20]:


f1, f2, f3 = count()


# In[21]:


print(f1())
print(f2())
print(f3())


# In[22]:


def count():
    fs = []

    def f(n):
        def j():
            return n * n

        return j
    for i in range(1, 4):
        fs.append(f(i))
    return fs


# In[23]:


f1, f2, f3 = count()


# In[24]:


print(f1())
print(f2())
print(f3())


# In[25]:


@log
def now():
    print('2015-3-25')


# In[26]:


def log(func):
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper


# In[27]:


@log
def now():
    print('2015-3-25')


# In[28]:


now()


# In[31]:


import functools


# In[32]:


def logger(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator


# In[34]:


@logger('DEBUG')
def today():
    print('2015-3-25')


# In[35]:


today()


# In[36]:


print(today.__name__)


# In[37]:


print(now.__name__)


# In[57]:


def logger(text=''):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            if len(text) == 0:
                print("{}():".format(func.__name__))
            else:
                print("%s %s():" % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator


# In[60]:


@logger()
def f():
    pass


# In[61]:


f()


# In[56]:


import time
import functools


# In[47]:


def metric(fn):
    @functools.wraps(fn)
    def wrapper(*args, **kw):
       print('%s executed in %s ms' % (fn.__name__, 10.24))
       return fn(*args, **kw)
    return wrapper


# In[48]:


@metric
def fast(x, y):
    time.sleep(0.0012)
    return x + y


@metric
def slow(x, y, z):
    time.sleep(0.1234)
    return x * y * z


# In[49]:


f = fast(11, 22)


# In[50]:


s = slow(11, 22, 33)


# In[52]:


if f != 33:
    print('测试失败!')
elif s != 7986:
    print('测试失败!')
