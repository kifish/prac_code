class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> non_zero_nums;
        for(auto &num : nums){
            if(num != 0){
                non_zero_nums.push_back(num);
            }
        }
        for(int i = 0;i<non_zero_nums.size();i++){
            nums[i] = non_zero_nums[i];
        }
        for(int i = non_zero_nums.size();i<nums.size();i++){
            nums[i] = 0;
        }
    }
};