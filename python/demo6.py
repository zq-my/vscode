import time
import threading
from threading import Semaphore

Wmutex = Semaphore(1)
Rmutex = Semaphore(1)
Rcount = 0

def reader(i,sleept,start,start_sleep):
    time.sleep(start_sleep)
    print('时间点  '+str(int(time.strftime('%S'))-start)+'  reader  '+str(i)+'  waiting to read\n', end='')
    Rmutex.acquire()
    global Rcount
    if Rcount == 0:
        Wmutex.acquire()
    Rcount += 1
    Rmutex.release()
    print('时间点  '+str(int(time.strftime('%S'))-start)+'  reader  '+str(i)+'  reading\n', end='')
    time.sleep(sleept)
    print('时间点  '+str(int(time.strftime('%S'))-start)+'  reader  '+str(i)+'  finish reading\n', end='')
    Rmutex.acquire()
    Rcount -= 1
    if Rcount == 0:
        Wmutex.release()
    Rmutex.release()

def writer(i,sleept,start,start_sleep):
    time.sleep(start_sleep)
    now = int(time.strftime('%S'))
    print('时间点  '+str(int(time.strftime('%S'))-start)+'  writer  '+str(i)+'  waiting to write\n', end='')
    Wmutex.acquire()
    print('时间点  '+str(int(time.strftime('%S'))-start)+'  writer  '+str(i)+'  writing\n', end='')
    time.sleep(sleept)
    print('时间点  '+str(int(time.strftime('%S'))-start)+'  writer  '+str(i)+'  finish writing\n', end='')
    Wmutex.release()


if __name__ == '__main__':
    idx = []
    rwlist = []
    start_time = []
    continue_time = []
    with open('input.txt','r') as f:
        data = f.readlines()
        for x in data:
            x = x.split()
            idx.append(int(x[0]))
            rwlist.append(x[1])
            start_time.append(int(x[2]))
            continue_time.append(int(x[3]))
    start = int(time.strftime('%S'))
    print('时间点  '+str(start-start)+'  所有线程开始启动\n', end='')
    for i in range(len(rwlist)):
        print('时间点  '+str(int(time.strftime('%S'))-start)+'  线程  '+str(idx[i])+'  set up\n', end='')
        if rwlist[i] == 'R':
            t = threading.Thread(target=reader, args=(idx[i],continue_time[i],start,start_time[i]))
            t.start()
        else:
            t = threading.Thread(target=writer, args=(idx[i],continue_time[i],start,start_time[i]))
            t.start()

