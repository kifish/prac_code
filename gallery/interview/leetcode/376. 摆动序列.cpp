/*

https://leetcode-cn.com/problems/wiggle-subsequence/



https://leetcode-cn.com/problems/wiggle-subsequence/solution/dong-tai-gui-hua-tan-xin-suan-fa-1xing-d-ig8l/

DP (双DP平行数组)

https://leetcode-cn.com/problems/wiggle-subsequence/solution/bai-dong-xu-lie-by-leetcode-solution-yh2m/


贪心

https://leetcode-cn.com/problems/wiggle-subsequence/solution/tan-xin-suan-fa-bai-dong-xu-lie-by-jcmla-i31l/

https://leetcode-cn.com/problems/wiggle-subsequence/solution/tan-xin-suan-fa-bai-dong-xu-lie-by-jcmla-i31l/


执行结果：
通过
显示详情
执行用时：
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗：
6.9 MB
, 在所有 C++ 提交中击败了
97.00%
的用户

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        int up = 0;
        int max_len = 1;
        for(int idx = 1; idx < nums.size(); idx++){
            if(up == 0){
                if(nums[idx] != nums[idx-1]){
                    max_len++;
                    if(nums[idx] > nums[idx-1]) up = 1;
                    else up = -1;
                }
            }
            else{
                if(nums[idx] != nums[idx-1]){
                    int cur_direction = nums[idx] - nums[idx-1];
                    if(cur_direction * up < 0){
                        max_len++;
                        up *= -1;
                    }
                }
            }
        }
        return max_len;
    }
    
};





*/