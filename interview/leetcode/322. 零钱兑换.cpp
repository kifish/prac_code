
/*

你可以认为每种硬币的数量是无限的。

*/

// #include <iomanip>




// 估计转移的逻辑有点问题
// WA
// [3,7,405,436]
// 8839
// 输出
// 29
// 预期结果
// 25


// 不用INT_MAX 初始化 写起来太麻烦了
// 重新实现一版

// class Solution {
// public:
//     void print(vector<vector<int>> dp){
//         cout<<"    ";
//         for(int j = 0;j <= 11;j++){
//             cout<<setw(2)<<j<<" ";
//         }
//         cout<<endl;
        
//         for(int i = 0;i< dp.size();i++){
//             // cout<<"consider to te index : "<<i<<endl;
//             cout<<setw(2)<<i<<" |";
//             for(int j = 0;j<dp[i].size();j++){
//                 cout<<setw(2)<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         if(coins.size() == 0) return -1;

//         vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
//         for(int i = 0;i<coins.size();i++){
//             dp[i][0] = 0;
//         }
//         for(int j = 1;j <= amount;j++){
//             if(j % coins[0] == 0){
//                 dp[0][j] = j / coins[0];
//             }
//         }

//         for(int i = 1;i<coins.size();i++){
//             for(int j = 1;j<= amount;j++){
//                 dp[i][j] = dp[i-1][j]; // 最坏的情况
//                 if(j - coins[i] >= 0){
//                     if(dp[i][j] == -1){ // 这个实现的错误原因估计在这个分支上, 这个url里实现的要清晰一点, 可以参考: https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-eric-345/
//                         int tmp1 = INT_MAX;
//                         if(dp[i-1][j-coins[i]] != -1)
//                             tmp1 = dp[i-1][j-coins[i]] + 1;
//                         int tmp2 = INT_MAX;
//                         if(dp[i][j-coins[i]] != -1)
//                             tmp2 = dp[i][j-coins[i]] + 1;
//                         int min_val = min(tmp1,tmp2);
//                         if(min_val != INT_MAX)
//                             dp[i][j] = min_val;

//                     }
//                     else{
//                         if(dp[i-1][j-coins[i]] != -1) // IMPORTANT
//                             dp[i][j] = min(dp[i][j], dp[i][j-coins[i]] + 1); // 不是从dp[i-1][j-coins[i]]转移了, 同一个硬币可以重复选
//                     }
//                 }
//             }
//         }

//         // print(dp);
//         return dp[(int)coins.size() - 1][amount];
//     }
// };





// 总体思路没变, 但是借助INT_MAX, 实现起来清晰多了

// 执行用时：
// 192 ms
// , 在所有 C++ 提交中击败了
// 13.40%
// 的用户
// 内存消耗：
// 42.2 MB
// , 在所有 C++ 提交中击败了
// 8.33%
// 的用户


class Solution {
public:
    void print(vector<vector<int>> dp, int amount){
        cout<<"    ";
        for(int j = 0;j <= amount;j++){
            cout<<setw(2)<<j<<" ";
        }
        cout<<endl;
        
        for(int i = 0;i< dp.size();i++){
            // cout<<"consider to te index : "<<i<<endl;
            cout<<setw(2)<<i<<" |";
            for(int j = 0;j<dp[i].size();j++){
                cout<<setw(2)<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0) return -1;

        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, INT_MAX - 1));
        for(int i = 0;i<coins.size();i++){
            dp[i][0] = 0;
        }
        for(int j = 1;j <= amount;j++){
            if(j % coins[0] == 0){
                dp[0][j] = j / coins[0];
            }
        }


        // 注意, 这道题是无穷背包, 完全可以压缩成一维dp, 且更新方向是正向的, j从1更新到amount
        for(int i = 1;i<coins.size();i++){
            for(int j = 1;j<= amount;j++){
                dp[i][j] = dp[i-1][j]; // 最坏的情况
                if(j - coins[i] >= 0){
                    dp[i][j] = min(dp[i][j], dp[i][j-coins[i]] + 1); // 不是从dp[i-1][j-coins[i]]转移了（而且dp[i][j-coins[i]]已经考虑过了dp[i-1][j-coins[i]]）, 同一个硬币可以重复选
                }
            }
        }

        // print(dp, amount);
        if(dp[(int)coins.size() - 1][amount] == INT_MAX - 1){
            return -1;
        }
        return dp[(int)coins.size() - 1][amount];
    }
};


// https://leetcode-cn.com/problems/coin-change/solution/dfsjian-zhi-2ms-ji-bai-100bi-dphuan-kuai-by-iejepw/278165
// 比dp还快?

