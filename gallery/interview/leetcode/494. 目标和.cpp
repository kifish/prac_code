
// 执行用时 :
// 1764 ms
// , 在所有 C++ 提交中击败了
// 23.14%
// 的用户
// 内存消耗 :
// 9.1 MB
// , 在所有 C++ 提交中击败了
// 35.29%
// 的用户

// class Solution {
// public:
//     int cnt = 0;
//     void dfs(int idx, vector<int>& nums, int cur_sum, int target){
//         if(idx == nums.size()){
//             if(target == cur_sum){
//                 cnt++;
//             }
//             return;
//         }

//         dfs(idx+1,nums, cur_sum-nums[idx],target);
//         dfs(idx+1,nums, cur_sum+nums[idx],target);
//     }

//     int findTargetSumWays(vector<int>& nums, int S) {
//         dfs(0,nums,0,S);
//         return cnt;
//     }
// };

// dp 转化为背包问题

// 执行用时 :
// 92 ms
// , 在所有 C++ 提交中击败了
// 52.80%
// 的用户
// 内存消耗 :
// 22.6 MB
// , 在所有 C++ 提交中击败了
// 11.76%
// 的用户

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0) return 0;
        int positive_sum = 0;
        for(auto num : nums){
            positive_sum += num;
        }
        // positive_sum = 1000;
        const int possible_sum_cnt = positive_sum * 2 + 1;// 最多这么多种可能的和
        vector<vector<int>> dp(nums.size(), vector<int> (possible_sum_cnt,0));
        int down_limit = -1*positive_sum;
        int up_limit = positive_sum;
        int offset = positive_sum;
        dp[0][nums[0] + offset] = 1;
        dp[0][-1*nums[0] + offset] = 1;
        if(nums[0] == 0){ // 0的情况要特殊处理
            dp[0][0 + offset] = 2;
        }
        for(int i = 1;i<nums.size();i++){
            for(int j = down_limit;j<=up_limit;j++){ // 记住所有dp[][j] 第二维都要加offset
                if(j - nums[i] >= down_limit){
                    dp[i][j+ offset] += dp[i-1][j-nums[i] + offset];
                }

                if(j + nums[i] <= up_limit){
                    dp[i][j+ offset] += dp[i-1][j+nums[i] + offset];
                }
            }
        }
        if(S > up_limit){
            return 0;
        }
        else{
            return dp[nums.size() - 1][S + offset];
        }
    }
};
