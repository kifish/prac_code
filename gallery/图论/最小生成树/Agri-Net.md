http://algorithm.openjudge.cn/201802/E/

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

struct Edge{
    int a;
    int b;
    int cost;
}edge[10005];

int parent[105];
int find_root(int x){
    if(parent[x] == x)
        return x;
    parent[x] = find_root(parent[x]);
    return parent[x];
}

//int G[105][105];
//void init(int n){
//    for(int i = 0;i<n;i++){
//        for(int j = 0;j<n;j++)
//            G[i][j] = 0;
//    }
//}

void init(int n){
    for(int i = 0;i<n;i++)
        parent[i] = i;
}
bool cmp(Edge &a,Edge &b){
    return a.cost < b.cost;
}
int main(){
    int n;
    int num;
    while(cin>>n){
        int idx = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>num;
                if(i <= n-1 && j >= i + 1){//上三角输入
                    edge[idx].a = i;
                    edge[idx].b = j;
                    edge[idx].cost = num;
                    idx++;
                }
            }
        }
        sort(edge,edge+idx,cmp);
        int sum = 0;
        init(n);
        for(int i = 0;i<idx;i++){
            int a = edge[i].a;
            int b = edge[i].b;
            int cost = edge[i].cost;
            int root_a = find_root(a);
            int root_b = find_root(b);
            if(root_a != root_b){
                sum += cost;
                parent[root_a] = root_b;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
```

