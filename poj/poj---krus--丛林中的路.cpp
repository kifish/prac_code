/*
错误分析：合并集合的时候，不是把边的两个端点修改关系，而是把两个端点的根修改关系。合并集合是对两个集合的根的操作。

建议:最好还是初始化根为自身吧，初始化为-1感觉有点别扭（虽然初始化的时候快一点）。实际上不用map也可以的。char x -‘A’ ,转化为节点编号。



*/


#include<cstdio>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int father[30];
int findfather(int x){
    /*if (father[x]==-1)
        return x;*/
    if(father[x]==x)
        return x;
    else {
        int tmp=findfather(father[x]);
        father[x]=tmp;
        return tmp;
    }
}

struct Edge{
    int ida,idb;
    int weight;
}edge[80];
bool cmp(Edge a,Edge b){
    return a.weight<b.weight;
}
map<string,int> M;
char str[3];
string tstr[28]; 
int main(){
    int n;int tmpn;
    while(scanf("%d",&n)!=EOF&&n!=0){
        int edgen=0;int noden=0;
        M.clear();
        //fill(father,father+30,-1);
        for(int i=0;i<n;i++) father[i]=i;
        for(int rowi=0;rowi<n-1;rowi++){
            int stri=0;
            scanf("%s",str);
            if(M.find(str)==M.end()){
                M[str]=noden++;
                //printf("char %s:id %d\n",str,noden-1);
            }
            tstr[stri++]=str;
            scanf("%d",&tmpn);
            for(int j=0;j<tmpn;j++){
                scanf("%s",str);
                tstr[stri++]=str;
                if(M.find(str)==M.end()){
                    M[str]=noden++;
                //    printf("char %s:id %d\n",str,noden-1);
                }
                scanf("%d",&edge[edgen].weight);
                edge[edgen].ida=M[tstr[0]];
                edge[edgen].idb=M[tstr[(stri-1)]];
                edgen++;
            }
        }
        
        
    sort(edge,edge+edgen,cmp);  
    /*for(int i=0;i<=edgen-1;i++){
        printf("%d\n",edge[i].weight);
    }*/
        
    int sum=0;
    for(int i=0;i<=edgen-1;i++){
        
        if(findfather(edge[i].ida)!=findfather(edge[i].idb)){
        //    printf("edge id: %d\n",i);
        //    printf("node ida:%d idb:%d\n",edge[i].ida,edge[i].idb);
            sum+=edge[i].weight;
            //father[edge[i].ida]=edge[i].idb;
            father[findfather(edge[i].ida)]=findfather(edge[i].idb);
        }
    }
    bool ismst=1;
    int cnt=0;

    for(int i=0;i<=noden-1;i++){
        if(father[i]==-1)
            cnt++;
            //printf("%d",cnt);   
        if(cnt>1)
            ismst=false;
    }
    if(ismst){
        printf("%d\n",sum);
    }
    
    }
    return 0;
}
