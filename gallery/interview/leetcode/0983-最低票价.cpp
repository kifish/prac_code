// https://leetcode-cn.com/problems/minimum-cost-for-tickets/comments/67361
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if(days.size() == 0) return 0;
        int n = days[days.size() - 1];
        vector<int> dp(n+1,0);
        for(auto day : days){
            dp[day] = -1; //-1��ʾ������Ҫ�����ˡ���Ҫ�������ǰ���7��Ʊ���൱����7���е����һ�츶��
        }
        for(int i = 1;i<=n;++i){
            if(dp[i] == -1){    // ��Ҫ����
                int a = dp[i-1] + costs[0];
                int b,c;
                if(i-7 >= 0){
                    b = dp[i-7] + costs[1];
                }
                else{
                    b = costs[1];
                }
                if(i - 30>=0){
                    c = dp[i-30] + costs[2];
                }
                else{
                    c = costs[2];
                }
                dp[i] = min(min(a,b),c);
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[n];
    }
};