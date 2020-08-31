


/*

https://leetcode-cn.com/explore/interview/card/bytedance/246/dynamic-programming-or-greedy/1043/

https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

*/


// 差分数列
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode/
class Solution
{
public:
    // 同一天可以多次买入卖出
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        for(int i = 0;i<prices.size();i++){
            if(i != 0){
                res += max(0,prices[i] - prices[i-1]);
            }
        }
        return res;
    }
};