# https://leetcode-cn.com/problems/longest-common-subsequence/

# https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/




# 执行结果：
# 通过
# 显示详情
# 执行用时：
# 3996 ms
# , 在所有 Python3 提交中击败了
# 76.51%
# 的用户
# 内存消耗：
# 38.1 MB
# , 在所有 Python3 提交中击败了
# 52.90%
# 的用户


class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        s1 = A 
        s2 = B
        m = len(s1) 
        n = len(s2) 

        dp = [ [0] * (n + 1) for _ in range(m + 1) ] # m+1;n+1
        
        lcspan_len = 0
        for i in range(m + 1): # i [0,m] dp[0][0] 表示不考虑s1和s2任何字符; dp[2][2]表示考虑数学意义上的s1前2个字符和s2前2个字符
            for j in range(n + 1): 
                if i == 0 or j == 0 : 
                    dp[i][j] = 0       
                elif s1[i-1] == s2[j-1]: 
                    dp[i][j] = dp[i-1][j-1] + 1
                    if dp[i][j] > lcspan_len:
                        lcspan_len = dp[i][j]
                else:
                    pass 

        return lcspan_len