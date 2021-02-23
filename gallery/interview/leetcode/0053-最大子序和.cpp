/*

https://leetcode-cn.com/problems/maximum-subarray/

https://leetcode-cn.com/explore/interview/card/bytedance/246/dynamic-programming-or-greedy/1029/


*/


class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0,max_sum = nums[0];//size >= 1
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(sum + num < 0){ //这个判断比较关键
                sum = 0; 
                max_sum = max(max_sum, num); // 这里也有可能会更新; case: [-2,-1]
            }
            else{
                sum += num;
                max_sum = max(max_sum, sum);
            }
        }
        return max_sum;
    }
};



