// TLE
// [25000,24999,24998,24997,24996,24995,24994,......]
// 这种case就会超时

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         if(nums.size() == 0 || nums.size() == 1) return true;

//         vector<bool> dp (nums.size(), false);
//         dp[0] = true;
//         for(int i = 0;i<nums.size();i++){
//             if(dp[i]){
//                 for(int j = 1;j<= nums[i];j++){
//                     if(i + j <= nums.size() - 1){
//                         dp[i+j] = true;
//                         if(dp[nums.size() - 1]) return true;
//                     }
//                 }
//             }
//             else break;
//         }
//         return dp[nums.size() - 1];
//     }
// };

// https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode-solution/351864

// 优化
// 但是如果都是[1,1,1,1,.....]
// TLE
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         if(nums.size() == 0 || nums.size() == 1) return true;

//         vector<bool> dp (nums.size(), false); //can be reached
//         dp[0] = true;
//         for(int i = 1;i<nums.size();i++){
//             for(int j = 0;j< i;j++){
//                 if(dp[j] && nums[j] + j >= i){
//                     dp[i] = true;
//                     break; // 优化
//                 }
//             }
//         }
//         return dp[nums.size() - 1];
//     }
// };


// 执行用时 :
// 20 ms
// , 在所有 C++ 提交中击败了
// 35.97%
// 的用户
// 内存消耗 :
// 12.9 MB
// , 在所有 C++ 提交中击败了
// 8.70%
// 的用户



// 贪心

// 执行用时 :
// 24 ms
// , 在所有 C++ 提交中击败了
// 25.05%
// 的用户
// 内存消耗 :
// 12.7 MB
// , 在所有 C++ 提交中击败了
// 8.70%
// 的用户


// 执行用时 :
// 20 ms
// , 在所有 C++ 提交中击败了
// 35.97%
// 的用户
// 内存消耗 :
// 13.1 MB
// , 在所有 C++ 提交中击败了
// 8.70%
// 的用户

// 这题执行时间比较随机



class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return true;

        int right = 0;
        for(int i = 0;i<nums.size();i++){
            if(i > right) {
                break;
            }
            else{
                right = max(right, nums[i] + i);
                if(right >= nums.size() - 1){
                    break;
                }
            }
        }

        if(right >= nums.size() - 1) {
            return true;
        }
        return false;
    }
};

