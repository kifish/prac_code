#include<bits/stdc++.h>
using namespace std;

/*


bfs能解最短路吗?
看起来解决不了啊

仔细研究了下2,3,5 的数值设置

如果能多次入队，那么是可以解决最短路的。

改成可多次入队就好了, 以前没写过这种题型。


多次查询有办法优化吗?

改成floyd?
n^3
n为顶点数, 最多500, 可能不会超时


*/


int n; // row
int m; // col



vector<vector<char>> M(505,vector<char>(505, 'a'));

vector<vector<int>> dis(505,vector<int>(505, INT_MAX));

struct Point
{
   int x;
   int y;
   Point(int x,int y):x(x),y(y){}
};

vector<vector<Point>> pre(505,vector<Point>(505, Point(0,0)));

struct Node
{
    int x;
    int y;
    int cur_dis; // from start
};


bool valid(int x,int y){
    if(x < 1 || x > n || y < 1 || y > m){
        return false;
    }
    return true;
}


int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};




void init(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            dis[i][j] = INT_MAX;
            pre[i][j] = Point(i,j); // debug
        }
    }
}


int get_dis(int sx,int sy, int ex, int ey){
    init();
    Node tmp;
    tmp.x = sx;
    tmp.y = sy;
    tmp.cur_dis = 0;
    queue<Node> q;
    q.push(tmp);
    dis[sx][sy] = 0;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int new_x = tmp.x + dx[i];
            int new_y = tmp.y + dy[i];
            if(valid(new_x, new_y)){
                int new_dis = tmp.cur_dis;
                if(M[tmp.x][tmp.y] == 'C'){ // 陆地
                    if(M[new_x][new_y] == 'C'){
                        new_dis += 3;
                    }
                    else new_dis += 5;
                }
                else{
                    if(M[new_x][new_y] == 'S'){
                        new_dis += 2;
                    }
                    else new_dis += 5;
                }

                if(new_dis < dis[new_x][new_y]){
                    tmp.x = new_x;
                    tmp.y = new_y;
                    tmp.cur_dis = new_dis;
                    dis[new_x][new_y] = new_dis;
                    q.push(tmp);

                    // debug

                }
            }
        }
    }
    return dis[ex][ey];
}



void traceback(int ex, int ey){
    cout<<"("<<ex<<","<<ey<<")";

    while (!(ex == pre[ex][ey].x && ey == pre[ex][ey].y))
    {
        cout<<"->";
        cout<<"("<<pre[ex][ey].x<<","<<pre[ex][ey].y<<")";
        ex = pre[ex][ey].x;
        ey = pre[ex][ey].y;
    }
}





int main() {

	std::ios::sync_with_stdio(false);

    int q;
    while (cin>>n>>m>>q)
    {   
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>M[i][j];
            }
        }

        while(q--){
            int sx,sy,ex,ey;
            cin>>sx>>sy>>ex>>ey;
            int ret = get_dis(sx,sy,ex,ey);
            traceback(ex,ey);
            cout<<ret<<endl;
        }
    }

	return 0;
}




/*

4 4 2
CCCS
SSSS
CSCS
SSCC
1 1 3 4
3 1 1 3

*/