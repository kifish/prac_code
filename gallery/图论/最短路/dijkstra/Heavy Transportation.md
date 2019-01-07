最短路变形。
就是把找最短路节点和relax的运算符改一下而已。

这个算法也可用于网络流中找最大的增广路径。

http://bailian.openjudge.cn/practice/1797/

http://algorithm.openjudge.cn/betaexam/E/





```C
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


struct Node{
    int v;
    int cap;
};
vector<Node> adj[1005];
const int INF = 0x3fffffff;
int d[1005];//从s到i的路径上中瓶颈容量最大的那条路径的瓶颈容量
bool got[1005];
int n;
void dijkstra(int s){
    memset(got, false, sizeof(got));
    memset(d,-1, sizeof(d));
    d[s] = INF;
    int times = n;
    while (times--){
        int max_idx;
        int max_cap = -1;
        for(int j = 1;j<=n;j++){
            if(!got[j] && d[j] > max_cap){
                max_cap = d[j];
                max_idx = j;
            }
        }
        int u = max_idx;
        got[u] = true;
        d[u] = max_cap;
        for(int i = 0;i<adj[u].size();i++){
            int v = adj[u][i].v;
            if(got[v]) continue;
            int cap = adj[u][i].cap;
            int path_cap = min(d[u],cap);//u作为中间节点；与不使用u作为中间节点的情况比较
            d[v] = max(d[v],path_cap);//relax
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int i= 1;i<=t;i++){
        cin>>n;
        int m;
        cin>>m;
        Node tmp;
        int u,v,cap;
        for(int j = 1;j<=n;j++) adj[j].clear();
        while (m--){
            cin>>u>>v>>cap;
            tmp.v = v;
            tmp.cap = cap;
            adj[u].push_back(tmp);
            tmp.v = u;
            adj[v].push_back(tmp);
        }
        dijkstra(1);
        cout<<"Scenario #"<<i<<":"<<endl;
        cout<<d[n]<<endl;
        cout<<endl;
    }
    return 0;
}

```