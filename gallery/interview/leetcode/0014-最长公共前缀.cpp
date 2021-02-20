/*

纵向扫描即可。

这题还是很适合面试的。

*/


// https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1014/
// 归并也可以


// class Solution {
// public:
//     bool check(vector<string>& strs,int k){
//         char c = strs[0][k];
//         for(int i = 0;i<strs.size();i++){
//             if(strs[i][k] != c){
//                 return false;
//             }
//         }
//         return true;
//     }
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.size() == 0) return "";
//         int len = 0;
//         int min_len = INT_MAX;
//         for(int i = 0;i<strs.size();i++){
//             if(strs[i].size() < min_len){
//                 min_len = strs[i].size();
//             }
//         }
//         for(;len<=min_len;len++){
//             if(!check(strs,len)) break;
//         }
//         if(len == 0) return "";
//         else return strs[0].substr(0,len);
//     }
// };




/*

执行结果：
通过
显示详情
执行用时：
12 ms
, 在所有 C++ 提交中击败了
10.72%
的用户
内存消耗：
14.9 MB
, 在所有 C++ 提交中击败了
5.00%
的用户

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        int idx = 0;
        for( ; ;idx++){
            char c = strs[0][idx];
            bool final = false;
            for(auto s : strs){
                if(idx >= s.size() or s[idx] != c){
                    final = true;
                    break;
                }
            }

            if(final){
                break;
            }
        }

        return strs[0].substr(0, idx);
    }
};

