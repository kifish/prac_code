
// 执行用时 :
// 100 ms
// , 在所有 C++ 提交中击败了
// 22.36%
// 的用户
// 内存消耗 :
// 7.6 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }

        vector<int> dp(nums.size(), 1);
        for(int i = 1;i<nums.size();i++){
            for(int j = 0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ret = 0;
        for(auto r : dp){
            ret = max(ret, r);
        }
        return ret;
    }
};