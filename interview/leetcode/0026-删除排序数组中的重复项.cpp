class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {   if(nums.size() == 0) return 0;
        int idx = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] > nums[idx]){
                nums[++idx] = nums[i];
            }
        }
        return idx+1;
    }
};