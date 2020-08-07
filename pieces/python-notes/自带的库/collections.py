
# coding: utf-8

# In[2]:


from collections import namedtuple
Point = namedtuple('Point',['x','y'])
p = Point(1,2)
p.x


# In[3]:


p.y


# In[5]:


isinstance(p, Point)


# In[6]:


isinstance(p, tuple)


# In[ ]:


#namedtuple('名称',[属性list]):
Circle = nametuple('Circle',['x','y','r'])
#使用list存储数据时，按索引访问元素很快，但是插入和删除元素就很慢了，因为list是线性存储，数据量大的时候，插入和删除效率很低。


# In[7]:


#deque是为了高效实现插入和删除操作的双向列表，适合用于队列和栈
from collections import deque
q = deque(['a','b','c'])
q.append('x')
q.appendleft('y')
q


# In[ ]:


#deque除了实现list的append()和pop()外，还支持appendleft()和popleft()，这样就可以非常高效地往头部添加或删除元素


# In[ ]:


#使用dict时，如果引用的Key不存在，就会抛出KeyError。如果希望key不存在时，返回一个默认值，就可以用defaultdict


# In[8]:


from collections import defaultdict
dd = defaultdict(lambda: 'N/A')
dd['key1'] = 'abc'
dd['key1']


# In[9]:


dd['key2']


# In[ ]:


#注意默认值是调用函数返回的，而函数在创建defaultdict对象时传入。
#除了在Key不存在时返回默认值，defaultdict的其他行为跟dict是完全一样的。


# In[ ]:


#使用dict时，Key是无序的。在对dict做迭代时，我们无法确定Key的顺序。
#如果要保持Key的顺序，可以用OrderedDict


# In[2]:


from collections import OrderedDict
d = dict([('a',1),('b',2),('c',3)])
d


# In[3]:


od = OrderedDict([('a',1),('b',2),('c',3)])
#OrderedDict的Key会按照插入的顺序排列，不是Key本身排序
od


# In[4]:


od = OrderedDict()
od['z'] = 1
od['y'] = 2
od['x'] = 3
list(od.keys()) # 按照插入的Key的顺序返回


# In[7]:


#OrderedDict可以实现一个FIFO（先进先出）的dict，当容量超出限制时，先删除最早添加的Key
from collections import OrderedDict
class LastUpdatedOrderedDict(OrderedDict):
    def __init__(self,capacity):
        super(LastUpdatedOrderedDict,self).__init__()
        self._capacity = capacity
    def __setitem__(self,key,value):
        containsKey = 1 if key in self else 0
        if len(self)-containsKey >= self._capacity:
            last = self.popitem(last=False)
            print('remove:',last)
        if containsKey:
            del self[key]
            print('set:',(key,value))
        else:
            print('add:',(key,value))
        OrderedDict.__setitem__(self,key,value)


# In[11]:


from collections import Counter
c = Counter()
for ch in 'programming':
    c[ch] += 1
c

