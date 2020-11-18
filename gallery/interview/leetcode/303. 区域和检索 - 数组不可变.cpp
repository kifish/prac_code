class NumArray {
public:
    vector<int> pre_sum;
    vector<int> m_nums;
    NumArray(vector<int>& nums) {
        m_nums = nums;
        pre_sum = vector<int>(nums.size(), 0);
        for(int i = 0;i<nums.size(); i++){
            if(i == 0)
                pre_sum[i] = nums[i];
            else
                pre_sum[i] = pre_sum[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return pre_sum[j] - pre_sum[i] + m_nums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

