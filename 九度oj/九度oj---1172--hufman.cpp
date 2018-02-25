/*
给定结点的哈夫曼树可能不唯一，所以关于哈夫曼树的机试题往往需要求解的是其最小带权路径长度和。
最小带权路径长度和求法有多种：
1.所有非叶子节点的权值和 （搬睡过）
2.叶子节点乘以对应边数再求和 （哈夫曼树）
（根节点的权值不是最小带权路径长度和）

默认优先队列为大顶堆。
priority_queue<int> Q;
与下面这条语句等价
priority_queue<int,vector<int>,less<int> > Q;
 
小顶堆。
priority_queue<int,vector<int>,greater<int> > Q;


*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<string>

using namespace std;

priority_queue<int,vector<int>,greater<int> > Q;
int main(){
    int n;
    int res;
    int a,b;
    while(scanf("%d",&n)!=EOF){
        while(!Q.empty()){Q.pop();}
        while(n--){
            scanf("%d",&a);
            Q.push(a);
        }
        res=0;
        while(Q.size()>1){
            a=Q.top();
            Q.pop();
            b=Q.top();
            Q.pop();
            res+=a+b;
            Q.push(a+b);
        }
        printf("%d\n",res);
    }
    return 0;
}
