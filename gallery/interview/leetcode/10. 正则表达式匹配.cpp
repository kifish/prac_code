
/*
https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/





C里面是不能嵌套定义函数的,
但是c++ 可以在函数里写函数: https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/
这个url里写的很漂亮。

// https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/452866






https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/












字母 + 星号的组合在匹配的过程中，本质上只会有两种情况：

匹配 s 末尾的一个字符，将该字符扔掉，而该组合还可以继续进行匹配；

不匹配字符，将该组合扔掉，不再进行匹配。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。







*/




// 输入:
// "aab"
// "c*a*b"
// 输出
// false
// 预期结果
// true


// class Solution {
// public:
//     bool matches(const string & s, int i_th, const string & p, int j_th){ // 数学意义上的第i个第j个
//         // i_th >= 1 ; j_th>=1
//         if(p[j_th-1] == '.' || s[i_th - 1] == p[j_th - 1]){
//             return true;
//         }
//         else return false;
//     }

//     char get_k_th_char(const string & str, int k_th){
//         // k_th >= 1; str.size() >= 1
//         return str[k_th-1];
//     }


//     bool isMatch(string s, string p) {
//         int m = s.size();
//         int n = p.size();
//         vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
//         dp[0][0] = true;

//         for(int i = 1;i<=m;i++){
//             for(int j = 1;j<=n;j++){
//                 if(get_k_th_char(p,j) != '*'){
//                     if(matches(s,i,p,j)){
//                         dp[i][j] = dp[i-1][j-1];
//                     }
//                     else{
//                         dp[i][j] = false;
//                     }
//                 }
//                 else{
//                     // p[j-1] 是通配符 '*'
//                     // 那么要考虑 p[j-2] 和s[i-1] 是否匹配
//                     if(j >= 2){
//                         if(matches(s,i,p,j-1)){
//                             dp[i][j] = dp[i-1][j-1] || dp[i-1][j]; // *的生效次数为1次 或> 1次
//                         }
//                         else{
//                             dp[i][j] = dp[i][j-2]; // "x*" 这2个字符直接消失
//                         }
//                     }
//                     else{ // 说明j==1
//                         // 只需要考虑p的第一个字符
//                         // p 的第一个字符是* 
//                         // 那么直接判不匹配即可
//                         dp[i][j] = false;
//                     }
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };



// 也可以把这题理解为搜索 + memo

// 输入:
// "aab"
// "c*a*b"
// 输出
// false
// 预期结果
// true



// class Solution {
// public:
//     bool matches(const string & s, int i_th, const string & p, int j_th){ // 数学意义上的第i个第j个
//         // i_th >= 1 ; j_th>=1
//         if(p[j_th-1] == '.' || s[i_th - 1] == p[j_th - 1]){
//             return true;
//         }
//         else return false;
//     }

//     char get_k_th_char(const string & str, int k_th){
//         // k_th >= 1; str.size() >= 1
//         return str[k_th-1];
//     }


//     bool isMatch(string s, string p) {
//         int m = s.size();
//         int n = p.size();
//         vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
//         dp[0][0] = true;

//         for(int i = 1;i<=m;i++){
//             for(int j = 1;j<=n;j++){
//                 if(get_k_th_char(p,j) != '*'){
//                     if(matches(s,i,p,j)){
//                         dp[i][j] = dp[i-1][j-1];
//                     }
//                     else{
//                         dp[i][j] = false;
//                     }
//                 }
//                 else{
//                     // p[j-1] 是通配符 '*'
//                     // 那么要考虑 p[j-2] 和s[i-1] 是否匹配
//                     if(j >= 2){
//                         dp[i][j] = dp[i][j-2]; // "x*" 这2个字符直接消失
//                         if(matches(s,i,p,j-1)){
//                             // 由于dp的类型为bool, 因此无法使用 |=
//                             // 如果类型为int, 可以使用 |=
//                             dp[i][j] = dp[i][j] || dp[i-1][j-1]; //*的生效次数为1次
//                             dp[i][j] = dp[i][j] || dp[i-1][j]; // 或> 1次
//                         }
//                     }
//                     else{ // 说明j==1
//                         // 只需要考虑p的第一个字符
//                         // p 的第一个字符是* 
//                         // 那么直接判不匹配即可
//                         dp[i][j] = false;
//                     }
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };



// https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/452279




// "aa"
// "a*"




// 执行用时：
// 12 ms
// , 在所有 C++ 提交中击败了
// 66.02%
// 的用户
// 内存消耗：
// 6.7 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


// class Solution {
// public:


//     void pretty_print(vector<vector<bool>> & dp){
//         if(dp.size() == 0) return;

//         int col = dp[0].size();
//         int row = dp.size();
//         cout<<"    ";
//         for(int i = 0;i< col;i++){
//             cout<<setw(3)<<i;
//         }
//         cout<<endl;

//         for(int i = 0;i<row;i++){
//             cout<<i<<" | ";
//             for(int j = 0; j<col;j++){
//                 cout<<setw(3)<<(int)dp[i][j];
//             }
//             cout<<endl;
//         }
//     }

//     void pretty_print(vector<vector<bool>> & dp, const string & s, const string & p){
//         if(dp.size() == 0) return;
//         int col = dp[0].size(); // n+1;p
//         int row = dp.size(); // m+1;s
//         // 貌似在playground里面调试有点问题
//         // s会多一个无用的字符
//         // 需要row-1
//         // row -= 1;
//         // 提交的时候不需要减-

//         cout<<"row : "<<row<<endl;
//         cout<<"col : "<<col<<endl;

//         cout<<"row : "<<p<<endl;
//         cout<<"col : "<<s<<endl;

//         cout<<"      ";
//         for(int i = 0;i<col;i++){
//             if(i == 0)
//                 cout<<"  "<<"#";
//             else
//                 cout<<"  "<<p[i-1];
//         }

//         cout<<endl;

//         for(int i = 0;i<row;i++){
//             if(i == 0)
//                 cout<<"  "<<"#";
//             else
//                 cout<<"  "<<s[i-1];
//             cout<<" | ";

//             for(int j = 0; j<col;j++){
//                 // cout<<setw(2)<<(int)dp[i][j];
//                 cout<<"  "<<(int)dp[i][j];
//             }
//             cout<<endl;
//         }
//     }



//     bool matches(const string & s, int i_th, const string & p, int j_th){ // 数学意义上的第i个第j个
//         // i_th >= 1 ; j_th>=1
//         if(p[j_th-1] == '.' || s[i_th - 1] == p[j_th - 1]){
//             return true;
//         }
//         else return false;
//     }

//     char get_k_th_char(const string & str, int k_th){
//         // k_th >= 1; str.size() >= 1
//         return str[k_th-1];
//     }


//     bool isMatch(string s, string p) {
//         int m = s.size();
//         int n = p.size();
//         vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
//         dp[0][0] = true;

//         // 举例:
//         // aab
//         // c*a*b
//         // dp[0][0-2] 都应该是true
//         for(int i = 0;i<=m;i++){ // 需要从i=0开始更新, 而不是i=1
//             for(int j = 1;j<=n;j++){
//                 if(get_k_th_char(p,j) != '*'){
//                     if(i > 0 && matches(s,i,p,j)){
//                         dp[i][j] = dp[i-1][j-1];
//                     }
//                     else{
//                         dp[i][j] = false;
//                     }
//                 }
//                 else{
//                     // p[j-1] 是通配符 '*'
//                     // 那么要考虑 p[j-2] 和s[i-1] 是否匹配
//                     if(j >= 2){
//                         dp[i][j] = dp[i][j-2]; // "x*" 这2个字符直接消失
//                         if(i > 0 && matches(s,i,p,j-1)){
//                             dp[i][j] = dp[i][j] || (i>=1 && dp[i-1][j]); //  > 1次
//                             dp[i][j] = dp[i][j] || dp[i][j-1]; // 匹配一次
//                         }
//                     }
//                     else{ // 说明j==1
//                         // 只需要考虑p的第一个字符
//                         // p 的第一个字符是* 
//                         // 那么直接判不匹配即可
//                         dp[i][j] = false;
//                     }
//                 }
//             }
//         }
//         // pretty_print(dp);
//         // pretty_print(dp,s,p);
//         return dp[m][n];
//     }
// };






// 执行用时：
// 12 ms
// , 在所有 C++ 提交中击败了
// 66.02%
// 的用户
// 内存消耗：
// 6.8 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:


    void pretty_print(vector<vector<bool>> & dp){
        if(dp.size() == 0) return;

        int col = dp[0].size();
        int row = dp.size();
        cout<<"    ";
        for(int i = 0;i< col;i++){
            cout<<setw(3)<<i;
        }
        cout<<endl;

        for(int i = 0;i<row;i++){
            cout<<i<<" | ";
            for(int j = 0; j<col;j++){
                cout<<setw(3)<<(int)dp[i][j];
            }
            cout<<endl;
        }
    }

    void pretty_print(vector<vector<bool>> & dp, const string & s, const string & p){
        if(dp.size() == 0) return;
        int col = dp[0].size(); // n+1;p
        int row = dp.size(); // m+1;s
        // 貌似在playground里面调试有点问题
        // s会多一个无用的字符
        // 需要row-1
        // row -= 1;
        // 提交的时候不需要减-

        cout<<"row : "<<row<<endl;
        cout<<"col : "<<col<<endl;

        cout<<"row : "<<p<<endl;
        cout<<"col : "<<s<<endl;

        cout<<"      ";
        for(int i = 0;i<col;i++){
            if(i == 0)
                cout<<"  "<<"#";
            else
                cout<<"  "<<p[i-1];
        }

        cout<<endl;

        for(int i = 0;i<row;i++){
            if(i == 0)
                cout<<"  "<<"#";
            else
                cout<<"  "<<s[i-1];
            cout<<" | ";

            for(int j = 0; j<col;j++){
                // cout<<setw(2)<<(int)dp[i][j];
                cout<<"  "<<(int)dp[i][j];
            }
            cout<<endl;
        }
    }



    bool matches(const string & s, int i_th, const string & p, int j_th){ // 数学意义上的第i个第j个
        // i_th >= 1 ; j_th >= 1
        if(p[j_th-1] == '.' || s[i_th - 1] == p[j_th - 1]){
            return true;
        }
        else return false;
    }

    char get_k_th_char(const string & str, int k_th){
        // k_th >= 1; str.size() >= 1
        return str[k_th-1];
    }


    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        dp[0][0] = true;

        // 举例:
        // aab
        // c*a*b
        // dp[0][0-2] 都应该是true
        for(int i = 0; i<=m; i++){ // 需要从i=0开始更新, 而不是i=1
            for(int j = 1; j<=n; j++){
                if(get_k_th_char(p,j) != '*'){
                    if(i > 0 && matches(s,i,p,j)){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                else{
                    // p[j-1] 是通配符 '*'
                    // 那么要考虑 p[j-2] 和s[i-1] 是否匹配
                    if(j >= 2){
                        dp[i][j] = dp[i][j-2]; // "x*" 这2个字符直接消失
                        if(i > 0 && matches(s,i,p,j-1)){
                            dp[i][j] = dp[i][j] || (i > 0 && dp[i-1][j]); //  > 1次
                            // dp[i][j] = dp[i][j] || dp[i][j-1]; // 匹配一次; 这个情况其实已经被dp[i-1][j] 覆盖了; 或者说选择了dp[i][j-1]这个分支最后还是会走到dp[i-1][j]这个分支上 (实际更新的时候是正向更新, 不会回退到dp[i-1][j]这个分支, 但从正确性来说dp[i][j-1]的值其实取决于dp[i-1][j], 原因是'*'的特殊性)
                            // https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/452856

                            // 仔细理解下面这段话: 
                            // 字母 + 星号的组合在匹配的过程中，本质上只会有两种情况:
                            // 匹配 s 末尾的一个字符，将该字符扔掉，而该组合还可以继续进行匹配;
                            // 不匹配字符，将该组合扔掉，不再进行匹配。

                        }
                    }
                    else{ // 说明j==1
                        // 只需要考虑p的第一个字符
                        // p 的第一个字符是* 
                        // 那么直接判不匹配即可
                        dp[i][j] = false;
                    }
                }
            }
        }
        // pretty_print(dp);
        // pretty_print(dp,s,p);
        return dp[m][n];
    }
};