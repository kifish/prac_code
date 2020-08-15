class Solution {
public:
    map<int,int> rob_left;
    // map<int,int> rob_right;
    // int rob_left(vector<int>& nums,int l){
    //     if(rob_left.count(l)){
    //         return rob_left[l];
    //     }
    //     if(l ==  0) {
    //         rob_left[0] = nums[l];
    //         return nums[l];
    //     } 
    //     int v = nums[l];
    //     int ll_all = 0;
    //     if(l - 2 >= 0){
    //         ll_all += rob_left(nums, l - 2);
    //     }
    //     int l_all = 0;
    //     if(l - 1 >= 0){
    //         l_all += rob_left(nums,l - 1);
    //     }
    //     int ret = 0;
    //     if(l_all > ll_all + v){
    //         ret = l_all;
    //     }
    //     else ret = ll_all + v;
    //     rob_left[l] = ret;
    //     return ret;
    // }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int i = 0;i<nums.size();++i){
            if(i == 0){
                rob_left[i] = nums[i];
            }
            else if(i == 1){
                rob_left[i] = max(nums[0],nums[1]);
            }
            else{
                if(rob_left[i-2] + nums[i] > rob_left[i-1]){
                    rob_left[i] = rob_left[i-2] + nums[i];
                }
                else rob_left[i] = rob_left[i-1];
            }
        }
        return rob_left[nums.size() - 1];
    } 
};