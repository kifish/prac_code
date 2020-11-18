# https://leetcode-cn.com/problems/longest-common-subsequence/

# https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/



# 执行结果：
# 通过
# 显示详情
# 执行用时：
# 440 ms
# , 在所有 Python3 提交中击败了
# 77.17%
# 的用户
# 内存消耗：
# 34.4 MB
# , 在所有 Python3 提交中击败了
# 5.03%
# 的用户

    


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # find the length of the strings 
        s1 = text1
        s2 = text2
        
        m = len(s1) 
        n = len(s2) 

        dp = [ [None] * (n + 1) for _ in range(m + 1) ] # m+1;n+1
        prev =  [ [ (None, None) for __ in range(n + 1)] for _ in range(m + 1) ]
        

        for i in range(m + 1): # i [0,m] dp[0][0] 表示不考虑s1 和s2任何字符; dp[2][2]表示考虑数学意义上的s1前2个字符和s2前2个字符
            for j in range(n + 1): 
                if i == 0 or j == 0 : 
                    dp[i][j] = 0
                                    
                elif s1[i-1] == s2[j-1]: 
                    dp[i][j] = dp[i-1][j-1]+1
                    prev[i][j] = [i-1, j-1]
                else:
                    if dp[i-1][j] > dp[i][j-1]: # 暂时不考虑多解的情况
                        dp[i][j] = dp[i-1][j]
                    else:
                        dp[i][j] = dp[i][j-1]
        
        return dp[m][n]