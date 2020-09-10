
class Solution {
public:
    pair<int,int> partition(vector<int> & nums, int lo, int hi){
        int cur_idx = lo;
        int less_idx = lo;
        int greater_idx = hi;
        int pivot = nums[lo];
        while(cur_idx <= greater_idx){
            if(nums[cur_idx] < pivot){
                swap(nums[cur_idx], nums[less_idx]);
                less_idx++;
                cur_idx++;
            }
            else if(nums[cur_idx] > pivot){
                swap(nums[greater_idx], nums[cur_idx]);
                greater_idx--;
            }
            else{
                cur_idx++;
            }
        }
        return make_pair(less_idx,greater_idx);
    }

    // https://en.cppreference.com/w/cpp/utility/pair/make_pair

    // 三路快排
    void quick_sort(vector<int> & nums, int lo, int hi){
        if(lo >= hi){
            return;
        }

        pair<int,int> pivot_pair = partition(nums, lo, hi);
        int less_idx = pivot_pair.first; // 开区间,因此要-1
        int greater_idx = pivot_pair.second; // 闭区间,因此要+1
        quick_sort(nums, lo, less_idx-1);
        quick_sort(nums, greater_idx+1, hi);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};


/*
执行用时：
80 ms
, 在所有 C++ 提交中击败了
14.87%
的用户
内存消耗：
15.6 MB
, 在所有 C++ 提交中击败了
93.82%
的用户

这题用hash比较快。

https://leetcode-cn.com/problems/sort-an-array/solution/pai-xu-shu-zu-by-leetcode-solution/
*/