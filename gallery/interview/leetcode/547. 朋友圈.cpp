
/*


https://leetcode-cn.com/problems/friend-circles/

https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1036/



floyd 
并查集

dfs 联通分量

应该都可以

新名字 
547. 省份数量

https://leetcode-cn.com/problems/number-of-provinces/



*/

//dfs 简洁一点
// WA
// class Solution {
// public:
//     int m,n;
//     vector<vector<bool>> visited;
//     void dfs(vector<vector<int>> & M, int x, int y){
//         visited[x][y] = true; // x: from; y: target
//         visited[y][x] = true;
//         for(int i = 0;i<M[x].size();i++){
//             int f = M[x][i];
//             if(f == 1 && !visited[x][i]){
//                 dfs(M,x,i);
//             }
//         }
//     }
//     int dfs_search(vector<vector<int>> & M){
//         int cnt = 0; //连通分量
//         for(int i = 0; i<M.size(); i++){
//             for(int j = i;j<M[i].size();j++){
//                 if(!visited[i][j]){
//                     dfs(M,i,j);
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }

//     int findCircleNum(vector<vector<int>>& M) {
//         if(M.size() == 0) return 0;
//         m = M.size();
//         n = M[0].size();
//         visited = vector<vector<bool>> (m, vector<bool>(n, false));
//         return dfs_search(M);
//     }
// };


// 执行结果：
// 通过
// 显示详情
// 执行用时：
// 40 ms
// , 在所有 C++ 提交中击败了
// 93.21%
// 的用户
// 内存消耗：
// 12.2 MB
// , 在所有 C++ 提交中击败了
// 9.09%
// 的用户


class Solution {
public:
    int m,n;
    vector<bool> visited;
    void dfs(vector<vector<int>> & M, int x){
        visited[x] = true; // x: from
        for(int i = 0;i<M[x].size();i++){
            int f = M[x][i];
            if(f == 1 && !visited[i]){
                dfs(M,i);
            }
        }
    }

    int dfs_search(vector<vector<int>> & M){
        int cnt = 0; //连通分量
        for(int i = 0; i<M.size(); i++){
            if(!visited[i]){
                dfs(M,i);
                cnt++;
            }
        }
        return cnt;
    }

    int findCircleNum(vector<vector<int>>& M) {
        if(M.size() == 0) return 0;
        m = M.size();
        n = M[0].size();// 实际上m == n
        visited = vector<bool> (m, false);
        return dfs_search(M);
    }
};
