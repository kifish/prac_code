#coding = utf-8
"""
https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001431929340191970154d52b9d484b88a7b343708fcc60000#0
注意这段代码在windows上可能无法运行（由于序列化的问题）
运行master.py时报错
Traceback (most recent call last):
  File "L:/code/python/task_master.py", line 19, in <module>
    manager.start()
序列化不支持匿名函数。
看错误行
_pickle.PicklingError: Can't pickle <function <lambda> at 0x0000000002BC8730>: attribute lookup <lambda> on main failed
这个错误确实是说明序列化的问题。而且在这个教程的多进程一节，廖雪峰也说明了这点，摘录如下：
在Unix/Linux下，multiprocessing模块封装了fork()调用，使我们不需要关注fork()的细节。由于Windows没有fork调用，因此，multiprocessing需要“模拟”出fork的效果，父进程所有Python对象都必须通过pickle序列化再传到子进程去，所有，如果multiprocessing在Windows下调用失败了，要先考虑是不是pickle失败了。
不支持匿名函数，所以将其提取出来定义即可，如下：
def return_task_queue():
    global task_queue
    return task_queue

def return_result_queue():
    global result_queue
    return result_queue

def start_server():

# 把两个Queue都注册到网络上，callable参数关联了Queue对象
QueueManager.register('get_task_queue', callable = return_task_queue)
QueueManager.register('get_result_queue', callable = return_result_queue)
...
这样就可以实现。另外，本小节Server端在初始化QueueManager的时候并没有带ip地址，可能是linux和mac能支持的格式（未验证过），但windows暂时不支持，因此需要将ip地址赋值，如下：

# 绑定端口34512，设置验证码'abc'
manager = QueueManager(address = ('127.0.0.1', 34512), authkey = b'abc')

"""


#task_master.py
import random,time,queue
from multiprocessing.managers import BaseManager
#发送任务的队列
task_queue = queue.Queue()
#接收结果的队列
result_queue = queue.Queue()

#从BaseManager继承的QueueManager
class QueueManager(BaseManager):
    pass
#把两个Queue都注册到网络上，callable参数关联了Queue对象：
QueueManager.register('get_task_queue',callable=lambda:task_queue)
QueueManager.register('get_result_queue',callable=lambda:result_queue)
#绑定端口5000，设置验证码'abc'
manager = QueueManager(address=('',5000),authkey=b'abc')
#启动Queue:
manager.start()
#获得通过网络访问的Queue对象:
task = manager.get_task_queue()
result = manager.get_result_queue()
#放几个任务进去:
for i in range(10):
    n = random.randint(0,10000)
    print('Put task %d...' % n)
    task.put(n)
#从result队列读取结果:
print('Try to get results...')
for i in range(10):
    r = result.get(timeout=10)
    print('Result: %s'%r)
manager.shutdown()
print('master exit.')



#task_worker.py
import time,sys,queue
from multiprocessing.managers import BaseManager

class QueueManager(BaseManager):
    pass
#由于这个QueueManager只从网络上获取Queue,所以注册时只提供名字
QueueManager.register('get_task_queue')
QueueManager.register('get_result_queue')

#连接到服务器,也就是运行task_master.py的机器:
server_addr = '127.0.0.1'
print('Connect to server %s...' %server_addr)
#端口和验证注意保持与task_master.py设置的完全一致
m = QueueManager(address=(server_addr,5000),authkey=b'abc')
m.connect()
task = m.get_task_queue()
result = m.get_result_queue()
for i in range(10):
    try:
        n = task.get(timeout=1)
        print('run task %d * %d...'%(n,n))
        r = '%d * %d = %d' % (n,n,n*n)
        time.sleep(1)
        result.put(r)
    except Queue.Empty:
        print('task queue is empty.')

print('worker exit.')
