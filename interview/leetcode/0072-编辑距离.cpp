class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));//dp[m][n]代表word1到第m个字符、word2到第n个字符为止的编辑距离，换言之，这些字符都已经被匹配，无需再考虑
        for(int i = 1;i<=m;i++){
            dp[i][0] = i;
        }
        for(int j = 1;j<=n;j++){
            dp[0][j] = j;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};