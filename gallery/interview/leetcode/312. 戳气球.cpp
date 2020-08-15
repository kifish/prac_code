/*
这道题是poj上的一道改编的题目

感觉局部最优不一定能保证全局最优, 如果暴力模拟, 感觉也是求不出最优值的。

如果更暴力一点, 把所有扎气球的顺序都遍历, 那肯定能求出最优值。
复杂度: O(N!)

比如有四个气球，你先扎破第一个再扎破第二个，跟你先扎破第二个在扎破第一个，最后都是剩下第三个和第四个气球，因此对于剩余第三个和第四个气球这种情况只需要计算一次就可以了。

作者：LeetCode
链接：https://leetcode-cn.com/problems/burst-balloons/solution/chuo-qi-qiu-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

分治 把扎气球变成加气球 dp

https://leetcode-cn.com/problems/burst-balloons/solution/dong-tai-gui-hua-tao-lu-jie-jue-chuo-qi-qiu-wen-ti/

这题难度和扔鸡蛋差不多, 难就难在设计状态

注意这道题和 gallery\百炼oj\2018算法分析期末考试.md 中的E有点类似

执行用时：
36 ms
, 在所有 C++ 提交中击败了
71.46%
的用户
内存消耗：
8.9 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        // padding
        nums.insert(nums.begin() + 0,1);
        nums.push_back(1);

        // dp[i][j] 开区间, index从0开始
        // dp[i][j] 表示戳爆i+1 到j-1的气球得到的最高分
        // 不包括戳爆第i个气球 和第j个气球带来的分数
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), 0));
        int n = nums.size() - 2;
        for(int i = n-1;i >= 0;i--){
            for(int j = i + 2; j <= n+1; j++){ // j <= n+1
                for(int k = i + 1; k < j; k++){
                    // IMPORTANT: not nums[k] * nums[k-1] * nums[k+1]
                    // dp[i][j] = max(dp[i][j], dp[i][k] + nums[k] * nums[k-1] * nums[k+1] + dp[k][j]); // 开区间
                    // 这样转移是不对的

                    // 下面这种转移的方式, 表示i-k和k-j之间的气球已经爆了, 第i个气球, 第k个气球, 第j个气球依次顺序相邻
                    dp[i][j] = max(dp[i][j], dp[i][k] + nums[k] * nums[i] * nums[j] + dp[k][j]); // 开区间
                }
            }
        }

        return dp[0][n+1];
    }
};



