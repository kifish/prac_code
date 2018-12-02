D:The Unique MST

http://algorithm.openjudge.cn/algorithmb/D/


```C
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int INF = 0x3fffffff;
const int MAXV = 1005;
struct Node{
    int v;
    int w;
};


vector<Node> adj[MAXV];
bool got[MAXV];
int d[MAXV];//集合S到点i的最短距离
int n;
//right
//显然上面的实现比下面的实现更高效！
int prim(bool &is_unique){
    is_unique = true;
    fill(d,d+MAXV,INF);
    memset(got, false,sizeof(got));
    int s = 1;
    d[s] = 0;
    int times = n;
    int sum = 0;
    while (times--){
        int u = -1,min_d = INF;
        for(int i = 1;i<=n;i++){//本题结点编号从1开始
            if(!got[i] && d[i] < min_d){
                min_d = d[i];
                u = i;
            }
        }
        if(u == -1) return -1;//剩下的顶点与集合S不连通，即无法生成MST
        sum += d[u];//将与集合S距离最小的边加入MST
        got[u] = 1;
        for(int j = 0;j<adj[u].size();j++){
            int v = adj[u][j].v;
            int w = adj[u][j].w;
            if(!got[v]){
                if(0 + w < d[v])
                    d[v] = w;
                else if(0 + w == d[v]){
                    is_unique = false;
                }
            }
        }
    }
    return sum;
}

//right
//int prim(bool &is_unique){
//    is_unique = true;
//    fill(d,d+MAXV,INF);
//    memset(got, false,sizeof(got));
//    int s = 1;
//    d[s] = 0;
//    int times = n;
//    int sum = 0;
//    while (times--){
//        int u = -1,min_d = INF;
//        for(int i = 1;i<=n;i++){//本题结点编号从1开始
//            if(!got[i] && d[i] < min_d){
//                min_d = d[i];
//                u = i;
//            }
//        }
//        int equal_edge_cnt = 0;
//        for(int i = 0;i<adj[u].size();i++){
//            int v = adj[u][i].v;
//            int w = adj[u][i].w;
//            if(got[v] && w == min_d)
//                equal_edge_cnt++;
//        }
//        if(equal_edge_cnt > 1) is_unique = false;
//        if(u == -1) return -1;//剩下的顶点与集合S不连通，即无法生成MST
//        sum += d[u];//将与集合S距离最小的边加入MST
//        got[u] = 1;
//        for(int j = 0;j<adj[u].size();j++){
//            int v = adj[u][j].v;
//            int w = adj[u][j].w;
//            if(!got[v]){
//                if(0 + w < d[v])
//                    d[v] = w;
//                else if(0 + w == d[v]){
//                    ;
//                }
//            }
//        }
//    }
//    return sum;
//}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int m;
        scanf("%d %d",&n,&m);
        //清空邻接表！！！
        for(int i = 1;i<=n;i++) adj[i].clear();
        while(m--){
            int u,v,edge_weight;
            scanf("%d %d %d",&u,&v,&edge_weight);
            Node tmp;
            tmp.w = edge_weight;
            tmp.v = v;
            adj[u].push_back(tmp);
            tmp.v = u;
            adj[v].push_back(tmp);
        }
        bool is_unique;
        int res = prim(is_unique);
        if(is_unique){
            printf("%d\n",res);
        }
        else{
            printf("Not Unique!\n");
        }
    }
    return 0;
}
```