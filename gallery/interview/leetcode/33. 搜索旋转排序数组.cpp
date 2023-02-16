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

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
        
//         int lo = 0;
//         int hi = (int) nums.size() - 1;
//         while(lo <= hi){
//             int mid = (lo + hi) / 2;
//             // cout<<"cur turn:"<<endl;
//             // cout<<"lo :"<<lo<<endl;
//             // cout<<"mid :"<<mid<<endl;
//             // cout<<"hi :"<<hi<<endl;

//             if(nums[mid] == target){
//                 return mid;
//             }
            
//             if(nums[lo] <= nums[mid]){
//                 // 说明nums[lo-mid] 这个范围保证递增 ( 怎么推出来的？因为原数组是升序排列的, 如果lo-mid之间存在间断点是可以推出矛盾的,因此不存在间断点，因此递增)
//                 if(nums[lo] <= target && target < nums[mid]){ // =号其实可以特判拿来加速
//                     // cout<<"change hi from "<<hi <<" to "<<mid-1<<endl;
//                     hi = mid - 1;
//                 }
//                 else{
//                     // 往右边找, 左边不可能有解了
//                     // cout<<"change lo from "<<lo <<" to "<<mid+1<<endl;
//                     lo = mid + 1;
//                 }
//             }
//             else{ // nums[lo] > nums[mid]
//                 // 说明不连续点已经在lo-mid之间出现过了
//                 // 也就说明nums[mid-hi] 这个范围保证递增

//                 if(nums[mid] < target && target <= nums[hi]){
//                     // cout<<"change lo from "<<lo <<" to "<<mid+1<<endl;
//                     lo = mid + 1;
//                 }
//                 else{
//                     // cout<<"change hi from "<<hi <<" to "<<mid-1<<endl;
//                     hi = mid - 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };


/*

执行结果：
通过
显示详情
执行用时：
4 ms
, 在所有 C++ 提交中击败了
85.27%
的用户
内存消耗：
10.8 MB
, 在所有 C++ 提交中击败了
64.97%
的用户
炫耀一下:

写题解，分享我的解题思路
提交时间	提交结果	运行时间	内存消耗	语言
几秒前	通过	4 ms	10.8 MB	C++
8 个月前	通过	0 ms	6.3 MB	C++

class Solution {
public:
    int search(vector<int>& nums, int target) {
    if(nums.size() == 0) return -1;
    // 2,3,4,5,6,1
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while(lo <= hi){
        // cout<<"------------"<<endl;
        // cout<<"hi : "<<hi<<endl;
        // cout<<"lo : "<<lo<<endl;
        mid = lo + (hi - lo) / 2; 
        // cout<<"mid : "<<mid<<endl;
        

        if(nums[mid] == target){
            return mid;
        }

        else{

            
            // 画图来理解
            
            // 按包含断点和不包含断点来分类, 是没法继续二分的, 因为有可能搜寻范围漏掉了
            // 不需要考虑lo hi之外的范围, 不要去考虑间断点

            if(nums[lo] <= nums[mid]){ // nums[lo-mid] 递增
                // cout<<"lo num: "<<nums[lo]<<endl;
                // cout<<"mid num: "<<nums[mid]<<endl;
                // cout<<"hi num: "<<nums[hi]<<endl;
                if(nums[lo] <= target && target < nums[mid]){
                    hi = mid - 1;
                }

                else{ // lo 左边的区域不用考虑
                    lo = mid + 1;
                }

                // else{ // target < nums[lo] ? 要么答案是-1 要么是mid右边, 因此这种情况不需要考虑了
                //     lo = mid + 1;
                // }

            
            }
            else{ // nums[mid-hi] 递增

                if(nums[mid] < target && target <= nums[hi]){
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
        }
    }

    return -1;
    }
};
*/


/*
执行结果：
通过
显示详情
执行用时：
4 ms
, 在所有 C++ 提交中击败了
85.27%
的用户
内存消耗：
10.6 MB
, 在所有 C++ 提交中击败了
98.03%
的用户
炫耀一下:

写题解，分享我的解题思路
提交时间	提交结果	运行时间	内存消耗	语言
几秒前	通过	4 ms	10.6 MB	C++
12 分钟前	通过	4 ms	10.8 MB	C++
8 个月前	通过	0 ms	6.3 MB	C++



class Solution {
public:
    int search(vector<int>& nums, int target) {
    if(nums.size() == 0) return -1;
    // 2,3,4,5,6,1
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while(lo <= hi){
        // cout<<"------------"<<endl;
        // cout<<"hi : "<<hi<<endl;
        // cout<<"lo : "<<lo<<endl;
        mid = lo + (hi - lo) / 2; 
        // cout<<"mid : "<<mid<<endl;
        

        if(nums[mid] == target){
            return mid;
        }

        else{


            // 按包含断点和不包含断点来分类, 是没法继续二分的, 因为有可能搜寻范围漏掉了
            // 不需要考虑lo hi之外的范围, 不要去考虑间断点

            if(nums[lo] < nums[hi]){
                if(nums[mid] > target){
                    hi = mid -1;
                }
                else{
                    lo = mid + 1;
                }
            }

            else{
                if(nums[lo] <= nums[mid]){ // nums[lo-mid] 递增
                    // cout<<"lo num: "<<nums[lo]<<endl;
                    // cout<<"mid num: "<<nums[mid]<<endl;
                    // cout<<"hi num: "<<nums[hi]<<endl;
                    if(nums[lo] <= target && target < nums[mid]){
                        hi = mid - 1;
                    }

                    else{ // lo 左边的区域不用考虑
                        lo = mid + 1;
                    }

                    // else{ // target < nums[lo] ? 要么答案是-1 要么是mid右边, 因此这种情况不需要考虑了
                    //     lo = mid + 1;
                    // }

                
                }
                else{ // nums[mid-hi] 递增

                    if(nums[mid] < target && target <= nums[hi]){
                        lo = mid + 1;
                    }
                    else{
                        hi = mid - 1;
                    }
                }
            }
        }
    }

    return -1;
    }
};

*/

/*
分情况讨论:
情况1
        r
    m
l

情况2
    m
l       r

情况3
l       r
    m

情况4, 不可能出现
l   
    m
        r
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = int(nums.size() - 1);
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else{
                if(nums[mid] >= nums[lo]){ // 情况1和2
                    if(nums[lo] <= target && target < nums[mid]){
                        hi = mid - 1;
                    }
                    else{
                        lo = mid + 1;
                    }
                }
                else{ // 情况3
                    if(nums[mid] < target && target <= nums[hi]){
                        lo = mid + 1;
                    }
                    else{
                        hi = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
