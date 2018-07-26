

待修改.

 https://www.patest.cn/contests/pat-a-practise/1034

复制代码
#include<cstdio>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
map<string,int> M;
struct Edge {
    int ida,idb;
    int weight;
}edge[100];
int time[1005];
struct boss{
    int sum;
    string name;
     boss(string _name,int _sum=0):sum(_sum),name(_name){} 
};

int root[1005];
int findroot(int x){
    if(root[x]==x)
        return x;
    else{
        int tmp=findroot(root[x]);
        root[x]=tmp;
        return tmp;
    }
}
int main(){
    int n;int th;int tmp;
    char str[10];
    string a;
    scanf("%d %d",&n,&th);
    for(int i=0;i<n;i++){
        root[i]=i;
    }
    for(int i=0;i<n;i++){
        root[i]=i;
    }
    int noden=0,edgen=0;
    for(int i=0;i<n;i++){
        scanf("%s",str);
        a=str;
        if(M.find(str)==M.end()){
            M[str]=noden++;
        }
        scanf("%s",str);
        if(M.find(str)==M.end()){
            M[str]=noden++;
        }
        scanf("%d",&tmp);
        edge[edgen].ida=M[a];
        edge[edgen].idb=M[str];
        edge[edgen++].weight=tmp;
        time[edge[edgen].ida]+=tmp; 
        time[edge[edgen].idb]+=tmp;
    }
    int hangcnt=0;

    for(int i=0;i<edgen;i++){
        int roota=findroot(edge[i].ida);
        int rootb=findroot(edge[i].idb);
        if(roota!=rootb){
            if(time[rootb]>=time[roota])
                root[roota]=rootb;
            else root[rootb]=roota;
        }
    }
    map<int,int> S;
    map<string,int>res; 
    int rootn;
    int tmpsum=0;
    vector<int> rootid;
    for(int i=0;i<noden;i++){
        if(S.find(i)==S.end()){
            int id=root[i];
            S[id]+=time[i];
            if(S[id]>th){
                //res[]=0;
            }
        }
    }
    
    
    return 0;
}
