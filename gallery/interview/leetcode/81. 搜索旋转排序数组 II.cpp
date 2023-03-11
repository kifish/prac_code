/*
https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/

https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/zai-javazhong-ji-bai-liao-100de-yong-hu-by-reedfan/
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = int(nums.size() - 1);
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] == target){
                return true;
            }
            else{
                if(nums[mid] > nums[lo]){
                    if(nums[lo] <= target && target < nums[mid]){
                        hi = mid - 1;
                    }
                    else{
                        lo = mid + 1;
                    }
                }
                else if(nums[mid] < nums[lo]){
                    if(nums[mid] < target && target <= nums[hi]){
                        lo = mid + 1;
                    }
                    else{
                        hi = mid - 1;
                    }
                }
                else{ // 若nums[mid] == nums[lo], 则无法二分
                    lo++;
                }
            }
        }
        return false;
    }
};
