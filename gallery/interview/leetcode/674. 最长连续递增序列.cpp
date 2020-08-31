
/*

https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/

https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1035/




*/

// 执行用时：
// 20 ms
// , 在所有 C++ 提交中击败了
// 78.26%
// 的用户
// 内存消耗：
// 10.8 MB
// , 在所有 C++ 提交中击败了
// 6.67%
// 的用户

// class Solution {
// public:
//     int findLengthOfLCIS(vector<int>& nums) {
//         if(nums.size() == 0) return 0;

//         int ret = 1;
//         int cur = 1;
//         int pre_num = nums[0];
//         for(int i = 1;i<nums.size();i++){
//             if(nums[i] > pre_num){
//                 cur += 1;
//                 ret = max(ret, cur);
//                 pre_num = nums[i];
//             }
//             else{
//                 cur = 1;
//                 // ret = max(ret, cur);
//                 pre_num = nums[i];
//             }
//         }
//         return ret;
//     }
// };



// 执行用时：
// 20 ms
// , 在所有 C++ 提交中击败了
// 78.26%
// 的用户
// 内存消耗：
// 10.7 MB
// , 在所有 C++ 提交中击败了
// 6.67%
// 的用户


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int ret = 1;
        int cur = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] > nums[i-1]){
                cur += 1;
                ret = max(ret, cur);
            }
            else{
                cur = 1;
            }
        }
        return ret;
    }
};
