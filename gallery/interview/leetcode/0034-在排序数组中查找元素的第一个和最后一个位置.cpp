
// AC
// class Solution {
// public:

//     int binary_search_left(vector<int>& nums,int target){
//         int lo = -1;
//         int hi = (int)nums.size() -1;
//         if(lo > hi) return -1;
//         while (lo + 1< hi)
//         {
//             int mid = (lo + hi) / 2;
//             if(nums[mid] < target){
//                 lo = mid; // 循环不变量，lo表示小于target的数中最大的数的index
//             }              //而hi的存在的意义只是为了帮助搜索lo
//             else hi = mid;
//         }
//         if(lo + 1 < nums.size() && nums[lo + 1] == target)
//             return (lo + 1);
//         else return -1;
//     }

//     int binary_search_right(vector<int>& nums,int target){
//         int lo = 0;
//         int hi = (int)nums.size();
//         if(nums.size() == 0) return -1;
//         if(lo > hi) return -1;
//         while (lo < hi)
//         {
//             int mid = (lo + hi) / 2;
//             if(nums[mid] > target){
//                 hi = mid;
//             }
//             else lo = mid + 1; // 循环不变量，hi表示大于target的数中最小的数的index
//             // 而lo的存在的意义只是为了帮助搜索hi
//         }
//         if(hi - 1 >= 0 && nums[hi - 1] == target)
//             return (hi - 1);
//         else return -1;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         int ret1,ret2;
//         ret1 = binary_search_left(nums,target);
//         if(ret1 == -1){
//             return {-1,-1};
//         }
//         else{
//             ret2 = binary_search_right(nums,target);
//             return {ret1,ret2};
//         }
//     }
// };


// 此题思路不难，但是二分的细节还是很麻烦的，需要想清楚才能ac

class Solution {
public:

    int binary_search_left(vector<int>& nums,int target){
        int lo = -1;
        int hi = (int)nums.size() -1;
        if(nums.size() == 0) return -1;
        while (lo + 1< hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] < target){ // 因为最终要求的是lo的值，先做这个判断再考虑如何使得lo逼近正确的值
                lo = mid; // 循环不变量，lo表示小于target的数中最大的数的index
            }              //而hi的存在的意义只是为了帮助搜索lo
            else hi = mid; // 如果mid -1 可能会错过正确的解
        }
        if(lo + 1 < nums.size() && nums[lo + 1] == target)
            return (lo + 1);
        else return -1;
    }

    int binary_search_right(vector<int>& nums,int target){
        int lo = 0;
        int hi = (int)nums.size();
        if(nums.size() == 0) return -1;
        while (lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] > target){ // 因为最终要求的是hi的值，先做这个判断再考虑如何使得hi逼近正确的值
                hi = mid;
            }
            else lo = mid; // 循环不变量，hi表示大于target的数中最小的数的index
            // 而lo的存在的意义只是为了帮助搜索hi
            // 如果mid -1 可能会错过正确的解
        }
        if(hi - 1 >= 0 && nums[hi - 1] == target)
            return (hi - 1);
        else return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int ret1,ret2;
        ret1 = binary_search_left(nums,target);
        if(ret1 == -1){
            return {-1,-1};
        }
        else{
            ret2 = binary_search_right(nums,target);
            return {ret1,ret2};
        }
    }
};