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


class Solution {
public:
    map<char,int> window;
    int lengthOfLongestSubstring(string s) {
        int right = 0;
        int left = 0;
        int ret = 0;
        while(right < s.size()){
            int right_c = s[right];
            window[right_c]++;
            right++;

            // cout<<"s : "<<s<<endl;
            // cout<<"right : "<<right<<" char: "<<s[right]<<endl;
            // cout<<"left : "<<left<<" char: "<<s[left]<<endl;


            // while 窗口需要缩小的条件
            while(window.count(right_c) && window[right_c] >= 2){ 
                int left_c = s[left]; 
                window[left_c]--;
                left++;

                if(left == right){ // right一开始就了1 因此无需考虑left超过right, 相等即可break
                    break;
                }
                // 实际上这个if判断也可以去掉
            }
            
            ret = max(ret, right - left);
        }
        return ret;
    }
};
