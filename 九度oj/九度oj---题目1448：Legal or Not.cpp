
/*
几个注意点：记得加

using namespace std;
有时候本地不加，还是能跑。提交时候忘加了会CE.
Q存放的是度为0的点。
可新建队列保存结果。

*/

#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>list[500];
int indegree[500];
queue<int> Q;
queue<int> res;
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
    if(n==0&&m==0) break;
    fill(indegree,indegree+n,0);
    for(int i=0;i<=n-1;i++) list[i].clear();
    int u,v;
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        indegree[v]++;
        list[u].push_back(v);
    }
    while(!Q.empty()){Q.pop();}
    for(int i=0;i<=n-1;i++){
        if(indegree[i]==0){
            Q.push(i);
        }
    }
    //Q存放度为0的点
    int cnt=0;
    while(!res.empty()){res.pop();}
    while(!Q.empty()){
        int firstp=Q.front();
        res.push(firstp);
        cnt++;
        Q.pop();
        for(int i=0;i<list[firstp].size();i++){
            indegree[list[firstp][i]]--;
            if(indegree[list[firstp][i]]==0){
                Q.push(list[firstp][i]);
            }
        }
    } 
        if(cnt==n)  puts("YES"); //DAG
    
        else puts("NO");
    }
    return 0;
}
