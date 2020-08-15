#include<bits/stdc++.h>


typedef long long LL;
// or #define LL long long

using namespace std;


void print_vec(vector<int> & v){
    for(auto val : v){
        cout<<val<<" ";
    }
    cout<<endl;
}

const int mod = 1e9 + 7;

int n; // row
int m; // col



vector<vector<char>> M(505,vector<char>(505, 'a'));


vector<vector<bool>> vis(505,vector<bool>(505, false));

vector<vector<int>> dis(505,vector<int>(505, 0));


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
    if(vis[x][y]) return false;
    return true;
}


int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

int get_dis(int sx,int sy, int ex, int ey){

    Node tmp;
    tmp.x = sx;
    tmp.y = sy;
    tmp.cur_dis = 0;
    queue<Node> q;
    q.push(tmp);
    vis[sx][sy] = true;

    int ret;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            int new_x = tmp.x + dx[i];
            int new_y = tmp.y + dy[i];
            if(valid(new_x, new_y)){
                int new_dis = tmp.cur_dis;
                if(M[tmp.x][tmp.y] == 'C'){ // LUDI
                    if(M[new_x][new_x] == 'C'){ // new_x new_x; shit :)
                        new_dis += 3;
                    }
                    else new_dis += 5;
                }

                else{
                    if(M[new_x][new_x] == 'S'){ // new_x new_x; shit :)
                        new_dis += 2;
                    }
                    else new_dis += 5;
                }
                if(new_x == ex && new_y == ey){
                    ret = new_dis;
                    break;
                }
                tmp.x = new_x;
                tmp.y = new_y;
                tmp.cur_dis = new_dis;
                q.push(tmp);
                vis[new_x][new_y] = true;
            }
        }
    }
    return ret;
}




void init(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            vis[i][j] = false;
            dis[i][j] = 0;
        }
    }
}


int main() {

	std::ios::sync_with_stdio(false);

    int q;
    while (cin>>n>>m>>q)
    {   
        M.clear();
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>M[i][j];
                vis[i][j] = false;
                dis[i][j] = 0;
            }
        }


        while(q--){
            int sx,sy,ex,ey;
            cin>>sx>>sy>>ex>>ey;
            init();
            int ret = get_dis(sx,sy,ex,ey);
            cout<<ret<<endl;
        }
       
    }

	return 0;
}




