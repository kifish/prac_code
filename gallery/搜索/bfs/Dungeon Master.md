```C
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    char c;
    int x,y,z;
    int level = -1;
};
Node maze[35][35][35];
int height,row,col;

int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {1,-1,0,0,0,0};

bool was_in_queue[35][35][35];

bool is_valid(int x,int y,int z){
    if(was_in_queue[x][y][z]) return false;
    if(x > row || x < 1 || y > col || y < 1 || z > height || z < 1) return false;
    if(maze[x][y][z].c != '.') return false;
    return true;
}
void bfs(int x,int y,int z){
    maze[x][y][z].level = 0;
    queue<Node> q;
    q.push(maze[x][y][z]);
    was_in_queue[x][y][z] = true;
    while (!q.empty()){
        Node cur_node = q.front();
        q.pop();
        x = cur_node.x;//一开始忘记加这三行了，导致x,y,z一直是起始点的坐标。 // 2020-07-31回顾, 看来一开始写bfs的时候就犯过这个错误
        y = cur_node.y;
        z = cur_node.z;
        for(int i = 0;i<6;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            int new_z = z + dz[i];
            if(is_valid(new_x,new_y,new_z)){
                maze[new_x][new_y][new_z].level = cur_node.level + 1;
                q.push(maze[new_x][new_y][new_z]);
                was_in_queue[new_x][new_y][new_z] = true;
            }
        }
    }
}
int main(){
    while (cin>>height>>row>>col && !(height==0 && row == 0 && col == 0)){
        int s_x,s_y,s_z;
        int e_x,e_y,e_z;
        for(int k = 1;k <= height;k++){
            for(int i = 1;i<=row;i++){
                for(int j = 1;j<=col;j++){
                    cin>>maze[i][j][k].c;
                    maze[i][j][k].x = i;
                    maze[i][j][k].y = j;
                    maze[i][j][k].z = k;
                    if(maze[i][j][k].c == 'S'){
                        s_x = i;
                        s_y = j;
                        s_z = k;
                    }
                    else if(maze[i][j][k].c == 'E'){
                        e_x = i;
                        e_y = j;
                        e_z = k;
                        maze[i][j][k].c = '.';
                    }
                }
            }
        }
        memset(was_in_queue, false, sizeof(was_in_queue));
        bfs(s_x,s_y,s_z);
        if(maze[e_x][e_y][e_z].level == -1){
            cout<<"Trapped!"<<endl;
        }
        else{
            cout<<"Escaped in "<<maze[e_x][e_y][e_z].level<<" minute(s)."<<endl;
        }
    }
    return 0;
}
```


