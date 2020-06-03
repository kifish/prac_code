
// 执行用时 :
// 4 ms
// , 在所有 C++ 提交中击败了
// 99.19%
// 的用户
// 内存消耗 :
// 8.7 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        for(int j = 0;j<n;j++){
            if(j == 0){
                dp[0][j] = grid[0][j];
            }
            else{
                dp[0][j] = dp[0][j-1] + grid[0][j];
            }
        }
        for(int i = 1;i<m;i++){
            for(int j = 0;j<n;j++){
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};














// class Solution {
// public:
//     int opt_val = 1<<31 - 1;
//     int dx[] = {0,1};
//     int dy[] = {-1,0};
//     bool valid(int x,int y){

//     }
//     // 求最优? 是否应该用bfs求?
//     void dfs(int x, int y, int sum){
//         for(int i = 0;i < 2;i++){
//             int new_x = x + dx[i];
//             int new_y = y+ dy[i];

//         }
//     }
//     int minPathSum(vector<vector<int>>& grid) {
        
//     }
// };