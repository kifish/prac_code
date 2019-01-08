http://algorithm.openjudge.cn/algorithma/C/


http://bailian.openjudge.cn/practice/clarify/2387/

此题很多坑。

数据范围不对，而且有重边。

AC

```C
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    int v;
    int w;
};

int edge[1005][1005];

const int INF = 0x3fffffff;
vector<Node> adj[1005];
bool got[1005];
int d[1005];
int n;
void dijkstra(int s){
    memset(got, false, sizeof(got));
    fill(d,d+n+1,INF);
    d[s] = 0;
    int times = n;
    while(times--){
        int u;
        int min_d = INF;
        for(int j = 1;j<=n;j++){
            if(!got[j] && min_d > d[j]){
                min_d = d[j];
                u = j;
            }
        }
        //d[u] = min_d;
        got[u] = true;
        for(int j = 0;j<adj[u].size();j++){
            int v = adj[u][j].v;
//            int w = adj[u][j].w;//考虑重边的情况
            int w = edge[u][v];
            if(!got[v] && d[u] + w < d[v]){
                d[v] = d[u] + w;
            }
        }
    }
}

//这道题有重边。
int main(){
    int m;
    cin>>m>>n;
    fill(edge[0],edge[0] + 1005 * 1005,INF);
    while (m--){
        int u,v,w;
        cin>>u>>v>>w;
        Node tmp;
        tmp.v = v;
        tmp.w = w;
        adj[u].push_back(tmp);
        tmp.v = u;
        adj[v].push_back(tmp);
        if(edge[u][v] > w) edge[u][v] = w;
        if(edge[v][u] > w) edge[v][u] = w;
    }
    dijkstra(n);
    cout<<d[1]<<endl;
    return 0;
}

```