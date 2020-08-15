

/*

https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode/


必须原地修改，只允许使用额外常数空间。


2次贪心解决问题

执行用时：
8 ms
, 在所有 C++ 提交中击败了
40.99%
的用户
内存消耗：
12.1 MB
, 在所有 C++ 提交中击败了
6.67%
的用户


*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int the_index = (int) nums.size() - 2;
        // 第一次贪心:
        // 如果从后往前遍历是递增的,那么这段区间不能变的更大, 找到下降点然后跳出循环
        for(;the_index >= 0;the_index--){
            if(nums[the_index] < nums[the_index + 1])
                break;
        }

        if(the_index >= 0){ // 说明找到了下降点
            // 第二次贪心:
            // 找到刚刚好比nums[the_index]大的数
            // 从而保证比原来的数大,且是能组合的数里面比原来的数大的最小的那个
            int the_other_index = the_index + 1;
            for(; the_other_index < nums.size(); the_other_index++){
                if(nums[the_other_index] <= nums[the_index]){ // 注意这里需要等于号
                    break;
                }
            }
            the_other_index -= 1; // 即使超出nums的范围这一公式仍然成立
            swap(nums[the_index], nums[the_other_index]);

            // cout<<"the_index : "<<the_index<<endl;
            // cout<<"the_other_index : "<<the_other_index<<endl;

            // 逆序一下, 从而使得nums[the_index+1:] 是最小的数字串组合
            reverse(nums.begin() + the_index + 1, nums.end());

        }


        else{ // 无下降点
            reverse(nums.begin(), nums.end());
        }
    }
};