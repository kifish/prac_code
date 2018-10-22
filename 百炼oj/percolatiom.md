


这种写法可以正确判断是否存在一条路径连通网格的上端和下端。
但会出现backwash的问题，最下一行的的方格即使与virtual_top连通，也未必存在一条贯通路径通过该方格。不过出现backwash时，已经必然存在贯通路径了。


```c
#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Site{
    int row_idx,col_idx;
    int state;//0 closed, 1 open
    int parent;//siteID
}site[1002005];

void init(int n){
    for(int i = 0;i<=n*n+1;i++){
        site[i].state = 0;
        site[i].parent = i;
    }//也可以把virtual_top,virtual_bottom的state初始化为1
}


int find_root(int site_id){
    int raw = site_id;
    while(site[site_id].parent != site_id){
        site_id = site[site_id].parent;
    }
    int root = site_id;
    site_id = raw;
    while(site[site_id].parent != site_id){
        int tmp = site[site_id].parent;
        site[site_id].parent = root;
        site_id = tmp;
    }
    return root;
}

bool connected(int site_id1,int site_id2){
    return find_root(site_id1) == find_root(site_id2);
}

void union_site(int site_id1,int site_id2){
    int root1 = find_root(site_id1);
    int root2 = find_root(site_id2);
    if(root1 != root2){
        site[root1].parent = root2;
    }
}


int xy_to_1d(int x,int y,int n){
    return (x-1)*n + y;
}

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool valid(int x,int y,int n){
    if(x>=1 && x<= n && y>=1 && y<=n)
        return true;
    return false;
}
void print_sites(int n){
    cout<<site[0].state<<"-"<<find_root(0)<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<site[xy_to_1d(i,j,n)].state<<"-"<<find_root(xy_to_1d(i,j,n))<<"  ";
        }
        cout<<endl;
    }
    cout<<site[n*n+1].state<<"-"<<find_root(n*n+1)<<endl;
}
int main(){
    int t;
    cin>>t;
    int n,m;
    int x,y;
    int virtual_top;
    int virtual_bottom;
    int neighbour_x,neighbour_y;
    while(t--){
        cin>>n>>m;//n为边长
        init(n);
        virtual_top = 0;
        virtual_bottom = n*n + 1;
        int k = 0;
        int tmp = m;
        while(tmp--){
            cin>>x>>y;
            k++;
            site[xy_to_1d(x,y,n)].state = 1;
            if(x == 1){
                union_site(virtual_top,xy_to_1d(x,y,n));
            }
            else if(x == n){
                union_site(virtual_bottom,xy_to_1d(x,y,n));
            }
            for(int i = 0;i<4;i++){
                neighbour_x = x + dx[i];
                neighbour_y = y + dy[i];
                if(valid(neighbour_x,neighbour_y,n) && site[xy_to_1d(neighbour_x,neighbour_y,n)].state == 1){
                    union_site(xy_to_1d(x,y,n),xy_to_1d(neighbour_x,neighbour_y,n));
                }
            }
            if(connected(virtual_top,virtual_bottom)){
                break;
            }
        }
        if(k < m || (k == m && connected(virtual_top,virtual_bottom))){
            cout<<k<<endl;
            tmp = m-k;
            while(tmp--){
                cin>>x>>y;
            }
        }
        else
            cout<<"-1"<<endl;
//        print_sites(n);
    }
    return 0;
}
```