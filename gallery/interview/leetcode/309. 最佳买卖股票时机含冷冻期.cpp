
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-lab/

// https://www.geeksforgeeks.org/int_max-int_min-cc-applications/

// c++ int 最小值

// 不含有冷冻期
// 0:不持有
// 1:持有
// dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k-1][1] + prices[i])
// dp[i][k][1] = max(dp[i-1][k-1][0]-prices[i],dp[i-1][k][1])


// 含有冷冻期
// 0:不持有
// 1:持有
// dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k-1][1] + prices[i]) // 冷冻期不会影响这种情况
// dp[i][k][1] = max(dp[i-2][k-1][0]-prices[i],dp[i-1][k][1])
// 这种情况里为什么如果打算买入一定是从dp[i-2][k-1][0]转移过来的,而不可能是dp[i-1][k-1][0]?
// 因为dp[i-1][k-1][0]的值应该是和dp[i-2][k-1][0]一样的,因此只需考虑dp[i-2][k-1][0]

// 执行用时 :
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗 :
// 11.3 MB
// , 在所有 C++ 提交中击败了
// 14.29%
// 的用户


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 算利润可以按冷冻期算
        // 或者在最后一天就不用算冷冻期
        // 为了简单起见可以再prices后面补个0

        // 但是可以用dp的思路来解决

        int min_val = 1<<31;
        // cout<<min_val<<endl;
        int dp_i_0 = 0;
        int dp_i_1 = min_val; // 用负无穷表示状态不合法
        int pre_dp_i_0 = 0; // 相当于dp[i-2][k-1][0]
        for(int i = 0;i< prices.size();i++){
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0,dp_i_1 + prices[i]);
            dp_i_1 = max(pre_dp_i_0-prices[i], dp_i_1);
            pre_dp_i_0 = tmp;
        }

        return dp_i_0;
    }
};