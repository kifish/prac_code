/*

https://leetcode-cn.com/problems/132-pattern/



栈

https://leetcode-cn.com/problems/132-pattern/solution/cji-hu-shuang-bai-de-dan-diao-zhan-by-ff-40u2/



class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int second = INT_MIN;

        stack<int> s; // 单调递减, 栈顶最小, 存的是比 second 大的元素
        int n = nums.size();
        for (int i = n-1; i >=0; --i)
        {
             
            if (nums[i] >= second) // 栈可能要更新; 如果是等于, 貌似可以跳过
            {
                // 如果发现大于最大栈，那么要去更新栈和second的数值（second变为更大的数字）
                while (!s.empty() && nums[s.top()] < nums[i])
                {
                    second = nums[s.top()];
                    s.pop();
                }

                s.push(i);
            }
            else  // 找到比second小的数字，那么满足条件
            {
                return true;
            }
        }

        return false;
    }
};

作者：ffreturn
链接：https://leetcode-cn.com/problems/132-pattern/solution/cji-hu-shuang-bai-de-dan-diao-zhan-by-ff-40u2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/