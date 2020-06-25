// 执行用时 :
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗 :
// 6.5 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m,vector<int> (n,1));
       for(int i = 0;i < m;i++){
           for(int j = 0;j < n;j++){
               if(i >= 1 && j >= 1){
                   dp[i][j] = dp[i-1][j] + dp[i][j-1];
               }
               else if(i >= 1 && j == 0){
                   dp[i][j] = dp[i-1][j];
               }
               else if(j >= 1 && i == 0){
                   dp[i][j] = dp[i][j-1];
               }
           }
       }
       return dp[m-1][n-1]; 
    }
};