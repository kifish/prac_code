pata1030 模板。

pata 1003 模板。
https://github.com/kifish/prac_code/blob/master/gallery/pat/pat-a/1003.md

```C
//以下部分要放在if外面
pre[v].insert(u);
//需要重新计算最短路径条数！因为有可能pre[v]里面已经有u了；其实用count判断下估计也可以；或者用dfs判断。
num[v] = 0;
set<int>::iterator it;
for(it = pre[v].begin();it != pre[v].end();it++){
    num[v] += num[*it];
```