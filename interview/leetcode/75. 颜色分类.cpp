
// 这个解法不work

// [2,0,1]
// 输出
// [1,0,2]
// 预期结果
// [0,1,2]

// 0在中间咋办

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         if(nums.size() <= 1) return;
//         // 为啥这里能用快排分割
//         // 因为小于1一定是0
//         // 大于1一定是2
//         int pivot = 1;
//         int i = -1;
//         int j = nums.size();
//         while(i < j){
//             i++;
//             j--;
//             while(nums[i] < pivot && i < j) i++;
//             while(nums[j] > pivot) j--;
//             if(i < j){
//                 swap(nums[i],nums[j]);
//             }
//         }
//     }
// };

// https://leetcode-cn.com/problems/sort-colors/solution/yan-se-fen-lei-by-leetcode/299144
// https://leetcode-cn.com/problems/sort-colors/solution/kuai-su-pai-xu-partition-guo-cheng-she-ji-xun-huan/



// 这样的写法解决不了这种case

// [1,2,0]
// 输出
// [1,0,2]
// 预期结果
// [0,1,2]


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         if(nums.size() <= 1) return;
//         int left = 0;
//         int right = nums.size() - 1;
//         int idx = 0;
//         while(nums[left] == 0 && left < right) left++;
//         while(nums[right] == 2 && right) right--;
//         idx = left;
//         while(idx <= right){
//             if(nums[idx] == 0){
//                 swap(nums[idx], nums[left]);
//                 left++;
//             }
//             else if(nums[idx] == 2){
//                 swap(nums[idx], nums[right]);
//                 right--;
//             }
//             idx++;
//         }
//     }
// };


// 如果在else if(nums[idx] == 2)
// 也进行了idx++就会导致下面的bug
// 输入:
// [1,2,0]
// 输出
// [1,0,2]
// 预期结果
// [0,1,2]
// 原因是与有边界交换后,当前位置的新换来数并没有被检查过,如果换过来的数是0,就会导致这个0之后没有被换到左边界去

//AC
// 执行用时 :
// 4 ms
// , 在所有 C++ 提交中击败了
// 54.95%
// 的用户
// 内存消耗 :
// 8.5 MB
// , 在所有 C++ 提交中击败了
// 78.13%
// 的用户
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int left = -1;
        int right = nums.size();
        int idx = 0;
        while(left + 1 < right && nums[left+1] == 0) left++;
        while(right - 1 >= 0 && nums[right-1] == 2) right--;
        idx = left + 1;
        while(idx < right){
            if(nums[idx] == 0){
                swap(nums[idx], nums[left+1]);
                left++;
                idx++;
            }
            else if(nums[idx] == 2){
                swap(nums[idx], nums[right-1]);
                right--;
            }
            else
                idx++;
        }
    }
};

// 还可以优化,不要用swap,直接赋值会更快
