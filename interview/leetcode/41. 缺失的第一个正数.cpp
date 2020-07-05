/*

https://leetcode-cn.com/problems/first-missing-positive/solution/que-shi-de-di-yi-ge-zheng-shu-by-leetcode-solution/

https://leetcode-cn.com/problems/first-missing-positive/solution/que-shi-de-di-yi-ge-zheng-shu-by-leetcode-solution/463006


*/


// 执行用时：
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 6.5 MB
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 原地hash
        int n = nums.size();
        if(n == 0) return 1;

        int max_num = n + 1; // 设为n+1即可
        // preprocess

        for(int i = 0;i<n;i++){
            if(nums[i] <= 0 ){
                nums[i] = max_num;
            }
        }

        // 1 会被hash到nums[0]

        for(int i = 0;i<n;i++){
            if(abs(nums[i]) >= max_num){ // 这里也需要加abs;不加abs就过滤不掉max_num变为负的情况,从而导致越界
                continue;
            }

            int new_idx = abs(nums[i]) - 1;
            if(nums[new_idx] > 0){
                nums[new_idx] *= -1;
            }
        }

        for(int possible_num = 1; possible_num <= n;possible_num++){
            if(nums[possible_num-1] < 0){ // 说明出现过了
                continue;
            }
            return possible_num;
        }

        return max_num; // 说明是n+1
    }
};

