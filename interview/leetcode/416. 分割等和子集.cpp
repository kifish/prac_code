// 首先如果是sum为奇数,那肯定不可能
// 如果sum为偶数则要分情况讨论
// dfs可以解决吗? 可以, dfs然后和为sum的一半

// 注意题目有强烈的暗示: 
// 每个数组中的元素不会超过 100
// 数组的大小不会超过 200

// https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/

// 背包问题

// 执行用时 :
// 564 ms
// , 在所有 C++ 提交中击败了
// 30.43%
// 的用户
// 内存消耗 :
// 11.1 MB
// , 在所有 C++ 提交中击败了
// 26.09%
// 的用户

//优化后: 
// 执行用时 :
// 320 ms
// , 在所有 C++ 提交中击败了
// 50.36%
// 的用户
// 内存消耗 :
// 11.1 MB
// , 在所有 C++ 提交中击败了
// 26.09%
// 的用户


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        if(sum % 2 == 1){
            return false;
        }

        if(nums.size() == 1){
            return false;
        }

        const int half_sum = sum/2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool> (half_sum+1,false));
        dp[0][0] = true; // 数学意义层面不合逻辑; 但是代码实现层面这么写会方便很多
        // 非空数组
        dp[0][nums[0]] = true;
        for(int idx = 1;idx < nums.size();idx++){
            for(int cur_sum = 1;cur_sum <= half_sum;cur_sum++){
                dp[idx][cur_sum] = dp[idx-1][cur_sum] || (cur_sum >= nums[idx] && dp[idx-1][cur_sum - nums[idx]]);
            }
            if(dp[idx][half_sum]){
                return true;
            }
        }


        // 可以优化
        // int half = sum / 2;
        // for(int i = 0;i<nums.size();i++){
        //     if(dp[i][half]){
        //         return true;
        //     }
        // }

        return dp[nums.size() -1][half_sum];
    }
};