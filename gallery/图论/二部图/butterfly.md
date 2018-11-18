Jon Kleinberg著《Algorithm Design》第3章图论课后习题第4题，英文原版第107页
http://algorithm.openjudge.cn/algorithmb/

https://blog.csdn.net/wr339988/article/details/53739056

`#include<bits/stdc++.h>`
POJ支持这样的写法，但是clion不支持。

二部图染色

```
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int edge[1005][1005];//egde[a][b]可取三个值，0表示未知，1表示相同，2表示不同
int color[1005];//0未知，1red，2black
bool visited[1005];
bool valid;
queue<int> q;
int n,m;
//wrong bfs
//bool bfs(int node){
//    if(visited[node]) return true;
//    visited[node] = 1;
//    if(!color[node]) color[node] = 1;//未上色，则上色为red
//    for(int i = 0;i<n;i++){
//        if(edge[node][i] == 1){//蝴蝶颜色相同
//            if(!color[i]) color[i] = color[node];
//            else{
//                if(color[i] != color[node]){
////                    printf("edge:1\n");
////                    printf("here: %d %d\n",node,i);
////                    printf("color %d:%d;%d:%d",node,color[node],i,color[i]);
//                    return false;
//                }
//                else{
//                    if(!visited[i])
//                        q.push(i);
//                }
//            }
//        } else if (edge[node][i] == 2){//蝴蝶颜色不同
//            if(!color[i]) color[i] = 3 - color[node];//不能写成 = 2
//            else{
//                if(color[i] == color[node]){
////                    printf("edge:2\n");
////                    printf("here: %d %d\n",node,i);
////                    printf("color %d:%d;%d:%d\n",node,color[node],i,color[i]);
//                    return false;
//                }
//                else{
//                    if(!visited[i])
//                        q.push(i);
//                }
//            }
//        }
//    }
//    return true;
//}

//true bfs
bool bfs(int node){
    if(visited[node]) return true;
    visited[node] = 1;
    if(!color[node]) color[node] = 1;//未上色，则上色为red
    for(int i = 0;i<n;i++){
        if(edge[node][i] == 1){//蝴蝶颜色相同
            if(!color[i]) color[i] = color[node];
            else{
                if(color[i] != color[node]){
//                    printf("edge:1\n");
//                    printf("here: %d %d\n",node,i);
//                    printf("color %d:%d;%d:%d",node,color[node],i,color[i]);
                    return false;
                }
            }
            //note: 无论蝴蝶是原来没有颜色现在被染色了还是已经有颜色了，都是要加入待访问队列的!
            //只要没有被访问过，都是要加入待访问队列的!
            if(!visited[i])
                q.push(i);
        } else if (edge[node][i] == 2){//蝴蝶颜色不同
            if(!color[i]) color[i] = 3 - color[node];//不能写成 = 2
            else{
                if(color[i] == color[node]){
//                    printf("edge:2\n");
//                    printf("here: %d %d\n",node,i);
//                    printf("color %d:%d;%d:%d\n",node,color[node],i,color[i]);
                    return false;
                }
            }
            if(!visited[i])
                q.push(i);
        }
    }
    return true;
}

//true bfs
//bool bfs(int node)
//{
//    if(visited[node])   return true;
//    visited[node]=1;
//    if(!color[node])    color[node]=1;
//    for(int i=0;i<n;i++){
//        if(edge[node][i]==2){
//            if(!color[i])   color[i]=3-color[node];
//            else if(color[i]==color[node]){
//                return false;
//            }
//            if(!visited[i])  q.push(i);
//        }
//        else if(edge[node][i]==1){
//            if(!color[i])   color[i]=color[node];
//            else if(color[i]!=color[node]){
//                return false;
//            }
//            if(!visited[i])  q.push(i);
//        }
//    }
//    return true;
//}

int main() {
    int a,b,w;
    while (scanf("%d%d",&n,&m) == 2){
        valid = true;
        while(!q.empty()) q.pop();
        memset(edge,0,sizeof(edge));
        memset(color,0,sizeof(color));
        memset(visited,0,sizeof(visited));
        while(m--){
            scanf("%d %d %d",&a,&b,&w);
            w += 1;// offset
            edge[a][b] = w;
            edge[b][a] = w;
        }
        for(int i = 0;i<n;i++){
            //可能有多个连通子图
            if(!visited[i])
                q.push(i);

            while(!q.empty()){
                int cur_node = q.front();
                q.pop();
                valid = bfs(cur_node);
                if(!valid)
                    break;
            }

            if(!valid)
                break;
        }
        if(valid)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
```


