/*
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

我们考虑数组中的最后一个元素 xx：在最小值右侧的元素，它们的值一定都小于等于 xx；而在最小值左侧的元素，它们的值一定都大于等于 xx。因此，我们可以根据这一条性质，通过二分查找的方法找出最小值。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-de-zui--16/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-de-zui--16/
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
            else if(nums[mid] < nums[hi]){
                hi = mid;
            }
            else{
                hi--;
            }
        }
        return nums[hi];
    }
};
