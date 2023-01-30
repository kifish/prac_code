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


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left_idx = 1;
        int right_idx = 1;
        for(; right_idx < nums.size(); right_idx++){
            if(nums[right_idx] == nums[right_idx - 1]){
                continue;
            }
            else{
                nums[left_idx++] = nums[right_idx];
            }
        }
        return left_idx;
    }
};
