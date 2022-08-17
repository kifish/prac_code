/*
https://leetcode-cn.com/problems/longest-common-subsequence/
执行结果：
通过

执行用时：
16 ms, 在所有 C++ 提交中击败了89.72%的用户
内存消耗：
10.5 MB, 在所有 C++ 提交中击败了85.29%的用户
通过测试用例：
44 / 44

class Solution {
public:
    int dp[1005][1005];
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int max_len = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                    max_len = max(max_len, dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return max_len;
    }
};

*/