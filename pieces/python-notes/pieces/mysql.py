#coding=utf-8
#导入pymysql的包
import pymysql
import pymysql.cursors

#获取一个数据库连接，注意如果是UTF-8类型的，需要制定数据库
#port 必须是数字不能为字符串
connection=pymysql.connect(host='localhost',
                           user='root',
                           password='xx1115',
                           db='k_test',
                           #port=3307, 写明了端口反而无法连接数据库
                           charset='utf8')
try:
    #获取一个游标

   with connection.cursor() as cursor:
       sql='select * from newaccount'
       cout=cursor.execute(sql)
       print("数量： "+str(cout))
       for row in cursor.fetchall():
           #print('%s\t%s\t%s' %row)

            #注意int类型需要使用str函数转义
            print(row)
           #print("ID: "+str(row[0])+'  名字： '+row[1]+"  性别： "+row[2]) 需要注意数据类型
       connection.commit()
except:
   # Rollback in case there is any error
    connection.rollback()
finally:
    connection.close()


# -------------------------fork
#!/usr/bin/python3
# a sample to use mysql-connector for python3
# see details from   http://dev.mysql.com/doc/connector-python/en/index.html
 
import mysql.connector
import sys, os
 
user = 'root'
pwd  = '123456'
host = '127.0.0.1'
db   = 'test'
 
data_file = 'mysql-test.dat'
 
create_table_sql = "CREATE TABLE IF NOT EXISTS mytable ( \
                    id int(10) AUTO_INCREMENT PRIMARY KEY, \
    name varchar(20), age int(4) ) \
    CHARACTER SET utf8"
 
insert_sql = "INSERT INTO mytable(name, age) VALUES ('Jay', 22 ), ('杰', 26)"
select_sql = "SELECT id, name, age FROM mytable"
 
cnx = mysql.connector.connect(user=user, password=pwd, host=host, database=db)
cursor = cnx.cursor()
 
try:
    cursor.execute(create_table_sql)
except mysql.connector.Error as err:
    print("create table 'mytable' failed.")
    print("Error: {}".format(err.msg))
    sys.exit()
 
try:
    cursor.execute(insert_sql)
except mysql.connector.Error as err:
    print("insert table 'mytable' failed.")
    print("Error: {}".format(err.msg))
    sys.exit()
 
if os.path.exists(data_file):
    myfile = open(data_file)
    lines = myfile.readlines()
    myfile.close()
 
    for line in lines:
        myset = line.split()
        sql = "INSERT INTO mytable (name, age) VALUES ('{}', {})".format(myset[0], myset[1])
        try:
            cursor.execute(sql)
        except mysql.connector.Error as err:
            print("insert table 'mytable' from file 'mysql-test.dat' -- failed.")
            print("Error: {}".format(err.msg))
            sys.exit()
 
try:
    cursor.execute(select_sql)
    for (id, name, age) in cursor:
        print("ID:{}  Name:{}  Age:{}".format(id, name, age))
except mysql.connector.Error as err:
    print("query table 'mytable' failed.")
    print("Error: {}".format(err.msg))
    sys.exit()
 
cnx.commit()
cursor.close()
cnx.close()



# ------------------插入数据
#coding=utf-8
#导入pymysql的包
import pymysql
import pymysql.cursors

#获取一个数据库连接，注意如果是UTF-8类型的，需要制定数据库
#port 必须是数字不能为字符串
connection=pymysql.connect(host='localhost',
                           user='root',
                           password='xx1115',
                           db='k_test',
                           #port=3307, 写明了端口反而无法连接数据库
                           charset='utf8')
try:
    #获取一个游标

   with connection.cursor() as cursor:
        sql='select * from newaccount'
        cout=cursor.execute(sql)
        print("数量： "+str(cout))
        for row in cursor.fetchall():
            print(row)

        sql = "INSERT INTO newaccount (id, createTime, ipaddress) VALUES ( '%s', '%s', '%s')"
        data = ('6', '20180324', '192.168.0.9')
        cursor.execute(sql % data)
        connection.commit()
        print('成功插入', cursor.rowcount, '条数据')
        sql='select * from newaccount'
        cout=cursor.execute(sql)
        print("数量： "+str(cout))
        for row in cursor.fetchall():
            print(row)

except:
   # Rollback in case there is any error
    connection.rollback()
finally:
    connection.close()


# -----------修改数据




#coding=utf-8
#导入pymysql的包
import pymysql
import pymysql.cursors

#获取一个数据库连接，注意如果是UTF-8类型的，需要制定数据库
#port 必须是数字不能为字符串
connection=pymysql.connect(host='localhost',
                           user='root',
                           password='xx1115',
                           db='k_test',
                           #port=3307, 写明了端口反而无法连接数据库
                           charset='utf8')
try:
    #获取一个游标

   with connection.cursor() as cursor:
        sql='select * from newaccount'
        cout=cursor.execute(sql)
        print("数量： "+str(cout))
        for row in cursor.fetchall():
            print(row)


        sql = "UPDATE newaccount SET ipaddress = '%s'  WHERE id = %d "
        data = ('192.168.0.8',2)
        cursor.execute(sql % data)
        connection.commit()
        print('成功修改', cursor.rowcount, '条数据')
        sql='select * from newaccount'
        cout=cursor.execute(sql)
        print("数量： "+str(cout))
        for row in cursor.fetchall():
            print(row)

except:
   # Rollback in case there is any error
    connection.rollback()
finally:
    connection.close()

# ---------查询数据
#coding=utf-8
#导入pymysql的包
import pymysql
import pymysql.cursors

#获取一个数据库连接，注意如果是UTF-8类型的，需要制定数据库
#port 必须是数字不能为字符串
connection=pymysql.connect(host='localhost',
                           user='root',
                           password='xx1115',
                           db='k_test',
                           #port=3307, 写明了端口反而无法连接数据库
                           charset='utf8')
try:
    #获取一个游标

   with connection.cursor() as cursor:
        sql = "SELECT id,ipaddress FROM newaccount WHERE id = %d "
        data = (3,)
        cout = cursor.execute(sql % data)
        print("数量： "+str(cout))
        for row in cursor.fetchall():
            print("Id:%d\tipaddress:%s" % row)
except:
   # Rollback in case there is any error
    connection.rollback()
finally:
    connection.close()
# ----------------删除数据
#coding=utf-8
#导入pymysql的包
import pymysql
import pymysql.cursors

#获取一个数据库连接，注意如果是UTF-8类型的，需要制定数据库
#port 必须是数字不能为字符串
connection=pymysql.connect(host='localhost',
                           user='root',
                           password='xx1115',
                           db='k_test',
                           #port=3307, 写明了端口反而无法连接数据库
                           charset='utf8')
try:
    #获取一个游标

   with connection.cursor() as cursor:
        sql='select * from newaccount'
        cout=cursor.execute(sql)
        print("数量： "+str(cout))
        for row in cursor.fetchall():
            print(row)

        sql = "DELETE FROM newaccount WHERE id = %d LIMIT %d "
        data = (3,1)
        cursor.execute(sql % data)
        connection.commit()
        print("删除： "+str(cursor.rowcount),'条数据')

        sql='select * from newaccount'
        cout=cursor.execute(sql)
        print("数量： "+str(cout))
        for row in cursor.fetchall():
            print(row)

except:
   # Rollback in case there is any error
    connection.rollback()
finally:
    connection.close()





"""
数量： 5
(1, datetime.datetime(2018, 3, 14, 0, 0), '192.168.1.0')
(2, None, '192.168.0.8')
(3, datetime.datetime(2018, 3, 22, 0, 0), '192.168.1.2')
(3, datetime.datetime(2018, 3, 22, 0, 0), '192.168.1.2')
(6, datetime.datetime(2018, 3, 24, 0, 0), '192.168.0.9')
删除： 1 条数据
数量： 4
(1, datetime.datetime(2018, 3, 14, 0, 0), '192.168.1.0')
(2, None, '192.168.0.8')
(3, datetime.datetime(2018, 3, 22, 0, 0), '192.168.1.2')
(6, datetime.datetime(2018, 3, 24, 0, 0), '192.168.0.9')


"""


# -------------事务处理
#coding=utf-8
#导入pymysql的包
import pymysql
import pymysql.cursors

#获取一个数据库连接，注意如果是UTF-8类型的，需要制定数据库
#port 必须是数字不能为字符串
connection=pymysql.connect(host='localhost',
                           user='root',
                           password='xx1115',
                           db='k_test',
                           #port=3307, 写明了端口反而无法连接数据库
                           charset='utf8')



sql_1 = "UPDATE newaccount SET createTime = createTime + 1000 WHERE id = 1 "
sql_2 = "UPDATE newaccount SET createTime = createTime + 2000 WHERE id = 6 "
sql_3 = "UPDATE newaccount SET createTime = createTime + 3000 WHERE id = 3 "

try:
    #获取一个游标

   with connection.cursor() as cursor:
        sql='select * from newaccount'
        cout=cursor.execute(sql)
        print("数量： "+str(cout))
        for row in cursor.fetchall():
            print(row)

        cursor.execute(sql_1)
        cursor.execute(sql_2)
        cursor.execute(sql_3)
        connection.commit()

        sql='select * from newaccount'
        cout=cursor.execute(sql)
        print("数量： "+str(cout))
        for row in cursor.fetchall():
            print(row)

except:
   # Rollback in case there is any error
    connection.rollback()
finally:
    connection.close()





"""

数量： 4
(1, datetime.datetime(2018, 3, 14, 0, 0), '192.168.1.0')
(2, None, '192.168.0.8')
(3, datetime.datetime(2018, 3, 22, 0, 0), '192.168.1.2')
(6, datetime.datetime(2018, 3, 24, 0, 0), '192.168.0.9')
数量： 4
(1, datetime.datetime(2018, 3, 14, 0, 10), '192.168.1.0')
(2, None, '192.168.0.8')
(3, datetime.datetime(2018, 3, 22, 0, 30), '192.168.1.2')
(6, datetime.datetime(2018, 3, 24, 0, 20), '192.168.0.9')

"""


# ----------

"""
mysql> describe newaccount;
+------------+--------------+------+-----+---------+-------+
| Field      | Type         | Null | Key | Default | Extra |
+------------+--------------+------+-----+---------+-------+
| id         | bigint(20)   | YES  |     | NULL    |       |
| createTime | datetime     | YES  |     | NULL    |       |
| ipaddress  | varchar(255) | YES  |     | NULL    |       |
+------------+--------------+------+-----+---------+-------+
"""



"""
http://www.runoob.com/python/python-mysql.html

这里待完善 用变量传递参数 user_id = "test123" password = "password"

connection.execute('insert into Login values("%s", "%s")' % 
(user_id, password))

sql = "INSERT INTO EMPLOYEE(FIRST_NAME, 
LAST_NAME, AGE, SEX, INCOME) 
VALUES ('%s', '%s', '%d', '%c', '%d' )" % 
('Mac', 'Mohan', 20, 'M', 2000)




"""
