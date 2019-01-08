http://algorithm.openjudge.cn/2016finalex/G/


https://www.cnblogs.com/kuangbin/archive/2012/08/17/2644807.html



有负权边的图中求正环。

```C
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


int n;
const int INF = 0x3fffffff;
double d[105];
struct Node{
    int v;
    double rate;
    double c;//手续费
};
vector<Node> adj[105];

bool bf(int s, double init_val){
    for(int i = 1;i<=n;i++) d[i] = 0;
    d[s] = init_val;
    int times = n - 1;
    while(times--){
        bool relaxed = false;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<adj[i].size();j++){
                int v = adj[i][j].v;
                double rate = adj[i][j].rate;
                double c = adj[i][j].c;
                if(d[v] < (d[i] - c) * rate){
                    relaxed = true;
                    d[v] = (d[i] - c) * rate;
                }
            }
        }
        if(!relaxed) return false;//无正环
    }
    bool relaxed = false;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<adj[i].size();j++){
            int v = adj[i][j].v;
            double rate = adj[i][j].rate;
            double c = adj[i][j].c;
            if(d[v] < (d[i] - c) * rate){
                relaxed = true;
                d[v] = (d[i] - c) * rate;
            }
        }
    }
    if(!relaxed) return false;//无正环
    return true;//有正环，可以套利。
}

int main(){
    int m;
    int s;
    double V;
    cin>>n>>m>>s>>V;
    while (m--){
        int u,v;
        double rate,c;
        cin>>u>>v;
        cin>>rate>>c;
        Node tmp;
        tmp.v = v;
        tmp.rate = rate;
        tmp.c = c;
        adj[u].push_back(tmp);
        cin>>rate>>c;
        tmp.v = u;
        tmp.rate = rate;
        tmp.c = c;
        adj[v].push_back(tmp);
    }
    bool res = bf(s,V);
    if(res)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

```



