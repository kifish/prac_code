
/*

你的算法时间复杂度必须是 O(log n) 级别。

https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/yi-wen-jie-jue-4-dao-sou-suo-xuan-zhuan-pai-xu-s-2/


https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1017/



示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1




*/





// 执行用时 :
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗 :
// 6.4 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int lo = 0;
        int hi = (int) nums.size() - 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            // cout<<"cur turn:"<<endl;
            // cout<<"lo :"<<lo<<endl;
            // cout<<"mid :"<<mid<<endl;
            // cout<<"hi :"<<hi<<endl;

            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[lo] <= nums[mid]){
                // 说明nums[lo-mid] 这个范围保证递增 ( 怎么推出来的？因为原数组是升序排列的, 如果lo-mid之间存在间断点是可以推出矛盾的,因此不存在间断点，因此递增)
                if(nums[lo] <= target && target < nums[mid]){ // =号其实可以特判拿来加速
                    // cout<<"change hi from "<<hi <<" to "<<mid-1<<endl;
                    hi = mid - 1;
                }
                else{
                    // 往右边找, 左边不可能有解了
                    // cout<<"change lo from "<<lo <<" to "<<mid+1<<endl;
                    lo = mid + 1;
                }
            }
            else{ // nums[lo] > nums[mid]
                // 说明不连续点已经在lo-mid之间出现过了
                // 也就说明nums[mid+1-hi] 
                
                if(nums[mid] < target && target <= nums[hi]){
                    // cout<<"change lo from "<<lo <<" to "<<mid+1<<endl;
                    lo = mid + 1;
                }
                else{
                    // cout<<"change hi from "<<hi <<" to "<<mid-1<<endl;
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};


