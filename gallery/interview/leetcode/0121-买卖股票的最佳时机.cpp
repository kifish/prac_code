
/*

https://leetcode-cn.com/explore/interview/card/bytedance/246/dynamic-programming-or-greedy/1042/

https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/


*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int lowest_price_before[prices.size()];
        int cur_min = prices[0];
        for(int i =1;i<prices.size();i++){
            lowest_price_before[i] = cur_min;
            if(prices[i] < cur_min) cur_min = prices[i];
        }
        int max_profit = 0;
        for(int i = 1;i<prices.size();i++){
            max_profit = max(max_profit,prices[i] - lowest_price_before[i]);
        }
        return max_profit;
    }
};