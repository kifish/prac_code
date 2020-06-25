class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0,max_sum = nums[0];//size >= 1
        for(int i =0;i<nums.size();i++){
            int num = nums[i];
            if(sum + num < 0){ //����жϱȽϹؼ�
                sum = 0;
                max_sum = max(max_sum, num);
            }
            else{
                sum += num;
                max_sum = max(max_sum,sum);
            }
        }
        return max_sum;
    }
};