
// 感觉做搜索框的时候 可能会用到这个算法


// https://leetcode-cn.com/problems/word-break/solution/dan-ci-chai-fen-by-leetcode/


// dfs
// bug的原因是:
// "aaaaaaa"
// ["aaaa","aaa"]
// 由于aaa比aaaa短，因此每次会按aaa去切
// cur_state:
// can_be_locally_breaked :0
// can_be_breaked :0
// cur_start_idx : 0
// cur_idx : 0
// cur_state:
// can_be_locally_breaked :0
// can_be_breaked :0
// cur_start_idx : 0
// cur_idx : 1
// cur_state:
// can_be_locally_breaked :1
// can_be_breaked :0
// cur_start_idx : 0
// cur_idx : 2
// cur_state:
// can_be_locally_breaked :0
// can_be_breaked :0
// cur_start_idx : 3
// cur_idx : 3
// cur_state:
// can_be_locally_breaked :0
// can_be_breaked :0
// cur_start_idx : 3
// cur_idx : 4
// cur_state:
// can_be_locally_breaked :1
// can_be_breaked :0
// cur_start_idx : 3
// cur_idx : 5
// cur_state:
// can_be_locally_breaked :0
// can_be_breaked :0
// cur_start_idx : 6
// cur_idx : 6



// 感觉做搜索框的时候 可能会用到这个算法


// https://leetcode-cn.com/problems/word-break/solution/dan-ci-chai-fen-by-leetcode/


// dfs
// WA
// class Solution {
// public:
//     bool can_be_breaked = false;
//     bool can_be_locally_breaked = false;
//     void dfs(int cur_start_idx, int cur_idx, string &s, set<string>& wordDict){
//         if(cur_idx == s.size()){
//             return;
//         }

//         if(wordDict.count(s.substr(cur_start_idx, cur_idx-cur_start_idx + 1))){
//             can_be_locally_breaked = true;
//         }

//         cout<<"cur_state:\n";
//         cout<<"can_be_locally_breaked :"<<can_be_locally_breaked<<endl;
//         cout<<"can_be_breaked :"<<can_be_breaked<<endl;
//         cout<<"cur_start_idx : "<<cur_start_idx<<endl;
//         cout<<"cur_idx : "<<cur_idx<<endl;



//         if(cur_idx == (int) s.size() -1){ // s是字符串
//             if(can_be_locally_breaked){
//                 can_be_breaked = true;
//             }
//             return;
//         }


//         if(can_be_breaked) return; // 是否多余？感觉是多余的

//         if(can_be_locally_breaked){
//             can_be_locally_breaked = false;
//             dfs(cur_idx+1,cur_idx+1,s,wordDict);
//         }
//         else{
//             dfs(cur_start_idx, cur_idx+1, s, wordDict);
//         }        
//     }


//     bool wordBreak(string s, vector<string>& wordDict) {
//         set<string> d;
//         for(auto s: wordDict){
//             d.insert(s);
//         }
//         dfs(0,0,s,d);
//         return can_be_breaked;
//     }
// };


// TLE
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
// ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

// 时间复杂度：O(n^n)O(n 
// n
//  ) 。考虑最坏情况 ss = \text{aaaaaaa}aaaaaaa 。每一个前缀都在字典中，此时回溯树的复杂度会达到 n^nn 
// n
//   。
// 空间复杂度：O(n)O(n) 。回溯树的深度最深达到 nn 。

// 作者：LeetCode
// 链接：https://leetcode-cn.com/problems/word-break/solution/dan-ci-chai-fen-by-leetcode/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// class Solution {
// public:
//     bool can_be_breaked = false;
//     bool can_be_locally_breaked = false;
//     void dfs(int cur_start_idx, int cur_idx, string &s, set<string>& wordDict){
//         if(cur_idx == s.size()){
//             return;
//         }

//         if(wordDict.count(s.substr(cur_start_idx, cur_idx-cur_start_idx + 1))){
//             can_be_locally_breaked = true;
//         }

//         // cout<<"cur_state:\n";
//         // cout<<"can_be_locally_breaked :"<<can_be_locally_breaked<<endl;
//         // cout<<"can_be_breaked :"<<can_be_breaked<<endl;
//         // cout<<"cur_start_idx : "<<cur_start_idx<<endl;
//         // cout<<"cur_idx : "<<cur_idx<<endl;



//         if(cur_idx == (int) s.size() -1){ // s是字符串
//             if(can_be_locally_breaked){
//                 can_be_breaked = true;
//             }
//             return;
//         }


//         if(can_be_breaked) return; // 是否多余？感觉是多余的

//         if(can_be_locally_breaked){
//             can_be_locally_breaked = false;
//             dfs(cur_idx+1,cur_idx+1,s,wordDict);
//             // 注意即使能切也可以选择不切
//             can_be_locally_breaked = false;
//             dfs(cur_start_idx, cur_idx+1, s, wordDict);
//         }
//         else{
//             dfs(cur_start_idx, cur_idx+1, s, wordDict);
//         }        
//     }


//     bool wordBreak(string s, vector<string>& wordDict) {
//         set<string> d;
//         for(auto s: wordDict){
//             d.insert(s);
//         }
//         dfs(0,0,s,d);
//         return can_be_breaked;
//     }
// };


// 这个方法加memo有点复杂
// class Solution {
// public:
//     bool can_be_breaked = false;
//     bool can_be_locally_breaked = false;
//     void dfs(int cur_start_idx, int cur_idx, string &s, set<string>& wordDict){
//         if(cur_idx == s.size()){
//             return;
//         }

//         if(wordDict.count(s.substr(cur_start_idx, cur_idx-cur_start_idx + 1))){
//             can_be_locally_breaked = true;
//         }

//         // cout<<"cur_state:\n";
//         // cout<<"can_be_locally_breaked :"<<can_be_locally_breaked<<endl;
//         // cout<<"can_be_breaked :"<<can_be_breaked<<endl;
//         // cout<<"cur_start_idx : "<<cur_start_idx<<endl;
//         // cout<<"cur_idx : "<<cur_idx<<endl;



//         if(cur_idx == (int) s.size() -1){ // s是字符串
//             if(can_be_locally_breaked){
//                 can_be_breaked = true;
//             }
//             return;
//         }


//         if(can_be_breaked) return; // 是否多余？感觉是多余的

//         if(can_be_locally_breaked){
//             can_be_locally_breaked = false;
//             dfs(cur_idx+1,cur_idx+1,s,wordDict);
//             // 注意即使能切也可以选择不切
//             can_be_locally_breaked = false;
//             dfs(cur_start_idx, cur_idx+1, s, wordDict);
//         }
//         else{
//             dfs(cur_start_idx, cur_idx+1, s, wordDict);
//         }        
//     }


//     bool wordBreak(string s, vector<string>& wordDict) {
//         set<string> d;
//         for(auto s: wordDict){
//             d.insert(s);
//         }
//         dfs(0,0,s,d);
//         return can_be_breaked;
//     }
// };


//  https://leetcode-cn.com/problems/word-break/solution/dan-ci-chai-fen-by-leetcode/

// bfs 加memo就清晰多了

// 执行用时 :
// 36 ms
// , 在所有 C++ 提交中击败了
// 37.87%
// 的用户
// 内存消耗 :
// 14.1 MB
// , 在所有 C++ 提交中击败了
// 42.42%
// 的用户

// bfs求的是能与不能

// class Solution {
// public:
//     bool can_be_breaked = false;
//     vector<bool> was_in_q;
//     void bfs(string &s, set<string> d){
//         queue<int> q;
//         q.push(0);
//         was_in_q[0] = true;
//         while(!q.empty()){
//             int cur_idx = q.front();
//             q.pop();
//             for(int candidate_idx = cur_idx+1; candidate_idx <= s.size();candidate_idx++){
//                 string sub_str = s.substr(cur_idx,candidate_idx-cur_idx);//闭开区间
//                 if(d.count(sub_str)){
//                     // 可以扩展状态
//                     if(candidate_idx == s.size()){
//                         can_be_breaked = true;
//                         return;
//                     }
//                     if(was_in_q[candidate_idx] == false){
//                         q.push(candidate_idx);
//                         was_in_q[candidate_idx] = true;
//                     }
//                 }
//             }
//         }
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         set<string> d;
//         for(auto str : wordDict){
//             d.insert(str);
//         }
//         was_in_q = vector<bool> (s.size(),false);
//         bfs(s,d);
//         return can_be_breaked;
//     }
// };


// https://leetcode-cn.com/problems/word-break/solution/dan-ci-chai-fen-by-leetcode/
// dp思路也和bfs的思路很接近
// 还没bfs快
// 执行用时 :
// 52 ms
// , 在所有 C++ 提交中击败了
// 15.35%
// 的用户
// 内存消耗 :
// 13.1 MB
// , 在所有 C++ 提交中击败了
// 48.48%
// 的用户

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> d;
        for(auto str : wordDict){
            d.insert(str);
        }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        // dp[i] 表示考虑到s[0]-s[i-1]结束(包括s[i-1])
        for(int i = 1;i<=s.size();i++){
            for(int j = 0;j<i;j++){ // 开闭区间;i代表区间最右边
                dp[i] = dp[j] && (bool) d.count(s.substr(j,i-j));
                if(dp[i]) break;
            }
        }
        return dp[s.size()]; // s非空
    }    
};

