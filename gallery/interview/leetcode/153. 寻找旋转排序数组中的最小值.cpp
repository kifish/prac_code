/*
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/

https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/xun-zhao-xuan-zhuan-pai-lie-shu-zu-zhong-de-zui-xi/

https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/xun-zhao-xuan-zhuan-pai-lie-shu-zu-zhong-de-zui-xi/401803
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = int(nums.size() - 1);
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] > nums[hi]){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return nums[hi];
    }
};
