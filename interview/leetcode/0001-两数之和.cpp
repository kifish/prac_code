class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //vector<int> res;
        for(int i = 0;i< (int)nums.size()-1;i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    //res = vector<int>{i,j};
                    return {i,j};
                }
            }
        }
        return {0,0};
    }
};