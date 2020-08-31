#https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001431927781401bb47ccf187b24c3b955157bb12c5882d000
import os
from multiprocessing import Process
print('Process (%s) start...'%os.getpid())
#only works on Unix/Linux/Mac 
pid = os.fork()
if pid == 0:
    print('I am child process (%s) and my parent is %s.'%(os.getpid(),os.getppid()))
else:
    print('I (%s) just created a child process (%s).'%(os.getpid(),pid))
 
import os,time,random
from multiprocessing import Process,Pool
def run_proc(name):
    print('Run child process %s (%s)...' % (name,os.getpid()))
    
if __name__=='__main__':
    print('Parent process %s.' % os.getpid())
    p = Process(target=run_proc,args=('test',))
    print('Child process will start.')
    p.start()
    p.join()
    print('Child process end.')
 
import os,time,random
from multiprocessing import Process,Pool
def long_time_task(name):
    print('Run child process %s (%s)...' % (name,os.getpid()))
    start = time.time()
    time.sleep(random.random()*3)
    end = time.time()
    print('Task %s runs %0.2f senonds.' % (name,(end-start)))
    
if __name__=='__main__':
    print('Parent process %s.'%os.getpid())
    p = Pool(4)
    for i in range(5):
        p.apply_async(long_time_task,args=(i,))
    print('Waiting for all subprocesses done...')
    p.close()
    p.join()
    print('All subprocesses done.')
    
 
这里要在shell中运行。ide里没结果。
import subprocess
print('$ nslookup www.python.org')
r = subprocess.call(['nslookup','www.python.org'])
print('Exit code:',r)
 
