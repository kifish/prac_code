// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/


// 滑动窗口

// WA 

// class Solution {
// public:
//     map<char,int> window;
//     int lengthOfLongestSubstring(string s) {
//         int right = 0;
//         int left = 0;
//         int ret = 0;
//         while(right < s.size()){
//             int right_c = s[right];
//             window[right_c]++;
//             right++;

//             cout<<"s : "<<s<<endl;
//             cout<<"right : "<<right<<" char: "<<s[right]<<endl;
//             cout<<"left : "<<left<<" char: "<<s[left]<<endl;


//             int left_c = s[left]; 
//             window[left_c]++;
//             while(window.count(left_c) && window[left_c] >= 2){ // while 窗口需要缩小的条件
//                 left++;
//                 if(left == right){
//                     break;
//                 }
//                 window[left_c]--;
//                 left_c = s[left];
//             }
            
//             ret = max(ret, right - left);
//         }
//         return ret;
//     }
// };


// 执行用时 :
// 100 ms
// , 在所有 C++ 提交中击败了
// 14.43%
// 的用户
// 内存消耗 :
// 8.6 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

// https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1012/

// class Solution {
// public:
//     map<char,int> window;
//     int lengthOfLongestSubstring(string s) {
//         int right = 0;
//         int left = 0;
//         int ret = 0;
//         while(right < s.size()){
//             int right_c = s[right];
//             window[right_c]++;
//             right++;

//             // cout<<"s : "<<s<<endl;
//             // cout<<"right : "<<right<<" char: "<<s[right]<<endl;
//             // cout<<"left : "<<left<<" char: "<<s[left]<<endl;


//             // while 窗口需要缩小的条件
//             while(window.count(right_c) && window[right_c] >= 2){ 
//                 int left_c = s[left]; 
//                 window[left_c]--;
//                 left++;

//                 if(left == right){ // right一开始就为1了;因此无需考虑left超过right, 相等即可break
//                     break;
//                 }
//                 // 实际上这个if判断也可以去掉
//             }
            
//             ret = max(ret, right - left);
//         }
//         return ret;
//     }
// };





/*
因为是字串而不是子序列, 因此多半是用滑动窗口来解决

2个while 解决问题 相当于2重循环


*/

// WA
// class Solution {
// public:
//     // https://stackoverflow.com/questions/26281979/c-loop-through-map
    
//     void print_window(map<char,int> window_counter){
//         cout<<"----------"<<endl;
//         for(auto it : window_counter){
//             cout<<it.first<<" "<<it.second<<endl;
//         }
//         cout<<"----------"<<endl;
//     }
    
    
//     int lengthOfLongestSubstring(string s) {
//         int right = 0;
//         int left = 0;
//         map<char,int> window_counter;
//         int max_len = 0;
//         while(right < s.size()){
//             char c = s[right++];
//             window_counter[c]++;
//             cout<<"right :"<<right<<endl;
            
//             print_window(window_counter);
//             char left_c = s[left];
//             while(window_counter.count(left_c) and window_counter[left_c] > 1){ // 不能判断left_c 而是应该判断right_c; case: "abcabcbb"

//                 left++;
//                 cout<<"left :"<<left<<endl;
//                 window_counter[left_c]--;
//                 left_c = s[left];
//             }
//             print_window(window_counter);
//             max_len = max(max_len, right - left); // 不用+1 因为right已经加过一次, 是开区间
//         }
//         return max_len;
//     }
// };





/*
因为是字串而不是子序列, 因此多半是用滑动窗口来解决

2个while 解决问题 相当于2重循环

执行用时：
36 ms
, 在所有 C++ 提交中击败了
53.74%
的用户
内存消耗：
8.4 MB
, 在所有 C++ 提交中击败了
60.12%
的用户


*/

class Solution {
public:
    // https://stackoverflow.com/questions/26281979/c-loop-through-map
    
    void print_window(map<char,int> window_counter){
        cout<<"----------"<<endl;
        for(auto it : window_counter){
            cout<<it.first<<" "<<it.second<<endl;
        }
        cout<<"----------"<<endl;
    }
    
    
    int lengthOfLongestSubstring(string s) {
        int right = 0;
        int left = 0;
        map<char,int> window_counter;
        int max_len = 0;
        while(right < s.size()){
            char c = s[right++];
            window_counter[c]++;
            // cout<<"right :"<<right<<endl;
            
            // print_window(window_counter);
            while(window_counter.count(c) and window_counter[c] > 1){
                char left_c = s[left];
                left++;
                window_counter[left_c]--;
                // cout<<"left :"<<left<<endl;
            }
            // print_window(window_counter);
            max_len = max(max_len, right - left); // 不用+1 因为right已经加过一次, 是开区间
        }
        return max_len;
    }
};


