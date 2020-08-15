
/*


https://leetcode-cn.com/problems/ones-and-zeroes/

*/


// 执行用时：
// 676 ms
// , 在所有 C++ 提交中击败了
// 13.66%
// 的用户
// 内存消耗：
// 101.8 MB
// , 在所有 C++ 提交中击败了
// 14.00%
// 的用户


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(strs.size() == 0) return 0;

        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>> (m+1, vector<int>(n+1,0)));
        // <=
        // not only == 

        int cur_0_cnt = 0;
        int cur_1_cnt = 0;
        
        for(auto ch : strs[0]){
            if(ch == '0'){
                cur_0_cnt++;
            }
            else cur_1_cnt++;
        }

        for(int i = cur_0_cnt;i<=m;i++){
            for(int j = cur_1_cnt;j<=n;j++){
                dp[0][i][j] = 1;
            }
        }

        for(int k = 1;k<strs.size();k++){
            cur_0_cnt = cur_1_cnt = 0;
            for(auto ch : strs[k]){
                if(ch == '0'){
                    cur_0_cnt++;
                }
                else cur_1_cnt++;
            }
            // cout<<"cur_0_cnt : "<<cur_0_cnt<<endl;
            // cout<<"cur_1_cnt : "<<cur_1_cnt<<endl;
            for(int i = 0;i<=m;i++){
                for(int j = 0;j<=n;j++){
                    dp[k][i][j] = dp[k-1][i][j];

                    if(i-cur_0_cnt>=0 && j-cur_1_cnt>=0){
                        dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-cur_0_cnt][j-cur_1_cnt] + 1);
                    }
                    // cout<<"k " <<k<<"i "<<i<<"j "<<j<<endl;
                    // cout<<dp[k][i][j]<<endl;
                }
            }
        }

        return dp[strs.size() - 1][m][n];
    }
};