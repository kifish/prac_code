

/*

https://leetcode-cn.com/explore/interview/card/bytedance/246/dynamic-programming-or-greedy/1028/


https://leetcode-cn.com/problems/maximal-square/


题解:
https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode-solution/

*/

// https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode-solution/


// 这个转移方程怎么推出来？

// 自己画个9宫格
// 0 1 1
// 1 1 1
// 1 1 1


// 执行用时 :
// 16 ms
// , 在所有 C++ 提交中击败了
// 95.21%
// 的用户
// 内存消耗 :
// 9 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int max_side = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                        max_side = max(max_side, dp[i][j]);
                    }
                    else{
                        dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]), dp[i-1][j-1]) + 1;
                        max_side = max(max_side, dp[i][j]);
                    }
                }
            }
        }
        return max_side*max_side;
    }
};