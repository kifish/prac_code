
# coding: utf-8

# In[86]:


#coding = utf-8
from datetime import datetime
now = datetime.now()
print(now)


# In[87]:


print(type(now))


# In[88]:


#如果仅导入import datetime，则必须引用全名datetime.datetime


# In[89]:


dt = datetime(2015, 4, 19, 12, 20)
print(dt)


# In[90]:


dt.timestamp()
t = dt.timestamp()
#注意Python的timestamp是一个浮点数。如果有小数位，小数位表示毫秒数。


# In[91]:


#某些编程语言（如Java和JavaScript）的timestamp使用整数表示毫秒数，这种情况下只需要把timestamp除以1000就得到Python的浮点表示方法。


# In[92]:


print(datetime.fromtimestamp(t))  # 本地时间
#这里是按当前操作系统设定的时区计算的，本机默认为UTC+8:00


# In[93]:


print(datetime.utcfromtimestamp(t))  # utc时间


# In[94]:


cday = datetime.strptime('2015-6-1 18:19:59', '%Y-%m-%d %H:%M:%S')
print(cday)
print(type(cday))
#https://docs.python.org/3/library/datetime.html#strftime-strptime-behavior


# In[95]:


now = datetime.now()
print(now.strftime('%a, %b %d %H:%M'))


# In[96]:


from datetime import datetime, timedelta, timezone
now = datetime.now()
print(now)
print(now+timedelta(hours=10))
print(now+timedelta(days=1))
print(now+timedelta(days=2, hours=12))


# In[97]:


tz_utc_8 = timezone(timedelta(hours=8))
datetime.now()


# In[98]:


dt = now.replace(tzinfo=tz_utc_8)
dt
#如果系统时区恰好是UTC+8:00，那么上述代码就是正确的，否则，不能强制设置为UTC+8:00时区。


# In[99]:


utc_dt = datetime.utcnow().replace(tzinfo=timezone.utc)
print(utc_dt)


# In[100]:


bj_dt = utc_dt.astimezone(timezone(timedelta(hours=8)))


# In[101]:


print(bj_dt)


# In[102]:


tokyo_dt = utc_dt.astimezone(timezone(timedelta(hours=9)))


# In[103]:


print(tokyo_dt)


# In[104]:


tokyo_dt2 = bj_dt.astimezone(timezone(timedelta(hours=9)))


# In[105]:


print(tokyo_dt2)


# In[161]:


import re
from datetime import datetime, timezone, timedelta


def prezerostr_to_int(s):
    res = 0
    first_nonzero = False
    for digit in s:
        digit = int(digit)
        if digit == 0 and first_nonzero == False:
            continue
        elif digit != 0 and first_nonzero == False:
            first_nonzero = True
            res = res*10 + digit
    return res


def to_timestamp(dt_str, tz_str):
    cday = datetime.strptime(dt_str, '%Y-%m-%d %H:%M:%S')
    #注意转换后的datetime是没有时区信息的。
    #user_dt = utc_dt.astimezone(timezone(timedelta(hours=x)))
    #不论x是什么，都是无法改变user_dt.timestamp()的
    #如果用户是UTC+7:00，则加相应的秒数
    #utc_dt = cday.replace(tzinfo=timezone.utc) 这行代码把问题搞复杂了
    #print(utc_dt)
    #int(01)这样会出错

    res = 0
    if re.match(r'^UTC\+(0[0-9]|1[0-9]|2[0-9]|[0-9]).*', tz_str):
        #这里+号前面的\不能省，因为需要转义
        s = re.match(r'^UTC\+(0[0-9]|1[0-9]|2[0-9]|[0-9]).*', tz_str).group(1)
        res = prezerostr_to_int(s)
        #res = (res-8)*-1
        res = 8 - res
    elif re.match(r'^UTC\-(0[0-9]|1[0-9]|2[0-9]|[0-9]).*', tz_str):
        s = re.match(r'^UTC\-(0[0-9]|1[0-9]|2[0-9]|[0-9]).*', tz_str).group(1)
        res = prezerostr_to_int(s)
        res *= -1
        res = 8 - res
    delta = res
    delta *= 3600
    return(cday.timestamp()+delta)


# In[162]:


t1 = to_timestamp('2015-6-1 08:10:30', 'UTC+7:00')
assert t1 == 1433121030.0, t1

t2 = to_timestamp('2015-5-31 16:10:30', 'UTC-09:00')
assert t2 == 1433121030.0, t2

print('ok')


# In[163]:


import re
from datetime import datetime, timezone, timedelta


def prezerostr_to_int(s):
    res = 0
    first_nonzero = False
    for digit in s:
        digit = int(digit)
        if digit == 0 and first_nonzero == False:
            continue
        elif digit != 0 and first_nonzero == False:
            first_nonzero = True
            res = res*10 + digit
    return res


def to_timestamp(dt_str, tz_str):
    cday = datetime.strptime(dt_str, '%Y-%m-%d %H:%M:%S')
    #注意转换后的datetime是没有时区信息的。
    #user_dt = utc_dt.astimezone(timezone(timedelta(hours=x)))
    #不论x是什么，都是无法改变user_dt.timestamp()的
    #我们也可以赋予datetime正确的时区信息
    res = 0
    if re.match(r'^UTC\+(0[0-9]|1[0-9]|2[0-9]|[0-9]).*', tz_str):
        s = re.match(r'^UTC\+(0[0-9]|1[0-9]|2[0-9]|[0-9]).*', tz_str).group(1)
        res = prezerostr_to_int(s)
    elif re.match(r'^UTC\-(0[0-9]|1[0-9]|2[0-9]|[0-9]).*', tz_str):
        s = re.match(r'^UTC\-(0[0-9]|1[0-9]|2[0-9]|[0-9]).*', tz_str).group(1)
        res = prezerostr_to_int(s)
        res *= -1
    tz_utc_user = timezone(timedelta(hours=res))
    dt = cday.replace(tzinfo=tz_utc_user)
    return(dt.timestamp())


# In[164]:


t1 = to_timestamp('2015-6-1 08:10:30', 'UTC+7:00')
assert t1 == 1433121030.0, t1

t2 = to_timestamp('2015-5-31 16:10:30', 'UTC-09:00')
assert t2 == 1433121030.0, t2

print('ok')
