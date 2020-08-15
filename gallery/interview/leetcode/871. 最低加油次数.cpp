
/*
pat 也有这题目
https://leetcode-cn.com/problems/minimum-number-of-refueling-stops/solution/zui-di-jia-you-ci-shu-by-leetcode/



贪心可解

*/

// dp
// https://leetcode-cn.com/problems/minimum-number-of-refueling-stops/solution/fang-yi-ge-wei-jiang-wei-de-dpjie-fa-by-pwrliang/



// 执行用时：
// 212 ms
// , 在所有 C++ 提交中击败了
// 7.37%
// 的用户
// 内存消耗：
// 107.2 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    #define LL long long
    int minRefuelStops(int target, int startFuel, vector<vector<int>> & stations) {
        int n = stations.size();
        if(startFuel >= target) return 0;

        vector<vector<LL>> dp(n+1,vector<LL> (n+1,0)); //dp[i][j] 考虑到车站i 且总共加j次油所能到达的最远距离
        dp[0][0] = startFuel;
        for(int i = 1;i<=n;i++){
            dp[i][0] = startFuel;
        }

        for(int i = 1;i<=n;i++){ // 遍历车站
            int cur_station_pos = stations[i-1][0];
            int cur_station_gas = stations[i-1][1];
            for(int j = 1;j<=i;j++){ // 遍历加油次数 // 最多可以加油i次

                // 情况1 在车站i未加油
                // 车站1-i-1 加了j次油
                dp[i][j] = max(dp[i][j], dp[i-1][j]);

                // 情况2 在车站i加油了一次
                // 条件就是首先得到达车站i
                if(dp[i-1][j-1] >= cur_station_pos){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + cur_station_gas);
                }
            }
        }

        for(int j = 1;j<=n;j++){
            if(dp[n][j] >= target){ // 要加=号
                return j;
            }
        }
        return -1;
    }
};

// 该dp可以状态压缩到一维

// 贪心怎么想呢?

// 例如经过第i个车站不一定立即加油, 继续行驶, 发现行驶不到当前的下一个车站则在前面的车站里选一个油量最大的加油

// 可以认为加油距离是无限的, 只要行驶过第i个车站, 则在之后是一直可以从该车站加油的

// 先不加油, 等油不够的时候, 优先选择油量最大的车站即可

// https://leetcode-cn.com/problems/minimum-number-of-refueling-stops/solution/zui-di-jia-you-ci-shu-by-leetcode/


