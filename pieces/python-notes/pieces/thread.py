
# coding: utf-8

# In[4]:


#coding=utf-8
import time,threading
#https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/00143192823818768cd506abbc94eb5916192364506fa5d000

def loop():
    print('thread %s is running...'%threading.current_thread().name)
    n = 0
    while n<5:
        n += 1
        print('thread %s >>> %s' % (threading.current_thread().name,n))
        time.sleep(1)
    print('thread %s ended.'% threading.current_thread().name)

print('thread %s is running...'%threading.current_thread().name)
t = threading.Thread(target=loop,name='LoopThread')
t.start()
t.join()
print('thread %s ended' % threading.current_thread().name)


# In[5]:


balance = 0
def change_it(n):
    global balance
    balance = balance +n
    balance = balance -n
    
def run_thread(n):
    for i in range(10000000):
        change_it(n)
t1 = threading.Thread(target=run_thread,args=(5,))
t2 = threading.Thread(target=run_thread,args=(8,))
t1.start()
t2.start()
t1.join()
t2.join()
print(balance)


# In[10]:


balance = 0
lock = threading.Lock()

def run_thread(n):
    for i in range(100000):
        lock.acquire()
        try:
            change_it(n)
        finally:
            lock.release()
            


# In[13]:


#死循环
import multiprocessing
def loop():
    x = 0
    while True:
        x = x^1
for i in range(multiprocessing.cpu_count()):
    t = threading.Thread(target = loop)
    t.start()


# In[2]:


import multiprocessing
print(multiprocessing.cpu_count())


# In[7]:


def process_student(name):
    std = Student(name)
    do_task_1(std)
    do_task_2(std)
def do_task_1(std):
    do_subtask_1(std)
    do_subtask_2(std)

def do_task_2(std):
    do_subtask_2(std)
    do_subtask_2(std)


# In[9]:


global_dict = {}
def std_thread(name):
    std = Student(name)
    global_dict[threading.current_thread()] = std

def do_task_1():
    std = global_dict[threading.current_thread()]
    ...
def do_task_2():
    std = global_dict[threading.current_thread()]
    ...


# In[12]:


local_school = threading.local()
def process_student():
    std = local_school.student
    print('Hello,%s (in %s)'%(std,threading.current_thread().name))
    print()
def process_thread(name):
    local_school.student = name
    process_student()
t1 = threading.Thread(target = process_thread,args=('Alice',),name = 'Thread-A')
t2 = threading.Thread(target = process_thread,args=('Bob',),name = 'Thread-B')
t1.start()
t2.start()
t1.join()
t2.join()

