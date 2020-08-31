// class Solution {
// public:
//     // 初级想法: hash
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         vector<int> hash(nums.size() + 1, 0);
//         for(auto &num : nums){
//             hash[num] = 1;
//         }
//         vector<int> ret;
//         for(int i = 1;i <= nums.size();i++){
//             if(hash[i] == 0){
//                 ret.push_back(i);
//             }
//         }
//         return ret;
//     }
// };


// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/zhao-dao-suo-you-shu-zu-zhong-xiao-shi-de-shu-zi-2/
// class Solution {
// public:
//     // 进阶想法: hash
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         for(int i = 0;i<nums.size();i++){
//             int hash_index = abs(nums[i]) - 1;
//             if(nums[hash_index] > 0){ //假设某个数字出现了2次，但只会进入这个分支一次
//                 nums[hash_index] *= -1; 
//             }   
//         }

//         vector<int> ret;
//         for(int i = 0;i < nums.size();i++){
//             if(nums[i] > 0){
//                 ret.push_back(i+1);
//             }
//         }
//         return ret;
//     }
// };


// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/cyuan-shu-zu-cao-zuo-by-haydenmiao/


// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/comments/9743


class Solution {
public:
    // 进阶想法: hash
    // 核心想法就是说数组的hash index处的最终的值只会与某一特定的值有关
    // 例如index为2的地方, 只会与值3有关 
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            int hash_index = abs(nums[i]) - 1;
            nums[hash_index] = -1 * abs(nums[hash_index]); //即使某个数字出现了2次,这个操作在同一个hash index处执行2次，也仍然为负数,因为多了一个abs
        }

        vector<int> ret;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] > 0){
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};
