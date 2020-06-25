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