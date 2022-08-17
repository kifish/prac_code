/*
https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
执行结果：
通过

执行用时：
132 ms, 在所有 C++ 提交中击败了91.13%的用户
内存消耗：
15.6 MB, 在所有 C++ 提交中击败了77.84%的用户
通过测试用例：
56 / 56

class Solution {
public:
    int dp[1005][1005] = {0}; // dp[i][j]: 以nums1的第i个数结尾且以nums2的第j个数结尾的最长公共子数组的长度, 如果nums1的第i个数和nums2的第j个数不相同, 则dp[i][j]为0
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m * n == 0) return 0;

        int max_len = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if(dp[i][j] > max_len){
                        max_len = dp[i][j];
                    }
                }
            }
        }
        return max_len;
    }
};


*/



/*
https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/comments/1064203

执行结果：
通过

执行用时：132 ms, 在所有 C++ 提交中击败了91.13%的用户
内存消耗：11.3 MB, 在所有 C++ 提交中击败了95.51%的用户
通过测试用例：
56 / 56

class Solution {
public:
    int dp[1005];
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m * n == 0) return 0;

        int max_len = 0;
        for(int i = 1; i <= m; i++){
            for(int j = n; j >= 1; j--){ // 反向更新, 防止第i轮循环中更新的结果用于第i轮循环中接下来的更新
                if(nums1[i-1] == nums2[j-1]){
                    dp[j] = dp[j-1] + 1;
                    if(dp[j] > max_len){
                        max_len = dp[j];
                    }
                }
                else{
                    dp[j] = 0;
                }
            }
        }
        return max_len;
    }
};


*/

/*
滑动窗口
https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/solution/javadong-tai-gui-hua-jie-jue-qi-shi-jiu-shi-zui-ch/

*/