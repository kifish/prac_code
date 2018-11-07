https://blog.csdn.net/logch/article/details/52996812

https://blog.csdn.net/mmc2015/article/details/50153739


```c
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

struct Node{
    int parent;//node_idx
    int relationship;//0表示和父类相同，1表示不同
}node[1005];

int find_root(int x){
    if(x == node[x].parent)
        return x;
    int parent = node[x].parent;
    node[x].parent = find_root(parent);
    if(node[x].relationship == node[parent].relationship)
        node[x].relationship = 0;
    else
        node[x].relationship = 1;
    return node[x].parent;
}
void init_sets(int n){
    for(int i = 0;i<n;i++){
        node[i].parent = i;
        node[i].relationship = 0;
    }
}

int main(){
    int n;
    int m;
    int a,b,r;

    while(scanf("%d %d",&n,&m) == 2){
        bool isvalid = true;
        init_sets(n);
        while(m--){
            scanf("%d %d %d",&a,&b,&r);
            int root_a = find_root(a);
            int root_b = find_root(b);
            if(root_a == root_b){
                if(r == 0){
                    if(node[a].relationship != node[b].relationship)
                        isvalid = false;
                }
                else if(r == 1){
                    if(node[a].relationship == node[b].relationship)
                        isvalid = false;
                }
            }
            else{
                node[root_b].parent = root_a;
                if(r == 0){
                    if(node[a].relationship == node[b].relationship)
                        node[root_b].relationship = 0;
                    else
                        node[root_b].relationship = 1;
                }
                else{
                    if(node[a].relationship == node[b].relationship)
                        node[root_b].relationship = 1;
                    else
                        node[root_b].relationship = 0;
                }
            }

        }
        if(isvalid)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
```


