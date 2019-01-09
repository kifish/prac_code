http://algorithm.openjudge.cn/algorithmb/E/

https://blog.csdn.net/Tc_To_Top/article/details/44459605


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
#include <utility>
#include <cmath>
using namespace std;

const int N = 1005;
const double INF = 1000000000.0;
struct Node{
    int v;
    double dis;//存的花费时间
};

vector<Node> adj[N];
double edge[N][N];


double consume_time_subway(int x1,int y1,int x2,int y2){
    double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return dis / (40 * 1000) * 60;
}

double consume_time_walk(int x1,int y1,int x2,int y2){
    double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return dis / (10 * 1000) * 60;
}

map<pair<int,int>,int> map1;
map<int,pair<int,int>> map2;

int idx = 0;
int xy_to_id(int x,int y){
    pair<int,int> xy = make_pair(x,y);
    if(map1.count(xy) == 0){
        map1[xy] = idx;
        map2[idx++] = xy;
    }
    return map1[xy];
}


pair<int,int> id_to_xy(int i){
    return map2[i];
}

bool got[N];
double d[N];
void dijkstra(int s){
    memset(got, false, sizeof(got));
    fill(d,d+N,INF);
    d[s] = 0;
    int times = idx;
    while (times--){
        int u;
        double min_d = INF;
        for(int j = 0;j<idx;j++){
            if(!got[j] && d[j] < min_d){
                u = j;
                min_d = d[j];
            }
        }
        got[u] = true;
        for(int j = 0;j<adj[u].size();j++){
            int v = adj[u][j].v;
            double w = edge[u][v];
            if(!got[v] && d[u] + w < d[v]){
                d[v] = d[u] + w;
            }
        }
    }
}

int main(){
    pair<int,int> start,end;
    cin>>start.first>>start.second>>end.first>>end.second;
    xy_to_id(start.first,start.second);
    xy_to_id(end.first,end.second);
    fill(edge[0],edge[0] + N*N,INF);
    int x,y;
    while(cin>>x>>y){
        int start_idx = idx;
        xy_to_id(x,y);
        while (cin>>x>>y && !(x == -1 && y == -1)){
            xy_to_id(x,y);
        }
        int end_idx = idx -1;
        for(int i = start_idx + 1;i<=end_idx;i++){
            pair<int,int> pos1 = id_to_xy(i);
            pair<int,int> pos2 = id_to_xy(i-1);
            double w = consume_time_subway(pos1.first,pos1.second,pos2.first,pos2.second);
            Node tmp;
            int u = i;
            int v = i-1;
            tmp.v = v;
            tmp.dis = w;
            adj[u].push_back(tmp);
            tmp.v = u;
            adj[v].push_back(tmp);
            edge[u][v] = w;
            edge[v][u] = w;
        }
    }
    for(int u = 0;u<idx;u++){
        for(int v = u + 1;v<idx;v++){
            pair<int,int> pos1 = id_to_xy(u);
            pair<int,int> pos2 = id_to_xy(v);
            double w = consume_time_walk(pos1.first,pos1.second,pos2.first,pos2.second);
            if(edge[u][v] == INF){
                Node tmp;
                tmp.v = v;
                adj[u].push_back(tmp);
                tmp.v = u;
                adj[v].push_back(tmp);//本来没有边，要记得添加。
                edge[u][v] = w;
                edge[v][u] = w;
            }
            else if(w < edge[u][v]){ //同一条地铁线路的站点之间肯定比走路快。
                ;
            }
        }
    }
    dijkstra(0);
//    cout<<d[1]<<endl;
    printf("%d",(int)(d[1] + 0.5));
    return 0;
}
```