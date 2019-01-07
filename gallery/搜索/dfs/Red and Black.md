http://bailian.openjudge.cn/practice/1979/

http://algorithm.openjudge.cn/betaexam/A/



```C
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
using namespace std;
int row_n,col_n;
char map[25][25];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int cnt;
bool visited[25][25];//一定要visited，不然dfs会死循环。
void dfs(int x,int y){
    visited[x][y] = true;
    if(map[x][y] == '.') cnt++;
    else return;
    for(int i = 0;i<4;i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x > row_n || new_x < 1 || new_y > col_n || new_y < 1){
            continue;
        }
        if(visited[new_x][new_y]) continue;
        dfs(new_x,new_y);
    }
}

int main(){
    int x,y;
    while(cin>>col_n>>row_n && !(col_n == 0 && row_n ==0)){
        for(int i = 1;i<=row_n;i++){
            for(int j = 1;j<=col_n;j++){
                cin>>map[i][j];
                if(map[i][j] == '@'){
                    x = i;
                    y = j;
                    map[i][j] = '.';
                }
            }
        }
        cnt = 0;
        memset(visited, false, sizeof(visited));
        dfs(x,y);
        cout<<cnt<<endl;
    }
    return 0;
}

```