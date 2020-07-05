// WA

// class Solution {
// public:

//     int sign(int x){
//         if(x >= 0){
//             return 1;
//         }
//         else return -1;
//     }
//     void pretty_print(vector<int> & v){
//         for(auto val : v){
//             cout<<val<<"  ";
//         }
//         cout<<endl;
//     }

//     int maxProduct(vector<int>& nums) {
//         if(nums.size() == 0) return 0;

//         vector<int> not_neg_or_neg(nums.size());
//         vector<int> dp_abs(nums.size());
//         dp_abs[0] = abs(nums[0]);
//         not_neg_or_neg[0] = sign(nums[0]);

//         for(int i = 1;i<nums.size();i++){
//             dp_abs[i] = abs(nums[i]);
//             not_neg_or_neg[i] = sign(nums[i]);

//             if(nums[i] != 0){
//                 if(dp_abs[i-1] * abs(nums[i]) >= dp_abs[i-1] && dp_abs[i-1] != 0){
//                     dp_abs[i] = dp_abs[i-1] * abs(nums[i]);
//                     not_neg_or_neg[i] *= not_neg_or_neg[i-1];
//                 }                
//             }
//         }
//         int ret = INT_MIN;

//         pretty_print(not_neg_or_neg);
//         pretty_print(dp_abs);
//         for(int i = 0;i<nums.size();i++){
//             ret = max(ret, dp_abs[i] * not_neg_or_neg[i]);
//             ret = max(ret, nums[i]);
//         }

//         return ret;
//     }
// };



/*

https://leetcode-cn.com/problems/maximum-product-subarray/solution/cheng-ji-zui-da-zi-shu-zu-by-leetcode-solution/

注意, 这个是整数数组

这题转移的来源有3个。

执行用时：
12 ms
, 在所有 C++ 提交中击败了
37.17%
的用户
内存消耗：
11.7 MB
, 在所有 C++ 提交中击败了
6.25%
的用户


*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp_max(nums); // copy
        vector<int> dp_min(nums); // copy
        // cout<<dp_max[0]<<endl;

        for(int i = 1;i< nums.size(); i++){
            dp_max[i] = max(dp_max[i], dp_min[i-1] * nums[i]);
            dp_max[i] = max(dp_max[i], dp_max[i-1] * nums[i]);
            dp_min[i] = min(dp_min[i], dp_min[i-1] * nums[i]);
            dp_min[i] = min(dp_min[i], dp_max[i-1] * nums[i]);
        }

        int ret = nums[0];
        for(int i = 1;i<nums.size();i++){
            ret = max(ret, dp_max[i]);
        }

        return ret;
    }
};





