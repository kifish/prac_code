

// 这种解法已经离最优解法很接近了,但是无法解决连续的相等的数的情况
// class Solution {
// public:
//     int find_from_left(vector<int>& nums){
//         int ret = -1;
//         for(int i = 1;i<nums.size();i++){
//             if(nums[i] < nums[i-1]){
//                 ret = i-1;
//                 break;
//             }
//         }
//         return ret;
//     }

//     int find_from_right(vector<int>& nums){
//         int ret = -1;
//         for(int i = nums.size() - 2;i>=0;i--){
//             if(nums[i] > nums[i+1]){
//                 ret = i + 1;
//                 break;
//             }
//         }
//         return ret;
//     }
//     int findUnsortedSubarray(vector<int>& nums) {
//         if(nums.size() == 0 || nums.size() == 1){
//             return 0;
//         }
//         int left = find_from_left(nums);
//         int right = find_from_right(nums);
//         if(left == -1) return 0;
//         else return right - left + 1;
//     }
// };



// 这个思路还是不对。
// [1,3,5,4,2]
// 输出
// 3
// 预期结果
// 4

// class Solution {
// public:
//     int find_from_left(vector<int>& nums){
//         int ret = -1;
//         for(int i = 1;i<nums.size();i++){
//             if(nums[i] < nums[i-1]){
//                 ret = i-1;
//                 break;
//             }
//         }
//         return ret;
//     }

//     int find_from_right(vector<int>& nums){
//         int ret = -1;
//         for(int i = nums.size() - 2;i>=0;i--){
//             if(nums[i] > nums[i+1]){
//                 ret = i + 1;
//                 break;
//             }
//         }
//         return ret;
//     }

//     int findUnsortedSubarray(vector<int>& nums) {
//         if(nums.size() == 0 || nums.size() == 1){
//             return 0;
//         }

//         int left = find_from_left(nums);
//         int right = find_from_right(nums);
//         if(left == -1) return 0;

//         int left_value = nums[left + 1];
//         int new_left = 0;
//         for(;new_left<left + 1;new_left++){
//             if(nums[new_left] > left_value){
//                 break;
//             }
//         }
//         int new_right = nums.size() - 1;
//         int right_value = nums[right -1];
//         for(;new_right > right-1;new_right--){
//             if(nums[new_right] < right_value){
//                 break;
//             }
//         }

//         return new_right - new_left + 1;
//     }
// };



// https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/chao-hao-li-jie-de-javadai-ma-shi-jian-ji-bai-100t/
// 执行结果：
// 通过
// 显示详情
// 执行用时 :
// 56 ms
// , 在所有 C++ 提交中击败了
// 66.80%
// 的用户
// 内存消耗 :
// 25.1 MB
// , 在所有 C++ 提交中击败了
// 6.67%
// 的用户

class Solution {
public:
    int find_from_left(vector<int>& nums){
        int ret = -1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                ret = i-1;
                break;
            }
        }
        return ret;
    }

    int find_from_right(vector<int>& nums){
        int ret = -1;
        for(int i = nums.size() - 2;i>=0;i--){
            if(nums[i] > nums[i+1]){
                ret = i + 1;
                break;
            }
        }
        return ret;
    }

    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return 0;
        }

        int left = find_from_left(nums);
        int right = find_from_right(nums);
        if(left == -1) return 0;

        int min_value_in_unsorted_array = nums[left];
        int max_value_in_unsorted_array = nums[right];

        for(int i = left;i<=right;i++){
            min_value_in_unsorted_array = min(min_value_in_unsorted_array,nums[i]);
            max_value_in_unsorted_array = max(max_value_in_unsorted_array,nums[i]);
        }

        int new_left = 0;
        for(;new_left<left;new_left++){
            if(nums[new_left] > min_value_in_unsorted_array){
                break;
            }
        }
        int new_right = nums.size() - 1;
        for(;new_right > right;new_right--){
            if(nums[new_right] < max_value_in_unsorted_array){
                break;
            }
        }

        return new_right - new_left + 1;
    }
};