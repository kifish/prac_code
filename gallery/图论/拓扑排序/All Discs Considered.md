http://algorithm.openjudge.cn/algorithmb/F/


https://blog.csdn.net/discreeter/article/details/69787419

10s+

TLE
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

const int N = 100005;
vector<int> adj[N];
int degree[N],raw_degree[N];

int n1,n2;
int n;

int install_from1(){
    int cnt = 0;
    queue<int> q;
    for(int i = 1;i <= n1;i++){
        if(degree[i] == 0){//可以安装
            q.push(i);
            degree[i]--;//避免再次进入队列
        }
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        for(int j = 0;j < adj[u].size();j++){
            int v = adj[u][j];
            degree[v]--;
            if(degree[v] == 0){
                if(v <= n1){
                    q.push(v);
                    degree[v]--;//避免再次进入队列，当然也可以用一个bool数组维护。
                }
            }
        }
    }
    return cnt;
}

int install_from2(){
    int cnt = 0;
    queue<int> q;
    for(int i = n1 + 1;i <= n;i++){
        if(degree[i] == 0){//可以安装
            q.push(i);
            degree[i]--;//避免再次进入队列
        }
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        for(int j = 0;j < adj[u].size();j++){
            int v = adj[u][j];
            degree[v]--;
            if(degree[v] == 0){
                if(v >= n1 + 1){
                    q.push(v);
                    degree[v]--;//避免再次进入队列，当然也可以用一个bool数组维护。
                }
            }
        }
    }
    return cnt;
}

int main(){
    int m;
    while (cin>>n1>>n2>>m){
        if(n1 == 0 && n2 == 0 && m == 0) break;
        n = n1 + n2;
        memset(raw_degree,0, sizeof(raw_degree));
        for(int i = 1;i<=n;i++) adj[i].clear();
        while(m--){
            int u,v;
            cin>>u>>v;//u 需要 v先安装
            adj[u].push_back(v);
            raw_degree[v]++;
        }
        memcpy(degree, raw_degree, sizeof(degree));
        int pkg_install_n = 0;
        int times = 0;
        while (true){
            pkg_install_n += install_from1();
            times++;
            if(pkg_install_n == n) break;
            pkg_install_n += install_from2();
            times++;
            if(pkg_install_n == n) break;
        }

        memcpy(degree, raw_degree, sizeof(degree));
        pkg_install_n = 0;
        int times2 = 0;
        while (true){
            pkg_install_n += install_from2();
            times2++;
            if(pkg_install_n == n) break;
            pkg_install_n += install_from1();
            times2++;
            if(pkg_install_n == n) break;
        }
        int res = min(times,times2);
        res += 1;//拔出最后的光盘算一次.
        cout<<res<<endl;
    }
    return 0;
}
```


254ms

AC
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

const int N = 100005;
vector<int> adj[N];
int degree[N],raw_degree[N];

int n1,n2;
int n;

queue<int> q1;
queue<int> q2;

void init(){
    for(int i = 1;i<=n;i++){
        if(degree[i] == 0) {
            if(i <= n1)
                q1.push(i);
            else
                q2.push(i);
        }
    }
}
int install_from1(){
    int cnt = 0;
    while (!q1.empty()){
        int u = q1.front();
        q1.pop();
        cnt++;
        for(int j = 0;j < adj[u].size();j++){
            int v = adj[u][j];
            degree[v]--;
            if(degree[v] == 0){
                if(v <= n1){
                    q1.push(v);
                    degree[v]--;//避免再次进入队列，当然也可以用一个bool数组维护。;当然这种写法不--也是可以的。
                }
                else{
                    q2.push(v);
                    degree[v]--;
                }
            }
        }
    }
    return cnt;
}

int install_from2(){
    int cnt = 0;
    while (!q2.empty()){
        int u = q2.front();
        q2.pop();
        cnt++;
        for(int j = 0;j < adj[u].size();j++){
            int v = adj[u][j];
            degree[v]--;
            if(degree[v] == 0){
                if(v >= n1 + 1){
                    q2.push(v);
                    degree[v]--;
                }
                else{
                    q1.push(v);
                    degree[v]--;
                }
            }
        }
    }
    return cnt;
}

int main(){
    int m;
    while (cin>>n1>>n2>>m){
        if(n1 == 0 && n2 == 0 && m == 0) break;
        n = n1 + n2;
        memset(raw_degree,0, sizeof(raw_degree));
        for(int i = 1;i<=n;i++) adj[i].clear();
        while(m--){
            int u,v;
            cin>>u>>v;//u 需要 v先安装
            adj[u].push_back(v);
            raw_degree[v]++;
        }

        memcpy(degree, raw_degree, sizeof(degree));
        init();
        int pkg_install_n = 0;
        int times = 0;
        while (true){
            pkg_install_n += install_from1();
            times++;
            if(pkg_install_n == n) break;
            pkg_install_n += install_from2();
            times++;
            if(pkg_install_n == n) break;
        }

        memcpy(degree, raw_degree, sizeof(degree));
        init();
        pkg_install_n = 0;
        int times2 = 0;
        while (true){
            pkg_install_n += install_from2();
            times2++;
            if(pkg_install_n == n) break;
            pkg_install_n += install_from1();
            times2++;
            if(pkg_install_n == n) break;
        }
        int res = min(times,times2);
        res += 1;//拔出最后的光盘算一次.
        cout<<res<<endl;
    }
    return 0;
}
```


