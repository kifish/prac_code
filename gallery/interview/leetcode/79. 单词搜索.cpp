// WA 
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// "ABCB"

// class Solution {
// public:
//     struct Node
//     {   int x;
//         int y;
//         int idx;
//         Node(int x_,int y_,int idx_): x(x_),y(y_),idx(idx_){}
//     };
//     string word_str;
//     vector<vector<vector<bool>>> was_in_q;
//     int m,n;
//     bool is_valid(int x,int y, int idx, vector<vector<char>>& board, string& word){
//         if(x >= m || x < 0 || y >= n || y < 0){
//             return false;
//         }
//         if(word[idx] != board[x][y]){
//             return false;
//         }
//         return true;
//     }

//     int dx[4] = {-1,0,1,0};
//     int dy[4] = {0,1,0,-1};

//     bool bfs(vector<vector<char>>& board, string& word){
//         queue<Node> q;
//         for(int i = 0;i<m;i++){
//             for(int j = 0;j<n;j++){
//                 if(board[i][j] == word[0]){
//                     q.push(Node(i,j,0));
//                     was_in_q[i][j][0] = true;
//                 }
//             }
//         }
//         while(!q.empty()){
//             Node tmp = q.front();
//             q.pop();
//             for(int i = 0;i<4;i++){
//                 int new_x = tmp.x + dx[i];
//                 int new_y = tmp.y + dy[i];
//                 if(is_valid(new_x,new_y,tmp.idx+1, board, word)){
//                     if(tmp.idx+1 == (int)word.size() - 1){
//                         return true;
//                     }

//                     if(!was_in_q[new_x][new_y][tmp.idx+1]){
//                         q.push(Node(new_x,new_y,tmp.idx+1));
//                         was_in_q[new_x][new_y][tmp.idx+1] = true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         m = board.size();
//         if(m == 0) return false;
//         n = board[0].size();
//         was_in_q = vector<vector<vector<bool>>> (m, vector<vector<bool>> (n, vector<bool> (word.size(), false)));
//         return bfs(board, word);
//     }
// };


// class Solution {
// public:
//     struct Node
//     {   int x;
//         int y;
//         int idx;
//         Node(int x_,int y_,int idx_): x(x_),y(y_),idx(idx_){}
//     };
//     vector<vector<vector<bool>>> was_in_q;
//     int m,n;
//     bool is_valid(int x,int y, int idx, vector<vector<char>>& board, string& word){
//         if(x >= m || x < 0 || y >= n || y < 0){
//             return false;
//         }
//         if(word[idx] != board[x][y]){
//             return false;
//         }
//         return true;
//     }

//     int dx[4] = {-1,0,1,0};
//     int dy[4] = {0,1,0,-1};

//     bool bfs_search(vector<vector<char>>& board, string& word){
//         for(int i = 0;i<m;i++){
//             for(int j = 0;j<n;j++){
//                 if(bfs(i,j, board, word)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }



//     bool bfs(int s_x, int s_y, vector<vector<char>>& board, string& word){
//         queue<Node> q;
//         for(int i = 0;i<m;i++){
//             for(int j = 0;j<n;j++){
//                 for(int k = 0;k<word.size();k++){
//                     was_in_q[i][j][k] = false;
//                 }
//             }
//         }

//         if(board[s_x][s_y] == word[0]){
//             if(word.size() == 1){
//                 return true;
//             }
//             q.push(Node(s_x,s_y,0));
//             was_in_q[s_x][s_y][0] = true;
//             was_in_q[s_x][s_y][(int) word.size() - 1] = true; // 这个位置正常访问永远不会被访问到。因此借用这个位置，表示s_x s_y idx 0-(int)word.size()-2 存在 被访问到
//         }
            
//         while(!q.empty()){
//             Node tmp = q.front();
//             q.pop();
//             for(int i = 0;i<4;i++){
//                 int new_x = tmp.x + dx[i];
//                 int new_y = tmp.y + dy[i];
//                 if(is_valid(new_x,new_y,tmp.idx+1, board, word)){
//                     if(tmp.idx+1 == (int)word.size() - 1 && was_in_q[new_x][new_y][(int) word.size() - 1] == false){
//                         return true;
//                     }

//                     if(!was_in_q[new_x][new_y][tmp.idx+1]){
//                         q.push(Node(new_x,new_y,tmp.idx+1));
//                         was_in_q[new_x][new_y][tmp.idx+1] = true;
//                         was_in_q[new_x][new_y][(int) word.size() - 1] = true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         m = board.size();
//         if(m == 0) return false;
//         n = board[0].size();

//         was_in_q = vector<vector<vector<bool>>> (m, vector<vector<bool>> (n, vector<bool> (word.size(), false)));
//         return bfs_search(board, word);
//     }
// };

// 其实应该用dfs
// 原因见文档https://docs.google.com/document/d/131fNEPa1tRaCi0tvYqDW0N5ucz_cF9HfKwnVmDHhkDY/edit。
// bfs必须要回溯恢复现场, 写起来估计麻烦。

// 这道题字节考过
// 感觉bfs方便求最优, dfs求的是存在性问题


// 执行用时 :
// 36 ms
// , 在所有 C++ 提交中击败了
// 66.77%
// 的用户
// 内存消耗 :
// 8.6 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    vector<vector<bool>> used;

    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,1,-1,0};
    int m,n;
    bool can_be_reached = false;

    bool is_valid(int x, int y, int idx, vector<vector<char>> & board, string & word){
        if(x >= m || x < 0 || y >= n || y < 0){
            return false;
        }
        if(used[x][y]){
            return false;
        }
        if(word[idx] != board[x][y]){
            return false;
        }
        return true;
    }

    void dfs(int x, int y, int idx, vector<vector<char>> & board, string & word){

        // necessary
        // 这里的实现用了全局标记有可能已经搜寻完了还在搜寻从而导致TLE
        if(can_be_reached) return;

        for(int i = 0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(is_valid(new_x, new_y, idx+1, board, word)){
                if(idx+1 == word.size() - 1){
                    can_be_reached = true;
                    return;
                }

                used[new_x][new_y] = true;
                dfs(new_x,new_y,idx+1,board, word);
                used[new_x][new_y] = false; // 恢复现场
            }
        }
    }
    bool dfs_search(vector<vector<char>>& board, string& word){
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(word.size() == 1) return true;

                    used[i][j] = true;
                    dfs(i,j,0,board, word);
                    if(can_be_reached) return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if(m == 0) return false;
        n = board[0].size();
        used = vector<vector<bool>> (m, vector<bool> (n, false));
        return dfs_search(board, word);
    }
};