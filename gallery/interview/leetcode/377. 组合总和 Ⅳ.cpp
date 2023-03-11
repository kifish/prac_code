/*

https://leetcode-cn.com/problems/combination-sum-iv/


背包问题

https://leetcode-cn.com/problems/combination-sum-iv/solution/xi-wang-yong-yi-chong-gui-lu-gao-ding-bei-bao-wen-/


https://leetcode-cn.com/problems/combination-sum-iv/solution/dong-tai-gui-hua-python-dai-ma-by-liweiwei1419/




*/

class Solution {
    using ULL = unsigned long long;
    vector<vector<ULL>> dp; // dp[i][j] 选取的数的个数是i且总和是j的方案数
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, vector<ULL>(target + 1, 0));
        dp[0][0] = 1;
        ULL ret = 0;
        for(int i = 1; i <= target; i++){
            for(int j = 1; j <= target; j++){
                for(int num:nums)
                if(j >= num){
                    dp[i][j] += dp[i-1][j-num];
                }
            }
            ret += dp[i][target];
        }
        return ret;
    }
};
