

// https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/bfsjian-dan-er-you-xiang-xi-de-pythonjiang-jie-by-/



// 执行用时：
// 1268 ms
// , 在所有 C++ 提交中击败了
// 5.04%
// 的用户
// 内存消耗：
// 30.2 MB
// , 在所有 C++ 提交中击败了
// 8.70%
// 的用户



// class Solution {
// public:
//     bool is_valid(string & s){
//         if(s.size() == 0) return true;

//         int left_cnt = 0;
//         int right_cnt = 0;
//         for(auto & c : s){
//             if(c == '('){
//                 left_cnt++;
//             }
//             else if(c == ')'){
//                 right_cnt++;
//             }

//             if(right_cnt > left_cnt){
//                 return false;
//             }

//         }
//         if(right_cnt == left_cnt){
//             return true;
//         }
//         else return false;
//     }

//     vector<string> ret;

//     vector<string> removeInvalidParentheses(string s) {
//         set<string> cur_level_states;
//         set<string> next_level_states;
//         cur_level_states.insert(s);
//         while(true){
//             while(!cur_level_states.empty()){
//                 for(auto str : cur_level_states){ // 这里不能加&
//                     if(is_valid(str)){
//                         ret.push_back(str);
//                     }
//                 }

//                 if(ret.size()){
//                     return ret;
//                 }

//                 for(auto & str : cur_level_states){
//                     for(int i = 0;i<str.size();i++){
//                         string new_str = "";
//                         for(int j = 0;j<str.size();j++){
//                             if(j != i){
//                                 new_str += str[j]; // 实际上也不需要真的复制, 用一个 标识是否删除的数组即可
//                             }
//                         }
//                         next_level_states.insert(new_str);
//                     }
//                 }

//                 cur_level_states = next_level_states;
//                 next_level_states.clear();
//             }
//         }
//     }
// };



// 执行结果：
// 超出时间限制
// 显示详情
// 最后执行的输入：
// "v)z())((("


// class Solution {
// public:
//     bool is_valid(string & s, vector<bool> & deleted){
//         if(s.size() == 0) return true;

//         int left_cnt = 0;
//         int right_cnt = 0;
//         for(int i = 0;i<deleted.size();i++){
//             char c = s[i];
//             if(deleted[i]) continue;

//             if(c == '('){
//                 left_cnt++;
//             }
//             else if(c == ')'){
//                 right_cnt++;
//             }

//             if(right_cnt > left_cnt){
//                 return false;
//             }

//         }
//         if(right_cnt == left_cnt){
//             return true;
//         }
//         else return false;
//     }


//     // 可能会有重复
//     set<string> ret_s;
//     vector<string> ret;

//     string format_s(string & s, vector<bool> & deleted){
//         string ret = "";
//         for(int i = 0;i<s.size();i++){
//             if(deleted[i]){
//                 continue;
//             }
//             ret += s[i];
//         }
//         return ret;
//     }
//     vector<string> removeInvalidParentheses(string s) {
//         vector<vector<bool>> cur_level_states; // 这种实现里, 这里用set应该无增益
//         vector<vector<bool>> next_level_states;
//         vector<bool> deleted(s.size(), false);
//         cur_level_states.push_back(deleted);

//         while(true){
//             while(!cur_level_states.empty()){
//                 for(auto & state : cur_level_states){ 
//                     if(is_valid(s, state)){
//                         ret_s.insert(format_s(s, state));
//                     }
//                 }

//                 for(auto valid_s : ret_s){
//                     ret.push_back(valid_s);
//                 }

//                 if(ret.size()){
//                     return ret;
//                 }

//                 for(auto & state : cur_level_states){
//                     for(int i = 0;i<state.size();i++){
//                         if(state[i]){
//                             continue;
//                         }
//                         state[i] = true;
//                         next_level_states.push_back(state);
//                         state[i] = false;
//                     }
//                 }

//                 cur_level_states = next_level_states;
//                 next_level_states.clear();
//             }
//         }
//     }
// };



// dfs ?
// 普通的dfs 复杂度肯定非常高

// 需要剪枝 见: https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/c-dfs-by-jerrysu/
// TODO

// class Solution {
// public:
//     bool is_valid(string & s, vector<bool> & deleted){
//         if(s.size() == 0) return true;

//         int left_cnt = 0;
//         int right_cnt = 0;
//         for(int i = 0;i<deleted.size();i++){
//             char c = s[i];
//             if(deleted[i]) continue;

//             if(c == '('){
//                 left_cnt++;
//             }
//             else if(c == ')'){
//                 right_cnt++;
//             }

//             if(right_cnt > left_cnt){
//                 return false;
//             }

//         }
//         if(right_cnt == left_cnt){
//             return true;
//         }
//         else return false;
//     }


//     // 可能会有重复
//     set<string> ret_s;
//     vector<string> ret;
//     int min_deleted_num = INT_MAX;



//     string format_s(string & s, vector<bool> & deleted){
//         string ret = "";
//         for(int i = 0;i<s.size();i++){
//             if(deleted[i]){
//                 continue;
//             }
//             ret += s[i];
//         }
//         return ret;
//     }

//     void dfs(string & s, ){

//     }

//     vector<string> removeInvalidParentheses(string s) {
//         vector<bool> deleted(s.size(), false);
//         cur_level_states.push_back(deleted);

        
//         while(true){
//             while(!cur_level_states.empty()){
//                 for(auto & state : cur_level_states){ 
//                     if(is_valid(s, state)){
//                         ret_s.insert(format_s(s, state));
//                     }
//                 }

//                 for(auto valid_s : ret_s){
//                     ret.push_back(valid_s);
//                 }

//                 if(ret.size()){
//                     return ret;
//                 }

//                 for(auto & state : cur_level_states){
//                     for(int i = 0;i<state.size();i++){
//                         if(state[i]){
//                             continue;
//                         }
//                         state[i] = true;
//                         next_level_states.push_back(state);
//                         state[i] = false;
//                     }
//                 }

//                 cur_level_states = next_level_states;
//                 next_level_states.clear();
//             }
//         }
//     }
// };


// https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--56/


