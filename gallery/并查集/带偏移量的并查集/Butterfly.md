https://blog.csdn.net/logch/article/details/52996812

https://blog.csdn.net/mmc2015/article/details/50153739


详见：
http://cavenkaka.iteye.com/blog/1489588

要理解这里集合的意思，若两个点之间有边，则该两点为同一个集合，但该两点可能不是同一类。
是否是同一类需要根据与根的偏移距离来判断，偏移距离为0，则为同一类，为1则为不同类。



但以下这个版本还是不好理解。
AC
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







AC
508ms

这个版本非常好理解了，不过比上一个版本多了150ms，估计是因为 %2 的耗时有点大。

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

struct Node{
    int parent;//node_idx
    int offset;//表示与父节点（不是根节点）的偏移距离，0，即相同.
}node[1005];

int find_root(int x){
    if(x == node[x].parent)
        return x;
    int parent = node[x].parent;
    node[x].parent = find_root(parent);
    node[x].offset = (node[x].offset + node[parent].offset) % 2;//从根节点然后往下计算，因此保证了正确性。
    return node[x].parent;                                      //事实上，如果这样递推计算之后，offset已经是与根节点的偏移距离
}
void init_sets(int n){
    for(int i = 0;i<n;i++){
        node[i].parent = i;
        node[i].offset = 0;
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
            if(root_a == root_b){//在同一个集合中，那么 判断是否为同一类。
                if(r == 0){
                    if(node[a].offset != node[b].offset)
                        isvalid = false;
                }
                else if(r == 1){
                    if(node[a].offset == node[b].offset)
                        isvalid = false;
                }
            }
            else{ //由于已经find_root过，因此node[a].offset代表node[a]相对于root_a的偏移距离（当然对于父节点也是成立的）
                node[root_b].parent = root_a;
                node[root_b].offset = (0  - node[b].offset + r + node[a].offset + 2) % 2;
                //0-node[b].offset 是root_b相对于b的距离， r是b相对于a的距离，node[a].offset是node[a]相对于root_a的距离
                //加2是防止出现负数，保证和为-1其实是与1等价的。
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

