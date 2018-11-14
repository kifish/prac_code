/*

邻接矩阵版。

含负权值加权图的最短路径->Bellmanford算法

对于有负权边但无负权回路的图：优先队列优化+允许重入队，那么可以。此算法在国内称为spfa，但这实际上已经是priority queue-based Bellman-Ford了，是Bellman-Ford算法的变种。（国外习惯把这个算法仍旧叫做堆优化的Dijkstra，看作Dijkstra的变种）

Bellman ford（O(VE)）比Dijkstra慢一些。

BellmanFord（有负环需检测，如有负权回路输出错误提示）可以找到负环，但SPFA只能判断负环是否存在。

含负权值加权图的最短路径->Spfa算法
(稠密带负权图中SPFA的效率并不如Bellman-Ford高),用BF就够了。

Dijkstra算法在使用斐波那契堆优化的情况下复杂度是O(E+VlogV)。

 算法分析：https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV=510;
const int INF=0x7fffffff;
int n,m,st,ed,G[MAXV][MAXV],nweight[MAXV];
int d[MAXV],w[MAXV],num[MAXV];
bool vis[MAXV]={false};

bool Dijkstra(int s){
    fill(d,d+MAXV,INF);
    memset(num,0,sizeof(num));
    memset(w,0,sizeof(w));
    d[s]=0;
    w[s]=nweight[s];
    num[s]=1;
    for(int i=0;i<n;i++){
        int u=-1,Min=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<Min){
                u=j;
                Min=d[j];
            }
        }
        if(u==-1) return false;/*no-connected--->false */
        
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    w[v]=w[u]+nweight[v];
                    num[v]=num[u];
                }
                else if(d[u]+G[u][v]==d[v]){
                    if(w[u]+nweight[v]>w[v]){
                        w[v]=w[u]+nweight[v];
                    }
                    num[v]+=num[u];
                }
            }
        }
    }
}

int main(){
    scanf("%d %d %d %d",&n,&m,&st,&ed);
    for(int i=0;i<n;i++) scanf("%d",&nweight[i]);
    fill(G[0],G[0]+MAXV*MAXV,INF);
    int tmp1,tmp2;
    for(int i=0;i<m;i++) {
        scanf("%d %d",&tmp1,&tmp2);
        scanf("%d",&G[tmp1][tmp2]);
        G[tmp2][tmp1]=G[tmp1][tmp2];
    }
    bool flag=Dijkstra(st);
    if(flag)
        printf("%d %d\n",num[ed],w[ed]);
    else printf("no");    ///////
    return 0;
}
