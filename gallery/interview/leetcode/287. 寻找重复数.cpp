
// 执行用时 :
// 12 ms
// , 在所有 C++ 提交中击败了
// 93.77%
// 的用户
// 内存消耗 :
// 11 MB
// , 在所有 C++ 提交中击败了
// 13.33%
// 的用户

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); i++){
            int new_idx = abs(nums[i]);
            if(nums[new_idx] < 0){
                ret = new_idx;
                break;
            }
            else{
                nums[new_idx] = -1 * nums[new_idx]; 
            } 
        }
        return ret;
    }
};