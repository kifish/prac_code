http://algorithm.openjudge.cn/final2017/H/


https://blog.csdn.net/scf0920/article/details/36180387


二分即可。
s为1，t为n。

二分的时候重新建图，如果边的1 <= cap <= mid,那么加入该边，并将cap改为1，统计路径条数（最大流的值）是否等于t。




