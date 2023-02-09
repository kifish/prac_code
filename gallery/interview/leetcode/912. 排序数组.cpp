// https://leetcode-cn.com/problems/sort-an-array/
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

class Solution {
public:
    void merge_sort(vector<int> & nums, int lo, int hi){
        if(lo >= hi) return;
        int mid = (lo + hi) / 2;
        merge_sort(nums, lo, mid);
        merge_sort(nums, mid + 1, hi);
        vector<int> buf;
        buf.resize(hi - lo + 1);
        int idx = 0;
        int i = lo;
        int j = mid + 1;
        while(i <= mid && j <= hi){
            if(nums[i] <= nums[j]){
                buf[idx++] = nums[i++];
            }
            else{
                buf[idx++] = nums[j++];
            }
        }
        while(i <= mid){
            buf[idx++] = nums[i++];
        }
        while(j <= hi){
            buf[idx++] = nums[j++];
        }
        for(int i = lo; i <= hi; i++){
            nums[i] = buf[i - lo];
        }
    }

    void merge_sort(vector<int> & nums){
        merge_sort(nums, 0, int(nums.size() - 1));
    }

    /* 
    // 在数组中有很多重复元素的情况下，时间复杂度会退化到O(N^2)
    int partition(vector<int> & nums, int lo, int hi){
        if(lo >= hi) return lo;
        swap(nums[lo], nums[rand() % (hi - lo + 1) + lo]);
        int i = lo;
        int j = hi + 1;
        int pivot_idx = lo;
        while(i < hi && j > lo && i < j){
            i++;
            j--;
            while(nums[i] < nums[pivot_idx] && i < hi) i++;
            while(nums[j] > nums[pivot_idx] && j > lo) j--;
            if(i < j){
                swap(nums[i], nums[j]);
            }
            else{
                break;
            }
        }
        swap(nums[pivot_idx], nums[j]);
        pivot_idx = j;
        return pivot_idx;
    }
    */

    int partition(vector<int> & nums, int lo, int hi){
        if(lo >= hi) return lo;
        swap(nums[lo], nums[rand() % (hi - lo + 1) + lo]);
        int i = lo;
        int j = hi + 1;
        int pivot_idx = lo;
        while(i < j){
            i++;
            j--;
            while(nums[i] < nums[pivot_idx] && i <= j && i < hi) i++; // WA: i < j; WA: i <= j
            while(nums[j] > nums[pivot_idx] && i <= j) j--; // WA: i < j
            if(i < j){
                swap(nums[i], nums[j]);
            }
            else{
                break;
            }
        }
        swap(nums[pivot_idx], nums[j]);
        pivot_idx = j;
        return pivot_idx;
    }

    /*
    // WA
    int partition(vector<int> & nums, int lo, int hi){
        if(lo >= hi) return lo;
        swap(nums[lo], nums[rand() % (hi - lo + 1) + lo]);
        int i = lo; // WA: i = lo + 1
        int j = hi;
        int pivot_idx = lo;
        while(i < j){
            // WA: i++, j--
            while(nums[i] < nums[pivot_idx] && i <= j) i++; // WA: i < j
            while(nums[j] > nums[pivot_idx] && i <= j) j--; // WA: i < j
            if(i < j){
                swap(nums[i], nums[j]);
                // WA: i++, j--
            }
            else{
                break;
            }
        }
        swap(nums[pivot_idx], nums[j]);
        pivot_idx = j;
        return pivot_idx;
    }
    */

    void quick_sort(vector<int> & nums, int lo, int hi){
        if(lo >= hi) return;
        int pivot_idx = partition(nums, lo, hi);
        quick_sort(nums, lo, pivot_idx - 1);
        quick_sort(nums, pivot_idx + 1, hi);
    }
    

    /*
    pair<int, int> partition(vector<int> & nums, int lo, int hi){
        if(lo >= hi) return make_pair(lo, hi);
        int lt = lo; // less_than_the_pivot_num_idx (- 1)
        int gt = hi; // greater_than_the_pivot_num_idx (+ 1)
        int i = lo + 1; // or i = lo
        swap(nums[lo], nums[rand() % (hi - lo + 1) + lo]);
        int pivot = nums[lo];
        while(i <= gt){
            if(nums[i] < pivot){
                swap(nums[i], nums[lt]);
                i++;
                lt++;
            }
            else if(nums[i] > pivot){
                swap(nums[i], nums[gt]);
                gt--;
            }
            else{
                i++;
            }
        }
        return make_pair(lt, gt);
    }

    void quick_sort_3_way(vector<int> & nums, int lo, int hi){
        if(lo >= hi) return;
        pair<int, int> pivot_idxs_pair = partition(nums, lo, hi);
        int lt = pivot_idxs_pair.first;
        int gt = pivot_idxs_pair.second;
        quick_sort_3_way(nums, lo, lt-1);
        quick_sort_3_way(nums, gt + 1, hi);
    }
    */

    void quick_sort_3_way(vector<int> & nums, int lo, int hi){
        if(lo >= hi) return;
        int lt = lo;
        int gt = hi;
        int i = lo + 1;
        swap(nums[lo], nums[rand() % (hi - lo + 1) + lo]);
        int pivot = nums[lo];
        while(i <= gt){
            if(nums[i] < pivot){
                swap(nums[i], nums[lt]);
                i++;
                lt++;
            }
            else if(nums[i] > pivot){
                swap(nums[i], nums[gt]);
                gt--;
            }
            else{
                i++;
            }
        }
        quick_sort_3_way(nums, lo, lt - 1);
        quick_sort_3_way(nums, gt + 1, hi);
    }

    void quick_sort(vector<int> & nums){
        // quick_sort(nums, 0, int(nums.size() - 1));
        quick_sort_3_way(nums, 0, int(nums.size() - 1));
    }

    vector<int> sortArray(vector<int>& nums) {
        // merge_sort(nums);
        quick_sort(nums);
        return nums;
    }
};
