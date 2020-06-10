// https://leetcode-cn.com/problems/palindromic-substrings/solution/647-hui-wen-zi-chuan-dong-tai-gui-hua-fang-shi-qiu/


// 执行用时 :
// 96 ms
// , 在所有 C++ 提交中击败了
// 18.35%
// 的用户
// 内存消耗 :
// 7.7 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool> (s.size(), false));
        // 初始化
        int cnt = 0;
        for(int i = 0;i < s.size();i++){
            dp[i][i] = true;
            cnt++;
        }
        for(int i = (int) s.size() - 1; i >= 0; i--){
            for(int j = i + 1;j < s.size(); j++){
                if(j == i + 1){ // 这种情况下是特例需要特殊处理
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }
                    // else 可省略
                }
                else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }
                    else{
                        dp[i][j] = false;
                    }
                }

                if(dp[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};